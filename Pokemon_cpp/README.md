# Proyecto 1 – Batalla de Pokémon (C++)

## Hecho por:
Sebastian Constaín Valencia

---

## Bases implementadas:

Este proyecto fue desarrollado en **C++**, cumpliendo con todos los requisitos mínimos.

1. **Lenguaje de programación obligatorio: C++**  
   - Todo el código fue escrito en C++ con división adecuada en archivos `.h` y `.cpp`.

2. **Sistema de combate por turnos**
   - El sistema permite que dos Pokémon alternen turnos para atacarse entre sí hasta que uno quede sin puntos de vida (HP).

3. **Menú de interacción**
   - Implementado un menú textual en consola que guía al usuario para seleccionar Pokémon, ataques y visualizar el resultado del combate.

4. **Sistema de ataques**
   - Cada Pokémon tiene **al menos dos ataques distintos**, con daño y tipo definidos.

5. **Sistema de victoria**
   - El combate termina correctamente cuando uno de los Pokémon queda sin vida, y se muestra al ganador.

---

## Estructura del Proyecto

```
Pokemon_cpp/
├── include/
│   ├── ataque.h       ← Declaración de clase Ataque
│   └── pokemon.h      ← Declaración de clase Pokemon
├── src/
│   ├── ataque.cpp     ← Implementación de Ataque
│   ├── pokemon.cpp    ← Implementación de Pokemon
│   └── main.cpp       ← Lógica principal del combate por turnos
```

---

## Innovaciones Implementadas

### 1. Separación modular en múltiples archivos
- **¿Para qué se implementó?**: Para facilitar la organización y mantenimiento del código.
- **¿Por qué se consideró necesario?**: Mejora la escalabilidad del proyecto y permite reutilizar componentes.
- **¿Cómo se implementó?**: Se usaron carpetas `include/` y `src/` para dividir declaraciones e implementaciones, siguiendo buenas prácticas en C++.

### 2. Sistema de ataques personalizados
- **¿Para qué se implementó?**: Para dar variedad al combate.
- **¿Por qué se consideró necesario?**: Hace que cada combate sea más dinámico y realista, simulando el estilo de los juegos originales.
- **¿Cómo se implementó?**: La clase `Ataque` tiene atributos como nombre, poder y tipo; los Pokémon pueden tener varios ataques con diferentes efectos.

### 3. Implementacion de 2 modos de juego
- **¿Para qué se implementó?**: Para poder jugar tanto en solitario como contra alguien, ademas de facilitar el testeo.
- **Por qué se consideró necesario?**: Uno no siempre tiene alguien con quien jugar, y si en algo se caracterizan los juegos de Pokemon es en su modo Singleplayer
- **¿Cómo se implementó?**: Se crean 2 casos que el usuario puede elegir, o contra otro jugador u contra un bot. El bot no tiene inteligencia alguna y funciona a partir de decisiones aleatorias.
---

## Cómo Compilar y Ejecutar

1. Abre una terminal en la carpeta `Pokemon_cpp`.

2. Compila con el siguiente comando:

   ```bash
   g++ -std=c++11 src/*.cpp -Iinclude -o batalla_pokemon
   ```

3. Ejecuta el programa:

   ```bash
   ./batalla_pokemon
   ```

---
