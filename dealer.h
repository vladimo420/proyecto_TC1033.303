#pragma once
/*
 * Archivo: Dealer.h
 * Descripción: Clase que representa a la Casa (Dealer).
 * Hereda de Jugador y añade lógica específica de IA simple y ocultamiento de cartas.
 */

#include "Jugador.h" 

using namespace std;

class Dealer : public Jugador {
    public:
        // Constructor. Asigna el nombre fijo "La Casa".
        Dealer() {
            nombre = "La Casa";
        }

        // Muestra la mano con la primera carta oculta.
        // Sobrescribe el comportamiento visual de Jugador para simular reglas de Blackjack.
        void mostrar_mano_oculta() {
            cout << "Mano de " << nombre << ": ";
            if (mano.size() > 0) {
                mano[0].muestra_carta();
                cout << " [CARTA OCULTA]";
            }
            cout << endl;
        }

        // Decide si la casa debe pedir otra carta (IA simple).
        // Regla: La casa siempre pide carta si tiene menos de 17 puntos.
        bool debe_pedir_carta() {
            return puntaje < 17;
        }
};