# Proyecto 2 – Sistema de Parqueadero

## Hecho por:
- Sebastian Constaín Valencia

---

## Funciones implementadas:

1. **Mapa del Parqueadero**
   - Generado dinámicamente con dimensiones **8x8** (cumple con el mínimo de más de 7x7).
   - Uso de caracteres visuales para representar el estado de cada celda:
     - `□` espacio libre
     - `■` espacio ocupado
     - `░` vías de circulación
     - `E` entrada
     - `S` salida

2. **Vías, Entrada y Salida**
   - Se definen vías (`'V'`) que conectan la entrada (`'E'`) en la esquina superior izquierda con la salida (`'S'`) en la esquina inferior derecha, permitiendo el acceso a los espacios de parqueo desde dichas vías.

3. **Registro de Vehículos**
   - Se permite ingresar la **placa del vehículo** y se almacena junto con la **hora de entrada** usando `time.time()`.

4. **Sistema de Cobro**
   - Al retirar un vehículo, se calcula el **tiempo total de permanencia** y se aplica una tarifa de **$3000 por hora**, con un cobro mínimo de **$3000**.

5. **Sistema de Disponibilidad**
   - Visualización clara del número de espacios **libres y ocupados** en tiempo real.
   - El estado se refleja gráficamente en el mapa con los símbolos mencionados.

---

## Innovaciones Implementadas

### 1. Menú Interactivo en Consola
- **¿Para qué se implementó?**: Para facilitar al usuario la navegación entre las funciones disponibles.
- **¿Por qué se consideró necesario?**: Mejora la experiencia de usuario permitiendo un flujo ordenado de operaciones.
- **¿Cómo se implementó?**: Se creó una función `main()` con un bucle `while True` que presenta un menú con opciones numéricas para interactuar con el sistema.

### 2. Visualización Simbólica Mejorada
- **¿Para qué se implementó?**: Para que el usuario pueda entender el estado del parqueadero de forma visual.
- **¿Por qué se consideró necesario?**: Una visualización simbólica permite identificar rápidamente vías, espacios ocupados, libres, entrada y salida.
- **¿Cómo se implementó?**: Se usó un diccionario `simbolos` para mapear los caracteres internos a símbolos Unicode más amigables.

---

## Cómo Ejecutar el Proyecto

1. Asegúrate de tener instalado Python 3.
2. Ejecuta el archivo `.py` con:
   ```bash
   python parqueadero.py
   ```
3. Interactúa con el menú para registrar o retirar vehículos, ver el mapa y consultar la disponibilidad.

---
