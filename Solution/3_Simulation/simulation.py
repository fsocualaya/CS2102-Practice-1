import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('./simulation.csv')

fig = plt.figure("Sorting Algorithms")

plt.title("Insertion Sort vs Merge Sort")

plt.plot(df["Size"],df["Insertion Sort"],label = 'Insertion Sort')

plt.plot(df["Size"],df["Merge Sort"],label = 'Merge Sort')

plt.tight_layout()
plt.xlabel("Array Sizes")
plt.ylabel("Time")
plt.legend()

print(df)
plt.show()
