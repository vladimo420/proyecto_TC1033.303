#pragma once
/*
 * Archivo: Carta.h
 * Descripción: Representa una carta individual de la baraja.
 * Gestiona el valor numérico y el palo de la carta.
 */

#include <iostream>
#include <string>

using namespace std;

class Carta {
    private:
        int numero;     // Valor numérico de la carta (1-13)
        string palo;    // Palo de la carta (Corazones, Diamantes, etc.)

    public:
        // Constructor por defecto. Inicializa una carta vacía.
        Carta() { numero = 0; palo = ""; }

        // Inicializa la carta con un número y un palo específicos.
        void iniciar(int _numero, string _palo) {
            numero = _numero;
            palo = _palo;
        }

        // Obtiene el valor real de la carta para el juego de Blackjack.
        // Retorna 10 si es figura (J, Q, K), o el valor numérico normal.
        int get_valor_blackjack() {
            if (numero > 10) return 10;
            return numero;
        }

        // Imprime la representación textual de la carta.
        // Convierte los números 1, 11, 12, 13 a sus nombres (AS, J, Q, K).
        void muestra_carta() {
            string nombre = to_string(numero);
            if (numero == 1) nombre = "AS";
            if (numero == 11) nombre = "J";
            if (numero == 12) nombre = "Q";
            if (numero == 13) nombre = "K";
            
            cout << "[" << nombre << " de " << palo << "]";
        }
};