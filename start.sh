#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd)"

N=(4)
epsilon=(1.0)
sigma=(1.0)
m=(1.0)
boundary_width=(10.0)
time_length=(10)
time_step=(0.002)

parent_directory="output"

for i in "${N[@]}"; do
	for j in "${epsilon[@]}"; do
		for k in "${sigma[@]}"; do
			for l in "${m[@]}"; do
				for m in "${boundary_width[@]}"; do
					for n in "${time_length[@]}"; do 
						for o in "${time_step[@]}"; do
							dir="${parent_directory}/N_${i}/epsilon_${j}/sigma_${k}/m_${l}/boundary_width_${m}/time_step_${n}"
							name="N_${i}_epsilon_${j}_sigma_${k}_m_${l}_boundary_width_${m}_time_step_${n}"
							mkdir -p ${dir}
							cp build/main ${dir}/${name}
							cp input/input.txt ${dir}/input.txt
							cd ${dir}
							nohup ./${name} ${n} ${o} &
							cd ${SCRIPT_DIR}
						done
					done
				done
			done
		done
	done
done	
