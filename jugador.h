#pragma once
#include <iostream>
#include <vector>
#include "Carta.h" // Incluye a Carta.h

using namespace std;

class Jugador {
    protected:
        string nombre;
        vector<Carta> mano; 
        int puntaje;
        double saldo;

    public:
        Jugador() { puntaje = 0; saldo = 0; }

        // Getters y Setters
        void set_nombre(string _nombre) { nombre = _nombre; }
        string get_nombre() { return nombre; }
        
        void set_saldo(double _saldo) { saldo = _saldo; }
        double get_saldo() { return saldo; }
        int get_puntaje() { return puntaje; }

        // Lógica de apuestas
        void ganar_apuesta(double cantidad) { saldo += cantidad; }
        void perder_apuesta(double cantidad) { saldo -= cantidad; }

        // Gestión de cartas
        void recibir_carta(Carta c) {
            mano.push_back(c);
            puntaje += c.get_valor_blackjack();
        }

        void limpiar_mano() {
            mano.clear();
            puntaje = 0;
        }

        // Virtual: Permite que las clases hijas cambien este comportamiento
        virtual void mostrar_mano() {
            cout << "Mano de " << nombre << " (Puntos: " << puntaje << "): ";
            for (int i = 0; i < mano.size(); i++) {
                mano[i].muestra_carta();
                cout << " ";
            }
            cout << endl;
        }
};