import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.animation
import pandas as pd
import numpy as np

filename = r"input/p_l_all_time.txt"
columns = ["qx","qy","qz","q","a","px","py","pz","p","b","fx","fy","fz","f"]

df = pd.read_csv(filename, names=columns)

def time(i):
    return (i//64)

df["a"] = df.index.map(time)

def update_graph(num):
    print(num)
    data=df[df['a']==num]
    graph.set_data (data.qx, data.qy)
    graph.set_3d_properties(data.qz)
    title.set_text('3D Test, time={:.2f}'.format(num*0.01))
    return title, graph
    
fig = plt.figure()
ax = fig.add_subplot(111, azim= 0, elev=5, projection='3d')
title = ax.set_title('3D Test')

ax.set_xlim3d([0.0, 5.0])
ax.set_xlabel('X')

ax.set_ylim3d([0.0, 5.0])
ax.set_ylabel('Y')

ax.set_zlim3d([0.0, 5.0])
ax.set_zlabel('Z')

data=df[df['a']==0]
graph, = ax.plot(data.qx, data.qy, data.qz, linestyle="", marker="o")

ani = matplotlib.animation.FuncAnimation(fig, update_graph, 400, interval=50, blit=False)


ani.save('im.gif', fps=10, dpi = 300)