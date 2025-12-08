#pragma once
/**
 * @file Carta.h
 * @brief Clase que representa una carta individual de la baraja.
 * @details Gestiona el valor numérico y el palo.
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Carta {
    private:
        int numero;     ///< Valor numérico de la carta (1-13)
        string palo;    ///< Palo de la carta

    public:
        /**
         * @brief Constructor por defecto.
         */
        Carta() { numero = 0; palo = ""; }

        /**
         * @brief Inicializa la carta con valores específicos.
         * @param _numero Número de la carta.
         * @param _palo Palo de la carta.
         */
        void iniciar(int _numero, string _palo) {
            numero = _numero;
            palo = _palo;
        }

        /**
         * @brief Obtiene el valor para Blackjack (J,Q,K valen 10).
         * @return Valor entero.
         */
        int get_valor_blackjack() {
            if (numero > 10) return 10;
            return numero;
        }

        /**
         * @brief Imprime la representación textual de la carta.
         */
        void muestra_carta() {
            string nombre;
            if (numero == 1) nombre = "AS";
            else if (numero == 11) nombre = "J";
            else if (numero == 12) nombre = "Q";
            else if (numero == 13) nombre = "K";
            else {
                stringstream ss;
                ss << numero;
                nombre = ss.str();
            }
            cout << "[" << nombre << " de " << palo << "]";
        }
};