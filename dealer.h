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
         * @brief Muestra la mano aplicando las reglas del Dealer.
         * @details Oculta la segunda carta si es el inicio de la partida.
         * @note Override: Sobrescribe el comportamiento base de Jugador.
         */
        void mostrar_mano() override {
            cout << "Mano de " << nombre << ": ";
            if (mano.size() > 0) {
                mano[0].muestra_carta();
                
                if (mano.size() > 1) {
                    cout << " [CARTA OCULTA]";
                }
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