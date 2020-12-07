import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

filename = [
    		r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_0/open_nnl_0/data.txt",
			r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_0/open_nnl_1/data.txt",
			r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_1/open_nnl_0/data.txt",
			r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_1/open_nnl_1/data.txt",
			r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_2/open_nnl_0/data.txt",
			r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_2/open_nnl_1/data.txt",
			r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_3/open_nnl_0/data.txt",
			r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_3/open_nnl_1/data.txt",
			r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_4/open_nnl_0/data.txt",
			r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_4/open_nnl_1/data.txt",
			r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_5/open_nnl_0/data.txt",
			r"output/lattice_edge_particles_4/time_length_50/time_step_0.002/scattering_time_5/open_nnl_1/data.txt",
			]
columns = ["time","kinetic energy","potential energy","total energy","mean squared trajectory","system total velocity"]
color = ['#1f77b1', '#ff7f0e', '#2ca02c', '#d62728', '#9467bd', '#8c564b', '#e377c2', '#7f7f7f', '#bcbd22', '#17becf']

fig, ax = plt.subplots(dpi=200)

for i in range(len(filename)):
	df = pd.read_csv(filename[i], names=columns)
	ax.plot(df["time"],df['mean squared trajectory'], color=color[i//2], label = filename[i][64:-9])

ax.set_xlabel("time")
ax.set_ylabel("mean squared trajectory")
ax.legend(fontsize = "x-small")

fig.savefig("mean squared trajectory.jpg")