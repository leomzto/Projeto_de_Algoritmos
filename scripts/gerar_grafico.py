import pandas as pd
import matplotlib.pyplot as plt

dados = pd.read_csv("../Algoritmos/Tempos/insertion_sort.csv")

# Cria o gráfico
for tipo in dados["tipo"].unique():
    dados_tipo = dados[dados["tipo"] == tipo].sort_values("tamanho")

    plt.plot(
        dados_tipo["tamanho"],
        dados_tipo["tempo"],
        marker="o",
        linestyle="-",
        label=tipo
    )

# Configurações do gráfico
plt.xlabel("Tamanho da instância")
plt.ylabel("Tempo (segundos)")
plt.title("Tempo de execução - Insertion Sort")

plt.legend()
plt.grid()

# Salva o gráfico
plt.savefig(
    "../Algoritmos/Graficos/insertion_sort.png",
    dpi=300,
    bbox_inches="tight"
)

plt.show()