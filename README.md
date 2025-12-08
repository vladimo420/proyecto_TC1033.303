
# BlackJack


### Contexto
-----

El entretenimiento es una necesidad que todo el ser humano tiene, cada quien busca el entretenimiento que prefiere.  Todoas las personas buscan entretenimiento ya sea en el deporte, en los videojuegos, contenido audiovisual, fiestas,e etc. Por lo tanto este proyecto va enfocado a las personas que buscan entretenimiento en juegos de azar como lo es el BlackJack donde la persona pueda pasar un buen rato, donde recibira un "bono" cada ve que entre al programa para poder jugar y al terminar cada juego se da la opcion al usuario de seguir jugando o retirarse con el dinero restante. El juego consta de repartir 2 cartas al azar por parte del dealer en este caso sera por parte del programa que se le entregara al jugador, el objetivo es llegar lo m[as cerca a 21 puntos por lo que si al usuario no le gusta la cantidad inicial que se le dio en las dos cartas siempre puede pedir otra pero si la cantidad llega a sobrepasar 21 el usuario perder la cantidad apostada en el juego al igual que si el programa obtiene en las cartas un numero mayor a 21 se dará por ganador al usuario.
Simulación de juego de Blackjack (21) utilizando Programación Orientada a Objetos en C++.



## Descripción
El proyecto permite a un usuario jugar contra la computadora (Dealer). Implementa los conceptos de:
- **Herencia:** Clase `Dealer` hereda de `Jugador`.
- **Composición:** Clase `Juego` gestiona instancias de `Jugador` y `Dealer`.
- **Polimorfismo:** Método `mostrar_mano()` implementado virtualmente.


## Estructura de Archivos
- `main.cpp`: Punto de entrada.
- `Juego.h`: Lógica principal del juego.
- `Jugador.h`: Clase base del participante.
- `Dealer.h`: Clase derivada (IA).
- `Carta.h`: Objeto básico del juego.



## Instrucciones de Compilación y Ejecución
1. Asegúrate de tener un compilador de C++ (G++, MinGW, Clang).
2. Abre la terminal en la carpeta del proyecto.
3. Compila el archivo principal:
   `g++ main.cpp -o blackjack`
4. Ejecuta el programa:
   - Windows: `blackjack.exe`
   - Linux/Mac: `./blackjack`
