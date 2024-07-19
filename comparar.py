import pandas as pd
import matplotlib.pyplot as plt
# Cargar los archivos CSV
file1 = 'results/execution_times_bloom_filter_3_hash.csv'
file2 = 'results/execution_times_bloom_filter_3_hash_1500000.csv'
file3 = 'results/execution_times_bloom_filter_5_hash.csv'
file4 = 'results/execution_times_bloom_filter_5_hash_1500000.csv'

df1 = pd.read_csv(file1)
df2 = pd.read_csv(file2)
df3 = pd.read_csv(file3)
df4 = pd.read_csv(file4)

df1 = df1[["data", " time"]]
df2 = df2[["data", " time"]]
df3 = df3[["data", " time"]]
df4 = df4[["data", " time"]]

df1['config'] = '3_hash'
df2['config'] = '3_hash_1500000'
df3['config'] = '5_hash'
df4['config'] = '5_hash_1500000'

df = pd.concat([df1, df2])

plt.figure(figsize=(14, 8))
for config in df['config'].unique():
    subset = df[df['config'] == config]
    plt.plot(subset['data'], subset[' time'], marker='o', label=config)

plt.xlabel('Número de palabras')
plt.ylabel('Tiempo de ejecución (s)')
plt.title('Comparación de tiempos de ejecución del filtro Bloom')
plt.xticks(rotation=45, ha='right')
plt.legend()
plt.grid(True)
plt.show()
