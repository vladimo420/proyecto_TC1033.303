#include <iostream>
#include "Carta.h"

using namespace std;

int main() {
    cout << "--- Prueba Avance 1: Carta ---" << endl;
    Carta c1;
    c1.iniciar(12, "Diamantes"); // Q de Diamantes
    
    c1.muestra_carta();
    cout << " Valor: " << c1.get_valor_blackjack() << endl;
    
    return 0;
}