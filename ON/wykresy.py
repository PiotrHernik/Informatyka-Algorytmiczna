import pandas as pd
import matplotlib.pyplot as plt

# Wczytaj dane z pliku dane.txt
data = []
with open("dane2.txt", "r") as file:
    lines = file.readlines()
    opcja, block_size = None, None
    for line in lines:
        if line.startswith("Opcja"):
            opcja = int(line.split(":")[1].split()[0])
            block_size = int(line.split(":")[2].split()[0])
        else:
            parts = line.strip().split("; ")
            size = int(parts[0])
            time = float(parts[1].replace(",", "."))
            memory = float(parts[2].replace(",", "."))
            if opcja in [3, 3]:
                memory *= 4  # Przemnożenie pamięci przez 4 tylko dla opcji 3 i 4
            if opcja in [4, 4] and block_size != 4:
                memory *= 6  # Przemnożenie pamięci przez 4 tylko dla opcji 3 i 4
            if opcja in [4, 4] and block_size == 4:
                memory *= 5  # Przemnożenie pamięci przez 4 tylko dla opcji 3 i 4
            memory /= 10
            data.append((opcja, block_size, size, time, memory))

# Przekształć dane do DataFrame
df = pd.DataFrame(data, columns=["Opcja", "Block_size", "Size", "Time", "Memory"])

# Mapowanie nazw opcji
option_labels = {
    1: "Gauss with pivot",
    2: "Gauss without pivot",
    3: "LU with pivot",
    4: "LU without pivot"
}

# Wartości block_size do analizy
block_sizes = df["Block_size"].unique()

# Generowanie wykresów
def plot_metric(metric, metric_label, ylabel, filename):
    for block_size in block_sizes:
        plt.figure(figsize=(10, 6))
        for opcja in df["Opcja"].unique():
            subset = df[(df["Block_size"] == block_size) & (df["Opcja"] == opcja)]
            plt.plot(subset["Size"], subset[metric], marker="o", label=option_labels[opcja])

        plt.title(f"{metric_label} dla l = {block_size}")
        plt.xlabel("Rozmiar macierzy")
        plt.ylabel(ylabel)
        plt.legend()
        plt.grid(True)
        plt.tight_layout()
        plt.savefig(f"{filename}_block_size_{block_size}.png")
        plt.close()

# Wykresy dla czasu
plot_metric("Time", "Czas działania algorytmu", "Czas [s]", "czas")

# Wykresy dla pamięci
plot_metric("Memory", "Zużycie pamięci", "Pamięć [jednostki]", "pamiec")

print("Wykresy zostały zapisane w plikach.")
