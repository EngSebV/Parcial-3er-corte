import time

filas = 8
columnas = 8
mapa = [['L' for _ in range(columnas)] for _ in range(filas)]
vehiculos = {}

mapa[0][0] = 'E'
mapa[filas - 1][columnas - 1] = 'S'

for f in range(filas):
    mapa[f][1] = 'V'
    mapa[f][4] = 'V'
for c in range(columnas):
    mapa[3][c] = 'V'
    mapa[6][c] = 'V'

def mostrar_mapa():
    simbolos = {'L': '□', 'O': '■', 'V': '░', 'E': 'E', 'S': 'S'}
    print("\n    " + " ".join(f"{i}" for i in range(columnas)))  
    for idx, fila in enumerate(mapa):
        linea = " ".join(simbolos.get(c, c) for c in fila)
        print(f"{idx:>2}  {linea}")  

def registrar_vehiculo():
    placa = input("Ingrese la placa del vehículo: ").upper()
    if placa in vehiculos:
        print("Ese vehículo ya está registrado.")
        return
    try:
        fila = int(input(f"Fila (0 a {filas - 1}): "))
        columna = int(input(f"Columna (0 a {columnas - 1}): "))
    except ValueError:
        print("Debe ingresar números.")
        return
    if mapa[fila][columna] != 'L':
        print("Ese espacio no está libre.")
        return
    mapa[fila][columna] = 'O'
    vehiculos[placa] = (fila, columna, time.time())
    print(f"Vehículo {placa} registrado en ({fila}, {columna}).")

def retirar_vehiculo():
    placa = input("Ingrese la placa del vehículo: ").upper()
    if placa not in vehiculos:
        print("Vehículo no encontrado.")
        return
    fila, columna, entrada = vehiculos.pop(placa)
    mapa[fila][columna] = 'L'
    tiempo = time.time() - entrada
    costo = max(3000, (tiempo / 3600) * 3000)
    print(f"Vehículo {placa} retirado. Tiempo: {tiempo / 60:.2f} min. Costo: ${costo:.2f}")

def mostrar_disponibilidad():
    libres = sum(f.count('L') for f in mapa)
    ocupados = sum(f.count('O') for f in mapa)
    print(f"Espacios libres: {libres} | Ocupados: {ocupados}")

def main():
    while True:
        print("\n--- MENÚ ---")
        print("1. Mostrar mapa")
        print("2. Registrar vehículo")
        print("3. Retirar vehículo")
        print("4. Ver disponibilidad")
        print("5. Salir")
        op = input("Elija una opción: ")
        if op == '1':
            mostrar_mapa()
        elif op == '2':
            registrar_vehiculo()
        elif op == '3':
            retirar_vehiculo()
        elif op == '4':
            mostrar_disponibilidad()
        elif op == '5':
            print("Hasta luego :)")
            break
        else:
            print("Opción no válida.")

if __name__ == "__main__":
    main()
