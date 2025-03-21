import bisect  # Se você deseja usar insort

def binary_search(lista, x):
    left = 0
    right = len(lista) - 1

    while left <= right:
        mid = (left + right) // 2

        if lista[mid] == x:
            return mid
        elif lista[mid] < x:
            left = mid + 1
        else:
            right = mid - 1

    return -1

def main():
    while True:  # Loop para ler até EOF
        try:
            # Verifique se a entrada não está vazia antes de continuar
            linha = input()
            if not linha.strip():  # Se a linha estiver vazia, continue
                continue

            n = int(linha)  # Lê o número de itens

            lista = []

            # Lê a lista de números e os insere na lista ordenada
            for num in map(int, input().split()):
                bisect.insort(lista, num)

            # Lê o orçamento
            orcamento = int(input())

            solucoes = []

            for i in range(n // 2):
                if lista[i] >= orcamento:
                    continue
                resultado_busca = binary_search(lista, orcamento - lista[i])
                if resultado_busca != -1:
                    solucoes.append([lista[i], lista[resultado_busca]])

            if solucoes:
                min_diff = float("inf")
                resposta = []

                for solucao in solucoes:
                    diff = abs(solucao[1] - solucao[0])
                    if diff < min_diff:
                        min_diff = diff
                        resposta = solucao

                print(f"Joaquina deve comprar os jogos de preços {resposta[0]} e {resposta[1]}.\n")
        except EOFError:
            break  # Sai do loop quando atingir o EOF
        except ValueError:
            continue  # Ignora linhas com valores inválidos (ex: linhas vazias ou não numéricas)


if __name__ == "__main__":
    main()
