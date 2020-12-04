import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

filename = r"input/all_Particles.txt"
columns = ["qx","qy","qz","q","a","px","py","pz","p","b","fx","fy","fz","f"]

df = pd.read_csv(filename, names=columns)

print(df.head())

fig, ax = plt.subplots(dpi=200)
ax.hist(df['px'])

fig.savefig("velocity_x_distribution.jpg")