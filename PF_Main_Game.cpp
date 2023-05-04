/**==============================================
 * ?                    ABOUT
 * @author      : Santiago Arellano
 * @email       : sarellanoj@estud.usfq.edu.ec
 * @uni         : Universidad San Francisco de Quito
 * @clase       : Programacion en C++ y Ejercicios
 * @description : Programa General, juego de BlackJack
=============================================**/

/**==============================================
 * !                  WARNING
 *   Para compilar este codigo usar la siguiente linea de comando
 *!  g++ PF_Main_Game.cpp  PF_Logica_Basica_IMP.cpp PF_Base_Player_Class_IMP.cpp  PF_Functions_Main_Game_IMP.cpp  -o test
=============================================**/


//! Directivas de Preprocesamiento
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstddef>
#include <string>
#include <cctype>
#include <list>
#include <array>
#include <cmath>
#include <ctime>
#include <random>
#include <vector>
#include <algorithm>
#include "PF_Logica_Basica.h"
#include "PF_Base_Player_Class.h"
#include "PF_Extension_Dealer_Class.h"
#include "PF_Functions_Main_Game.h"
using namespace std;


int main()
{
    unsigned int seleccion_del_menu = {0};
    //! Definicion de Jugadores Principales y el motor de logica
    Base_Player Jugador_1("Santiago", "Arellano");
    Dealer_Class Dealer_juego("Dealer", "Alpha");
    Logica_Basica Logic_Engine_Alpha;

    //! Loop Principal para el juego, de este se difulcaran funciones para el trabajao de diversos casos
    bool end_flag_val = false;
    cout <<  setw(47)  << setfill('=') << "|Bienvenido al juego 21 o BlackJack|" << setw(10)  << "" << setfill('=') << endl;

    cout << "Jugador 1: " << Jugador_1.get_nombre_usuario() << " " << Jugador_1.get_apellido_usuario() << endl;
    cout << "Jugador 2: " << Dealer_juego.get_nombre_usuario() << " " << Dealer_juego.get_apellido_usuario() << endl;
    do
    {
        cout << setw(57) << setfill('=') << "" << endl;
        cout << "Seleccione una opcion del siguiente menu\n1. Jugar una Partida\n2. Revisar sus Estadisticas\n3. Reiniciar Scores\n4. Salir del Juego\nSu eleccion es: ";
        cin >> seleccion_del_menu;
        switch (seleccion_del_menu)
        {
            case 1:
            {
                //! Llamada a la funcion que se encarga de esta seccion del juego
                PF_Func_Jugar_una_Partida(Jugador_1, Dealer_juego, Logic_Engine_Alpha);
                continue;
            }
            case 2:
            {
                //! Llamada a la funcion que se encarga de esta seccion del juego
                PF_Func_Revisar_sus_Estadisticas(Jugador_1, Dealer_juego);
                continue;
            }
            case 3:
            {
                //! Llamada a la funcion que se encarga de esta seccion del juego
                PF_Func_Reiniciar_Scores(Jugador_1, Dealer_juego, Logic_Engine_Alpha);
                continue;
            }
            case 4:
            {
                cout << setw(45) << setfill('=') << "|Gracias por jugar, hasta luego!|" << setw(12)  << "" << setfill('=') << endl;
                end_flag_val = true;
                continue;
            }
            default:
            {
                cout << setw(55) << setfill('=') << "|Su seleccion no se encuentra en el menu presentado|" << setw(2)  << "" << setfill('=') << endl; 
                cout << "Solucion: Favor Cerciorarse de que la opcion que elige\neste en un rango de 1 a 4.\n\nGracias! :D"<< endl;
                cout << endl;
                continue;
            }
        }
    } while (end_flag_val == false);
}