import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

filename = [r"input/3_scatter_nnl.txt",
			r"input/3_scatter_no_nnl.txt",
			r"input/no_scatter_nnb_data.txt",
			r"input/no_scatter_no_nnl_data.txt"
			]
columns = ["time","kinetic energy","potential energy","total energy","mean squared trajectory","system total velocity"]


fig, ax = plt.subplots(dpi=200)

for i in range(4):
	df = pd.read_csv(filename[i], names=columns)
	ax.plot(df["time"],df['mean squared trajectory'],label = filename[i][6:-4])

ax.set_xlabel("time")
ax.set_ylabel("mean squared trajectory")
ax.legend()

fig.savefig("mean squared trajectory.jpg")