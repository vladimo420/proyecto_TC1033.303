# Proyecto Blackjack (21)

Este proyecto implementa una simulación del juego de cartas Blackjack (21) utilizando Programación Orientada a Objetos (POO) en C++.

## Descripción y Contexto
El entretenimiento es una necesidad humana fundamental. Este proyecto va enfocado a personas que buscan entretenimiento en juegos de azar clásicos. El programa simula una partida donde el usuario recibe un bono inicial y juega contra la casa (Dealer). El objetivo es acercarse a 21 puntos sin pasarse.

### Alcance del Proyecto
* **Para qué sirve:**
    * Simular partidas rápidas de Blackjack contra una IA básica.
    * Demostrar la implementación de Herencia, Composición y Polimorfismo en C++.
    * Gestionar apuestas virtuales y estados de juego.

* **Para qué NO sirve (Limitaciones):**
    * No es una plataforma de apuestas con dinero real.
    * No cuenta con interfaz gráfica (GUI), es exclusivo de consola.
    * No guarda el progreso del saldo una vez cerrado el programa.

## Estructura de Archivos
- `main.cpp`: Punto de entrada.
- `Juego.h`: Lógica principal (Composición).
- `Jugador.h`: Clase base (Herencia).
- `Dealer.h`: Clase derivada (Polimorfismo).
- `Carta.h`: Objeto básico.

## Instrucciones de Compilación y Ejecución
1. Asegúrate de tener un compilador de C++ (G++, MinGW, Clang).
2. Abre la terminal en la carpeta del proyecto.
3. Compila el código:
   `g++ main.cpp -o blackjack`
4. Ejecuta el programa:
   - Windows: `blackjack.exe`
   - Linux/Mac: `./blackjack`
