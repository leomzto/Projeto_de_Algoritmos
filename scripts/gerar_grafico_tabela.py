import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

# Caminhos
PASTA_TEMPOS = Path("../Extras/Tempos")
PASTA_GRAFICOS = Path("../Extras/Graficos")
PASTA_TABELAS = Path("../Extras/Tabelas")

# Cria as pastas caso não existam
PASTA_GRAFICOS.mkdir(parents=True, exist_ok=True)
PASTA_TABELAS.mkdir(parents=True, exist_ok=True)

# Algoritmos que serão processados
algoritmos = [
    "insertion_sort",
    "bubble_sort",
    "selection_sort",
    "shell_sort"
]

# Nomes para exibição
nomes_algoritmos = {
    "insertion_sort": "Insertion Sort",
    "bubble_sort": "Bubble Sort",
    "selection_sort": "Selection Sort",
    "shell_sort": "Shell Sort"
}

for algoritmo in algoritmos:

    caminho_csv = PASTA_TEMPOS / f"{algoritmo}.csv"

    # Se o CSV ainda não existir, pula para o próximo
    if not caminho_csv.exists():
        print(f"CSV não encontrado: {caminho_csv}")
        continue

    nome = nomes_algoritmos[algoritmo]

    # Ler o CSV
    dados = pd.read_csv(caminho_csv)

    # Verificar se o CSV possui as colunas necessárias
    colunas_necessarias = {"tamanho", "tipo", "tempo"}

    if not colunas_necessarias.issubset(dados.columns):
        print(f"CSV inválido: {caminho_csv}")
        continue

    # ==================================================
    # 1. GERAR GRÁFICO
    # ==================================================

    plt.figure(figsize=(10, 6))

    for tipo in dados["tipo"].unique():

        dados_tipo = (
            dados[dados["tipo"] == tipo]
            .groupby("tamanho", as_index=False)["tempo"]
            .mean()
            .sort_values("tamanho")
        )

        plt.plot(
            dados_tipo["tamanho"],
            dados_tipo["tempo"],
            marker="o",
            linestyle="-",
            label=tipo
        )

    plt.xlabel("Tamanho da instância")
    plt.ylabel("Tempo (segundos)")
    plt.title(f"Tempo de execução - {nome}")

    plt.legend()
    plt.grid()

    plt.savefig(
        PASTA_GRAFICOS / f"{algoritmo}.png",
        dpi=300,
        bbox_inches="tight"
    )

    plt.close()

    # ==================================================
    # 2. GERAR TABELA PNG
    # ==================================================

    tabela = (
        dados.groupby(["tamanho", "tipo"])["tempo"]
        .mean()
        .unstack()
        .reset_index()
    )

    tabela = tabela.rename(columns={
        "tamanho": "Tamanho (n)",
        "Crescente": "Crescente (s)",
        "Decrescente": "Decrescente (s)",
        "Randomico": "Aleatória (s)"
    })

    tabela = tabela.sort_values("Tamanho (n)")

    # Garantir que todas as colunas de tempo existam
    colunas_tempo = [
        "Crescente (s)",
        "Decrescente (s)",
        "Aleatória (s)"
    ]

    for coluna in colunas_tempo:
        if coluna not in tabela.columns:
            tabela[coluna] = float("nan")

    tabela = tabela[
        ["Tamanho (n)"] + colunas_tempo
        ]

    tabela[colunas_tempo] = tabela[colunas_tempo].round(6)

    # Criar a figura da tabela
    fig, ax = plt.subplots(figsize=(12, 4.5))

    ax.axis("off")

    tabela_visual = ax.table(
        cellText=tabela.values,
        colLabels=tabela.columns,
        cellLoc="center",
        loc="center"
    )

    tabela_visual.auto_set_font_size(False)
    tabela_visual.set_fontsize(10)
    tabela_visual.scale(1, 2)

    plt.title(
        f"Resultados dos experimentos — {nome}",
        fontsize=14,
        pad=20
    )

    plt.savefig(
        PASTA_TABELAS / f"{algoritmo}.png",
        dpi=300,
        bbox_inches="tight"
    )

    plt.close()

    print(f"{nome}: gráfico e tabela gerados com sucesso!")

print("\nProcessamento concluído!")