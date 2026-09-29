import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path
from matplotlib.ticker import FuncFormatter


# ==================================================
# CAMINHOS
# ==================================================

PASTA_TEMPOS = Path("../Extras/Tempos")
PASTA_GRAFICOS = Path("../Extras/Graficos")
PASTA_TABELAS = Path("../Extras/Tabelas")

# Cria as pastas caso não existam
PASTA_GRAFICOS.mkdir(parents=True, exist_ok=True)
PASTA_TABELAS.mkdir(parents=True, exist_ok=True)


# ==================================================
# ALGORITMOS
# ==================================================

algoritmos = [
    "insertion_sort",
    "bubble_sort",
    "selection_sort",
    "shell_sort"
]

nomes_algoritmos = {
    "insertion_sort": "Insertion Sort",
    "bubble_sort": "Bubble Sort",
    "selection_sort": "Selection Sort",
    "shell_sort": "Shell Sort"
}


# ==================================================
# FORMATAÇÃO DOS EIXOS
# ==================================================

def formatar_tamanho(x, pos):
    """
    Formata o eixo X sem notação científica.
    Exemplo:
    10       -> 10
    100      -> 100
    1000     -> 1.000
    10000    -> 10.000
    100000   -> 100.000
    1000000  -> 1.000.000
    """
    return f"{int(x):,}".replace(",", ".")


# ==================================================
# 1. GRÁFICOS E TABELAS INDIVIDUAIS
# ==================================================

for algoritmo in algoritmos:

    caminho_csv = PASTA_TEMPOS / f"{algoritmo}.csv"

    # Verifica se o CSV existe
    if not caminho_csv.exists():
        print(f"CSV não encontrado: {caminho_csv}")
        continue

    nome = nomes_algoritmos[algoritmo]

    # --------------------------------------------------
    # Ler CSV
    # --------------------------------------------------

    dados = pd.read_csv(caminho_csv)

    # Verificar colunas
    colunas_necessarias = {
        "tamanho",
        "tipo",
        "tempo"
    }

    if not colunas_necessarias.issubset(dados.columns):
        print(f"CSV inválido: {caminho_csv}")
        continue


    # ==================================================
    # 1.1 GRÁFICO INDIVIDUAL
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
            linewidth=1.8,
            markersize=7,
            label=tipo
        )

    plt.xlabel("Tamanho da instância")
    plt.ylabel("Tempo (segundos)")
    plt.title(f"Tempo de execução - {nome}")

    # Formatação do eixo X
    plt.gca().xaxis.set_major_formatter(
        FuncFormatter(formatar_tamanho)
    )

    plt.legend()
    plt.grid(True)

    plt.tight_layout()

    plt.savefig(
        PASTA_GRAFICOS / f"{algoritmo}.png",
        dpi=300,
        bbox_inches="tight"
    )

    plt.close()


    # ==================================================
    # 1.2 TABELA PNG
    # ==================================================

    tabela = (
        dados.groupby(
            ["tamanho", "tipo"]
        )["tempo"]
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


    # Garantir que todas as colunas existam
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

    tabela[colunas_tempo] = (
        tabela[colunas_tempo]
        .round(6)
    )


    # Criar figura
    fig, ax = plt.subplots(
        figsize=(12, 4.5)
    )

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

    plt.tight_layout()

    plt.savefig(
        PASTA_TABELAS / f"{algoritmo}.png",
        dpi=300,
        bbox_inches="tight"
    )

    plt.close()

    print(
        f"{nome}: gráfico e tabela "
        f"gerados com sucesso!"
    )


# ==================================================
# 2. GRÁFICOS COMPARATIVOS
# ==================================================

print("\nGerando gráficos comparativos...")


tipos = {
    "Crescente": "crescente",
    "Decrescente": "decrescente",
    "Randomico": "aleatoria"
}


for tipo, nome_tipo in tipos.items():

    # Criar figura
    plt.figure(figsize=(10, 6))


    # --------------------------------------------------
    # Adicionar cada algoritmo
    # --------------------------------------------------

    for algoritmo in algoritmos:

        caminho_csv = (
                PASTA_TEMPOS /
                f"{algoritmo}.csv"
        )

        # Verificar CSV
        if not caminho_csv.exists():
            print(
                f"CSV não encontrado: "
                f"{caminho_csv}"
            )
            continue


        # Ler CSV
        dados = pd.read_csv(
            caminho_csv
        )


        # Filtrar tipo de entrada
        dados_tipo = dados[
            dados["tipo"] == tipo
            ]


        # Se não houver dados
        if dados_tipo.empty:
            print(
                f"Nenhum dado encontrado para "
                f"{algoritmo} - {tipo}"
            )
            continue


        # --------------------------------------------------
        # Agrupar por tamanho
        # --------------------------------------------------

        dados_tipo = (
            dados_tipo
            .groupby(
                "tamanho",
                as_index=False
            )["tempo"]
            .mean()
            .sort_values("tamanho")
        )


        # --------------------------------------------------
        # Plotar algoritmo
        # --------------------------------------------------

        plt.plot(
            dados_tipo["tamanho"],
            dados_tipo["tempo"],
            marker="o",
            linestyle="-",
            linewidth=1.8,
            markersize=7,
            label=nomes_algoritmos[algoritmo]
        )


    # ==================================================
    # CONFIGURAÇÕES DO GRÁFICO
    # ==================================================

    plt.xlabel(
        "Tamanho da instância"
    )

    plt.ylabel(
        "Tempo (segundos)"
    )

    plt.title(
        f"Comparação dos algoritmos — "
        f"Entrada {tipo}"
    )


    # --------------------------------------------------
    # Corrigir eixo X
    # --------------------------------------------------

    ax = plt.gca()

    ax.xaxis.set_major_formatter(
        FuncFormatter(formatar_tamanho)
    )


    # --------------------------------------------------
    # Garantir que o eixo Y comece em zero
    # --------------------------------------------------

    ax.set_ylim(bottom=0)


    # --------------------------------------------------
    # Legenda e grade
    # --------------------------------------------------

    plt.legend()

    plt.grid(True)


    # --------------------------------------------------
    # Ajustar layout
    # --------------------------------------------------

    plt.tight_layout()


    # --------------------------------------------------
    # Salvar
    # --------------------------------------------------

    plt.savefig(
        PASTA_GRAFICOS /
        f"comparacao_{nome_tipo}.png",
        dpi=300,
        bbox_inches="tight"
    )

    plt.close()


    print(
        f"Gráfico comparativo "
        f"{tipo} gerado com sucesso!"
    )


# ==================================================
# FINALIZAÇÃO
# ==================================================

print("\nProcessamento concluído!")