#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd)"

lattice_edge_particles=(4, 8, 12, 16)
time_length=(50)
time_step=(0.002)
scattering_time=(0, 1, 2, 3, 4, 5)
open_nnl=(0, 1)

parent_directory="output"

for i in "${lattice_edge_particles[@]}"; do
	for j in "${time_length[@]}"; do
		for k in "${time_step[@]}"; do
			for l in "${scattering_time[@]}"; do
				for m in "${open_nnl[@]}"; do
					dir="${parent_directory}/lattice_edge_particles_${i}/time_length_${j}/time_step_${k}/scattering_time_${l}/open_nnl_${m}"
					name="lattice_edge_particles_${i}_time_length_${j}_time_step_${k}_scattering_time_${l}_open_nnl_${m}"
					mkdir -p ${dir}
					cp build/main ${dir}/${name}
					cp input/input.txt ${dir}/input.txt
					cd ${dir}
					nohup ./${name} ${i} ${j} ${k} ${l} ${m}&
					cd ${SCRIPT_DIR}
				done
			done
		done
	done
done