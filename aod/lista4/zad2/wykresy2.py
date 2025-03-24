import pandas as pd
import matplotlib.pyplot as plt

# Wczytaj dane z pliku CSV
data = pd.read_csv("time_vs_k.csv")

# Tworzenie wykresów dla każdego i
unique_i_values = data['i'].unique()
for i in unique_i_values:
    subset = data[data['i'] == i]
    plt.figure()
    plt.plot(subset['k'], subset['AvgTime'], marker='o')
    plt.title(f'Time vs k for i={i}')
    plt.xlabel('k')
    plt.ylabel('Average Time (seconds)')
    plt.grid(True)
    plt.savefig(f'plots2/time_vs_k_i_{i}.png')
    plt.close()

print("Wykresy zapisane jako pliki PNG.")
