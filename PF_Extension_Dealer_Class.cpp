/**==============================================
 * ?                    ABOUT
 * @author      : Santiago Arellano
 * @email       : sarellanoj@estud.usfq.edu.ec
 * @uni         : Universidad San Francisco de Quito
 * @clase       : Programacion en C++ y Ejercicios
 * @description : Implementacion de la clase Dealer, funcion para contar cartas y generar nuevas
=============================================**/


//! Directivas de Preprocesamiento
#include <iostream>
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
#include "PF_Base_Player_Class.h"
#include "PF_Extension_Dealer_Class.h"
#include "PF_Logica_Basica.h"

//! Global Objeto Logica Basica
Logica_Basica Logic_Object_Dealear_Class;

void Dealer_Class::coger_cartas_si_total_menor_17(Logica_Basica& Logica_placeholder )
{
    //! Calling para el valor de lo puntos
    auto total_puntos_dealer_h_momento = Dealer_Class::get_cantidad_puntos();
    //! Generacion de cartas hasta menor de 17
    do
    {
        auto carta_seleccionada = Logica_placeholder.select_a_card();
        Dealer_Class::aumentar_cantidad_puntos_usr(carta_seleccionada.Card_Value);
        Dealer_Class::anadir_tarjeta_al_usr(carta_seleccionada.Card_Name);
        total_puntos_dealer_h_momento = Dealer_Class::get_cantidad_puntos();
    }
    while ((total_puntos_dealer_h_momento < 17));
}

void Dealer_Class::change_value_aces_based_usr_and_amount()
{
    //! Vars ejecucion y encontrar si tiene un as o no
    bool has_ace = false;
    for (size_t index = 0; index < tarjetas_del_jugador.size(); index+=1)
    {
        if (tarjetas_del_jugador.at(index) == "1 de Corazones Rojos") 
        {
            has_ace = true;
        }
        else if (tarjetas_del_jugador.at(index) == "1 de Corazones Negros")
        {   
            has_ace = true;
        }
        else if (tarjetas_del_jugador.at(index) == "1 de Diamantes")
        {
            has_ace = true;
        }
        else if (tarjetas_del_jugador.at(index) == "1 de Treboles")
        {
            has_ace = true;
        }
        else {continue;}
    }
    //! Cuerpo de decision basado en el puntaje actual
    if (has_ace == true)
    {
        if (cantidad_de_puntos <= 10 && cantidad_de_puntos + 11 <= 21)
        {
            cantidad_de_puntos -=1; cantidad_de_victorias += 11;
        }
        else if (cantidad_de_puntos > 11 && cantidad_de_victorias + 1 <= 21)
        {
            cantidad_de_puntos -=1; cantidad_de_puntos +=1;
        }
    }
}
