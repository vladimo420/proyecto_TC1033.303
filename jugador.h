#pragma once
/**
 * @file Jugador.h
 * @brief Clase base que representa a un participante genérico.
 * @details Implementa el encapsulamiento de datos, gestión de la mano y apuestas.
 */

#include <iostream>
#include <vector>
#include "Carta.h" 

using namespace std;

class Jugador {
    protected:
        string nombre;       ///< Identificador del jugador
        vector<Carta> mano;  ///< Colección de cartas en mano
        int puntaje;         ///< Suma actual de puntos
        double saldo;        ///< Dinero disponible

    public:
        /**
         * @brief Constructor por defecto.
         */
        Jugador() { puntaje = 0; saldo = 0; }

        // --- Getters y Setters ---
        
        void set_nombre(string _nombre) { nombre = _nombre; }
        string get_nombre() { return nombre; }
        
        void set_saldo(double _saldo) { saldo = _saldo; }
        double get_saldo() { return saldo; }
        int get_puntaje() { return puntaje; }

        // --- Lógica de apuestas ---
        
        void ganar_apuesta(double cantidad) { saldo += cantidad; }
        void perder_apuesta(double cantidad) { saldo -= cantidad; }

        // --- Gestión de cartas ---

        /**
         * @brief Agrega una carta a la mano y actualiza el puntaje.
         * @param c Objeto Carta a agregar.
         */
        void recibir_carta(Carta c) {
            mano.push_back(c);
            puntaje += c.get_valor_blackjack();
        }

        /**
         * @brief Reinicia la mano y el puntaje para una nueva ronda.
         */
        void limpiar_mano() {
            mano.clear();
            puntaje = 0;
        }

        /**
         * @brief Muestra todas las cartas en la mano.
         * @note Método virtual para permitir polimorfismo.
         */
        virtual void mostrar_mano() {
            cout << "Mano de " << nombre << " (Puntos: " << puntaje << "): ";
            for (unsigned int i = 0; i < mano.size(); i++) {
                mano[i].muestra_carta();
                cout << " ";
            }
            cout << endl;
        }
};