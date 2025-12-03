#pragma once
#include "Jugador.h" // Hereda de Jugador.h

using namespace std;

class Dealer : public Jugador {
    public:
        Dealer() {
            nombre = "La Casa";
        }

        // Sobrescribe el comportamiento para ocultar una carta
        void mostrar_mano_oculta() {
            cout << "Mano de " << nombre << ": ";
            if (mano.size() > 0) {
                mano[0].muestra_carta();
                cout << " [CARTA OCULTA]";
            }
            cout << endl;
        }

        // IA simple: Pide carta si tiene menos de 17
        bool debe_pedir_carta() {
            return puntaje < 17;
        }
};