import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def read(filename,*arg):
    print(filename)
    print(arg)

    df = pd.read_csv(filename, names=arg)

    print (type(df))
    return df

if __name__ == "__main__":
    filepath = r"input/test_Cut_LJ_Potential.txt"
    to_plot_columns = ("position", "potential")
    df = read(filepath, "position", "potential")
    
    fig, ax = plt.subplots()

    ax.scatter(df[to_plot_columns[0]], df[to_plot_columns[1]])
    ax.set_xlabel(to_plot_columns[0])
    ax.set_ylabel(to_plot_columns[1])
    ax.set_ylim(-0.5,100)
    
    fig.savefig("output.jpg", dpi = 200)
    print("finished")
