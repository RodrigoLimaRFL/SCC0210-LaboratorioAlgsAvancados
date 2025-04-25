# Grupo
# Rodrigo de Freitas Lima - 12547510
# Artur Trottmann Ramos - 14681052
# Henrique Yukia Sekiro - 14614564

def main():
    while True:
        num_roteadores, comprimento, largura = input().split()
        num_roteadores = int(num_roteadores)
        comprimento = int(comprimento)
        largura = int(largura)

        if comprimento == 0 and largura == 0 and num_roteadores == 0:
            break

        roteadores = []

        for i in range(num_roteadores):
            distancia_inicio, raio = input().split()
            distancia_inicio = int(distancia_inicio)
            raio = int(raio)

            if raio >= largura/2:
                roteadores.append([distancia_inicio, raio])

        roteadores_cobertura = []

        for i in range(len(roteadores)):
            distancia_inicio, raio = roteadores[i]
            cateto = (raio**2 - (largura/2)**2)**0.5
            inicio = max(0, distancia_inicio - cateto)
            fim = min(comprimento, distancia_inicio + cateto)
            roteadores_cobertura.append([inicio, fim])

        # Ordena inversamente pela posição de fim
        roteadores_cobertura.sort(key=lambda x: x[1], reverse=True)
        num_roteadores_usados = 0
        cobertura_atual = 0

        while cobertura_atual < comprimento:
            num_roteadores_usados += 1
            achou_cobertura = False
            for i in range(len(roteadores_cobertura)):
                inicio, fim = roteadores_cobertura[i]
                if inicio <= cobertura_atual and fim > cobertura_atual:
                    cobertura_atual = fim
                    del roteadores_cobertura[i]
                    achou_cobertura = True
                    break
            
            if not achou_cobertura:
                num_roteadores_usados = -1
                break

        print(num_roteadores_usados)
        roteadores.clear()
        roteadores_cobertura.clear()


if __name__ == "__main__":
    main()