import sys

def main():
    tamanho_min_tanque = 0
    gasto_combustivel = []  # Lista de tuplas (distancia, consumo)
    total_vazamentos = 0
    consumo = -1  # Consumo atual

    for line in sys.stdin:
        line = line.strip()  # Remove espaços extras e quebras de linha
        if not line:
            continue
        
        parts = line.split(maxsplit=1)
        if not parts:
            continue

        try:
            d = int(parts[0])  # Lê a distância inicial
        except ValueError:
            continue

        evento = parts[1] if len(parts) > 1 else ""

        if evento.startswith("Consumo de combustível"):
            try:
                consumo = int(evento.split()[-1])
                if d == 0 and consumo == 0:
                    break
                gasto_combustivel.append((d, consumo / 100.0 + total_vazamentos))
            except ValueError:
                consumo = -1
        elif evento == "Vazamento":
            total_vazamentos += 1
            gasto_combustivel.append((d, consumo / 100.0 + total_vazamentos))
        elif evento == "Mecânico":
            total_vazamentos = 0
            gasto_combustivel.append((d, consumo / 100.0))
        elif evento == "Posto de gasolina":
            tamanho_tanque = 0
            gasto_combustivel.append((d, consumo / 100.0 + total_vazamentos))
            
            for i in range(len(gasto_combustivel) - 1):
                tamanho_tanque += gasto_combustivel[i][1] * (gasto_combustivel[i + 1][0] - gasto_combustivel[i][0])
            
            tamanho_min_tanque = max(tamanho_min_tanque, tamanho_tanque)
            gasto_combustivel.clear()
            gasto_combustivel.append((d, consumo / 100.0 + total_vazamentos))
        elif evento == "Destino":
            tamanho_tanque = 0
            gasto_combustivel.append((d, consumo / 100.0 + total_vazamentos))
            
            for i in range(len(gasto_combustivel) - 1):
                tamanho_tanque += gasto_combustivel[i][1] * (gasto_combustivel[i + 1][0] - gasto_combustivel[i][0])
            
            tamanho_min_tanque = max(tamanho_min_tanque, tamanho_tanque)
            print(f"{tamanho_min_tanque:.3f}")
            sys.stdout.flush()
            
            gasto_combustivel.clear()
            total_vazamentos = 0
            consumo = -1
            tamanho_min_tanque = 0

if __name__ == "__main__":
    main()
