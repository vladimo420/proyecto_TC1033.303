/**
 * @file main.cpp
 * @brief Punto de entrada de la aplicación.
 * @details Inicia la ejecución del juego de Blackjack.
 */

#include <iostream>
#include "Juego.h" 

using namespace std;

int main() {
    Juego blackjack;
    blackjack.jugar();
    
    cout << "\nPresiona Enter para salir...";
    cin.ignore();
    cin.get();
    
    return 0;
}