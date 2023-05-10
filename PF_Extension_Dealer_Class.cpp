/**==============================================
 * ?                    ABOUT
 * @author      : Santiago Arellano
 * @email       : sarellanoj@estud.usfq.edu.ec
 * @uni         : Universidad San Francisco de Quito
 * @clase       : Programacion en C++ y Ejercicios
 * @description : Definicion de la clase extensiva para el dealer, no varia en mucho pero es necesario tenerlo para difulcar el codigo.
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
#include "PF_Logica_Basica.h"
#include "PF_Extension_Dealer_Class.h"

//! Global Vars para la Logica
Logica_Basica Logica_Engine_Alpha;


//! Implementacion de funciones 

void Dealer_Class::tomar_cartas_hasta_puntos_mejor_17()
{
    int puntos_dealer_actuales = cantidad_de_puntos;
    while (puntos_dealer_actuales < 17)
    {
        auto carta_a_anadir = Logica_Engine_Alpha.select_a_card();
        anadir_tarjeta_al_usr(carta_a_anadir.Card_Name);
        aumentar_cantidad_puntos_usr(carta_a_anadir.Card_Value);
        std::cout << "Puntos: " << puntos_dealer_actuales << std::endl;
        std::cout << "Carta: " << carta_a_anadir.Card_Name << std::endl;
        std::cout << "Valor: " << carta_a_anadir.Card_Value << std::endl;
        puntos_dealer_actuales = cantidad_de_puntos;
    }
}