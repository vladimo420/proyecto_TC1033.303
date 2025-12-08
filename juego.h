#pragma once
/**
 * @file Juego.h
 * @brief Clase controladora principal (Composition Root).
 * @details Gestiona el flujo de las rondas y reglas del Blackjack.
 */

#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include "Dealer.h" 

using namespace std;

class Juego {
    private:
        Jugador humano;       ///< Instancia del jugador
        Dealer computadora;   ///< Instancia del dealer
        double apuesta_actual;///< Monto de la ronda

    public:
        /**
         * @brief Constructor. Configura semilla y estado inicial.
         */
        Juego() {
            srand(time(0));
            humano.set_nombre("Jugador 1");
            apuesta_actual = 0;
        }

        /**
         * @brief Genera una carta aleatoria.
         * @return Objeto Carta.
         */
        Carta generar_carta_random() {
            string palos[] = {"Corazones", "Diamantes", "Treboles", "Picas"};
            int num = (rand() % 13) + 1;
            int paloIdx = rand() % 4;
            Carta c; 
            c.iniciar(num, palos[paloIdx]);
            return c;
        }

        /**
         * @brief Solicita el saldo inicial.
         */
        void configuracion_inicial() {
            double dinero;
            cout << "Bienvenido al Casino." << endl;
            cout << "Ingresa tu dinero inicial: $";
            cin >> dinero;
            humano.set_saldo(dinero);
        }

        /**
         * @brief Gestiona la entrada de la apuesta.
         */
        void pedir_apuesta() {
            double saldo = humano.get_saldo();
            cout << "\n--- NUEVA RONDA ---" << endl;
            cout << "Saldo actual: $" << saldo << endl;
            do {
                cout << "¿Cuanto quieres apostar?: $";
                cin >> apuesta_actual;
                if (apuesta_actual > saldo || apuesta_actual <= 0) 
                    cout << "Apuesta no valida." << endl;
            } while (apuesta_actual > saldo || apuesta_actual <= 0);
        }

        /**
         * @brief Reparte cartas iniciales a los participantes.
         */
        void repartir_cartas_iniciales() {
            humano.limpiar_mano();
            computadora.limpiar_mano();
            
            humano.recibir_carta(generar_carta_random());
            humano.recibir_carta(generar_carta_random());
            computadora.recibir_carta(generar_carta_random());
            computadora.recibir_carta(generar_carta_random());

            humano.mostrar_mano();
            computadora.mostrar_mano_oculta();
        }

        /**
         * @brief Turno del jugador humano.
         */
        void turno_jugador() {
            char opcion = 's';
            while (opcion == 's' && humano.get_puntaje() < 21) {
                cout << "¿Otra carta? (s/n): ";
                cin >> opcion;
                if (opcion == 's') {
                    Carta nueva = generar_carta_random();
                    cout << "Carta: "; nueva.muestra_carta(); cout << endl;
                    humano.recibir_carta(nueva);
                    humano.mostrar_mano();
                }
            }
        }

        /**
         * @brief Turno automático de la casa.
         */
        void turno_dealer() {
            cout << "\n--- Turno de la Casa ---" << endl;
            computadora.mostrar_mano(); 
            while (computadora.debe_pedir_carta()) {
                cout << "La casa pide carta..." << endl;
                Carta nueva = generar_carta_random();
                computadora.recibir_carta(nueva);
                computadora.mostrar_mano();
            }
        }

        /**
         * @brief Determina ganador y ajusta saldos.
         */
        void determinar_ganador() {
            int ph = humano.get_puntaje();
            int pc = computadora.get_puntaje();
            cout << "\n=== RESULTADO ===" << endl;
            
            if (ph > 21) {
                cout << "Te pasaste. PIERDES $" << apuesta_actual << endl;
                humano.perder_apuesta(apuesta_actual);
            } else if (pc > 21) {
                cout << "Casa se paso. GANAS $" << apuesta_actual << endl;
                humano.ganar_apuesta(apuesta_actual);
            } else if (ph > pc) {
                cout << "Mayor puntaje. GANAS $" << apuesta_actual << endl;
                humano.ganar_apuesta(apuesta_actual);
            } else if (pc > ph) {
                cout << "Casa gana. PIERDES $" << apuesta_actual << endl;
                humano.perder_apuesta(apuesta_actual);
            } else {
                cout << "Empate." << endl;
            }
            cout << "Saldo final: $" << humano.get_saldo() << endl;
        }

        /**
         * @brief Bucle principal del juego.
         */
        void jugar() {
            char seguir = 's';
            configuracion_inicial();
            do {
                if (humano.get_saldo() <= 0) {
                    cout << "Sin dinero. Fin del juego." << endl; break;
                }
                pedir_apuesta();
                repartir_cartas_iniciales();
                turno_jugador();
                if (humano.get_puntaje() <= 21) turno_dealer();
                determinar_ganador();
                if (humano.get_saldo() > 0) {
                    cout << "\n¿Jugar otra vez? (s/n): "; cin >> seguir;
                }
            } while (seguir == 's' || seguir == 'S');
        }
};