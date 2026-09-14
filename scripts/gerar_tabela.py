
import pandas as pd
import matplotlib.pyplot as plt

# Ler o CSV
df = pd.read_csv("../Algoritmos/Tempos/insertion_sort.csv")

# Calcular a média dos tempos por tamanho e tipo
tabela = (
    df.groupby(["tamanho", "tipo"])["tempo"]
    .mean()
    .unstack()
    .reset_index()
)

# Renomear colunas
tabela = tabela.rename(columns={
    "tamanho": "Tamanho (n)",
    "Crescente": "Crescente (s)",
    "Decrescente": "Decrescente (s)",
    "Randomico": "Aleatória (s)"
})

# Ordenar pelo tamanho
tabela = tabela.sort_values("Tamanho (n)")

# Arredondar os tempos
colunas_tempo = [
    "Crescente (s)",
    "Decrescente (s)",
    "Aleatória (s)"
]

tabela[colunas_tempo] = tabela[colunas_tempo].round(6)

# Criar a figura
fig, ax = plt.subplots(figsize=(12, 4.5))

ax.axis("off")

# Criar tabela visual
tabela_visual = ax.table(
    cellText=tabela.values,
    colLabels=tabela.columns,
    cellLoc="center",
    loc="center"
)

# Ajustar aparência
tabela_visual.auto_set_font_size(False)
tabela_visual.set_fontsize(10)
tabela_visual.scale(1, 2)

# Título
plt.title(
    "Resultados dos experimentos — Insertion Sort",
    fontsize=14,
    pad=20
)

# Salvar como PNG
plt.savefig(
    "../Algoritmos/Tabelas/insertion_sort.png",
    dpi=300,
    bbox_inches="tight"
)

plt.close()

print("Tabela PNG gerada com sucesso!")