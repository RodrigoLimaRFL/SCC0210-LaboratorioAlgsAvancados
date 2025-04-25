# Grupo
# Rodrigo de Freitas Lima - 12547510
# Artur Trottmann Ramos - 14681052
# Henrique Yukia Sekiro - 14614564

def main():
    while True:
        g, n= input().split()
        g = int(g)
        n = int(n)

        if g != 0 and n!=0:
            lootValue = map(int, input().split())
            lootValue = list(lootValue)

            # Matriz de dp
            # dp[i] = número mínimo de itens necessários para obter i de ouro
            dp = [float('inf')] * (g + 1)
            dp[0] = 0 # caso base, com 0 de ouro, 0 itens são necessários

            for i in range(1, g + 1): # itera sobre o valor de ouro
                for j in range(n): # itera sobre os itens disponíveis
                    if i - lootValue[j] >= 0:
                        dp[i] = min(dp[i], dp[i - lootValue[j]] + 1)

            if dp[g] == float('inf'):
                print("-1")
            else:
                print(dp[g])
        else:
            break

if __name__ == "__main__":
    main()