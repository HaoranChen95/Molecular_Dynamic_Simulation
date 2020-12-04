import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

filename = r"input/all_Particles.txt"
columns = ["qx","qy","qz","q","a","px","py","pz","p","b","fx","fy","fz","f"]

df = pd.read_csv(filename, names=columns)

fig = plt.figure(dpi=200)
ax = fig.add_subplot(111, azim= -40, elev=5,  projection='3d')
ax.set_xlim(0, 5.03968)

ax.scatter(df['qx'],df['qy'],df['qz'])

fig.savefig("lattice.jpg")