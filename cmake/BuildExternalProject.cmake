# These functions is used to force a build on a dependant project at cmake configuration phase. Original code taken from
# https://stackoverflow.com/a/23570741

function(build_external_cmake_project target source_archive)
    cmake_parse_arguments(PARSE_ARGV 2 ext "" "" "DEPENDS")

    set(cpath "")
    foreach(dependency ${ext_DEPENDS})
        get_target_property(dirs "${dependency}" INTERFACE_INCLUDE_DIRECTORIES)
        list(APPEND cpath "${dirs}")
    endforeach()
    list(JOIN cpath ":" cpath_string)

    set(library_path "")
    foreach(dependency ${ext_DEPENDS})
        get_target_property(lib_location "${dependency}" IMPORTED_LOCATION)
        get_filename_component(lib_dirname "${lib_location}" DIRECTORY)
        list(APPEND library_path "${lib_dirname}")
    endforeach()
    list(JOIN library_path ":" library_path_string)

    set(ext_dir "${CMAKE_BINARY_DIR}/${target}")
    set(ext_src_dir "${ext_dir}/src")
    set(ext_install_dir "${ext_dir}/install")
    set("${target}_install_dir"
        "${ext_install_dir}"
        PARENT_SCOPE
    )

    # generate a temporary cmake project
    set(CMAKE_LIST_CONTENT
        "
        cmake_minimum_required(VERSION 2.8)

        project(\"${target}\")

        include(ExternalProject)

        ExternalProject_Add(
            \"${target}\"
            URL \"${source_archive}\"
            SOURCE_DIR \"${ext_src_dir}\"
            CONFIGURE_COMMAND \"${CMAKE_COMMAND}\" -DCMAKE_INSTALL_PREFIX=${ext_install_dir} -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -S <SOURCE_DIR> -B <BINARY_DIR>
            BUILD_COMMAND make -C <BINARY_DIR> -j
        )
        add_custom_target(\"trigger_${target}\")
        add_dependencies(\"trigger_${target}\" \"${target}\")
    "
    )
    set(BASH_SCRIPT_CONTENT
        "
        export CPATH=\"${cpath_string}:\${CPATH}\"
        export LIBRARY_PATH=\"${library_path_string}:\${LIBRARY_PATH}\"
		${CMAKE_COMMAND} -S . -B build && \
        ${CMAKE_COMMAND} --build build
        "
    )

    file(WRITE "${ext_dir}/CMakeLists.txt" "${CMAKE_LIST_CONTENT}")
    file(WRITE "${ext_dir}/run_cmake.sh" "${BASH_SCRIPT_CONTENT}")

    execute_process(COMMAND bash run_cmake.sh WORKING_DIRECTORY "${ext_dir}")

    set(CMAKE_PREFIX_PATH
        ${CMAKE_PREFIX_PATH} "${ext_install_dir}"
        PARENT_SCOPE
    )
endfunction()

