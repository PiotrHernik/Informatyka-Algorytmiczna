import pandas as pd
import matplotlib.pyplot as plt

# Wczytaj dane z plików CSV
k = 3
matching = pd.read_csv(f"matching_{k}.csv")
time = pd.read_csv(f"time_{k}.csv")

# Wykres maksymalnego skojarzenia
plt.figure(figsize=(10, 5))
plt.plot(matching['i'], matching['AvgMaxFlow'], marker='o', label=f'k={k}')
plt.title('Średnia wielkość maksymalnego skojarzenia')
plt.xlabel('i')
plt.ylabel('AvgMaxFlow')
plt.legend()
plt.grid(True)
plt.savefig(f'plots/matching_{k}.png')
plt.close()

# Wykres czasu działania programu
plt.figure(figsize=(10, 5))
plt.plot(time['i'], time['AvgTime'], marker='o', label=f'k={k}')
plt.title('Średni czas działania programu')
plt.xlabel('i')
plt.ylabel('AvgTime (s)')
plt.legend()
plt.grid(True)
plt.savefig(f'plots/time_{k}.png')
plt.close()