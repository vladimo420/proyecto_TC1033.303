/*
 * Archivo: main.cpp
 * Descripción: Punto de entrada de la aplicación.
 * Inicia la ejecución del juego de Blackjack.
 */

#include <iostream>
#include "Juego.h" 

using namespace std;

int main() {
    // Instancia el juego e inicia el bucle principal
    Juego blackjack;
    blackjack.jugar();
    
    return 0;
}