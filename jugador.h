#pragma once
/*
 * Archivo: Jugador.h
 * Descripción: Clase base que representa a un participante genérico.
 * Contiene la mano de cartas, el puntaje y el saldo.
 */

#include <iostream>
#include <vector>
#include "Carta.h" 

using namespace std;

class Jugador {
    protected:
        string nombre;       // Identificador del jugador
        vector<Carta> mano;  // Colección de cartas que tiene el jugador
        int puntaje;         // Suma actual de los valores de las cartas
        double saldo;        // Dinero disponible para apostar

    public:
        // Constructor por defecto. Inicializa puntaje y saldo en 0.
        Jugador() { puntaje = 0; saldo = 0; }

        // --- Getters y Setters ---
        void set_nombre(string _nombre) { nombre = _nombre; }
        string get_nombre() { return nombre; }
        
        void set_saldo(double _saldo) { saldo = _saldo; }
        double get_saldo() { return saldo; }
        int get_puntaje() { return puntaje; }

        // --- Lógica de apuestas ---
        
        // Aumenta el saldo del jugador sumando la cantidad ganada.
        void ganar_apuesta(double cantidad) { saldo += cantidad; }

        // Disminuye el saldo del jugador restando la cantidad perdida.
        void perder_apuesta(double cantidad) { saldo -= cantidad; }

        // --- Gestión de cartas ---

        // Agrega una carta a la mano y actualiza el puntaje total.
        void recibir_carta(Carta c) {
            mano.push_back(c);
            puntaje += c.get_valor_blackjack();
        }

        // Reinicia la mano y el puntaje a cero para una nueva ronda.
        void limpiar_mano() {
            mano.clear();
            puntaje = 0;
        }

        // Muestra todas las cartas en la mano.
        // Es un método virtual para permitir polimorfismo en clases hijas (Dealer).
        virtual void mostrar_mano() {
            cout << "Mano de " << nombre << " (Puntos: " << puntaje << "): ";
            for (int i = 0; i < mano.size(); i++) {
                mano[i].muestra_carta();
                cout << " ";
            }
            cout << endl;
        }
};