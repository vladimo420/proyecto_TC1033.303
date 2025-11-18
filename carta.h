#pragma once
#include <iostream>
#include <string>

using namespace std;

class Carta {
    private:
        int numero; 
        string palo; 

    public:
        Carta() { numero = 0; palo = ""; }

        void iniciar(int _numero, string _palo) {
            numero = _numero;
            palo = _palo;
        }

        int get_valor_blackjack() {
            if (numero > 10) return 10;
            return numero;
        }

        void muestra_carta() {
            string nombre = to_string(numero);
            if (numero == 1) nombre = "AS";
            if (numero == 11) nombre = "J";
            if (numero == 12) nombre = "Q";
            if (numero == 13) nombre = "K";
            
            cout << "[" << nombre << " de " << palo << "]";
        }
};