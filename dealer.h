#pragma once
/**
 * @file Dealer.h
 * @brief Clase que representa a la Casa (Dealer).
 * @details Hereda de Jugador y añade lógica de IA.
 */

#include "Jugador.h" 

using namespace std;

class Dealer : public Jugador {
    public:
        /**
         * @brief Constructor. Asigna el nombre fijo "La Casa".
         */
        Dealer() {
            nombre = "La Casa";
        }

        /**
         * @brief Muestra la mano con la primera carta oculta.
         * @note Sobrescribe el comportamiento de Jugador.
         */
        void mostrar_mano_oculta() {
            cout << "Mano de " << nombre << ": ";
            if (mano.size() > 0) {
                mano[0].muestra_carta();
                cout << " [CARTA OCULTA]";
            }
            cout << endl;
        }

        /**
         * @brief Decide si la casa debe pedir otra carta.
         * @return true si tiene menos de 17 puntos.
         */
        bool debe_pedir_carta() {
            return puntaje < 17;
        }
};