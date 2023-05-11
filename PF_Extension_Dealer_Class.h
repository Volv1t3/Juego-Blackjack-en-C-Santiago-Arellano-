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

#ifndef PF_EXTENSION_DEALER_CLASS_H
#define PF_EXTENSION_DEALER_CLASS_H

class Dealer_Class : public Base_Player 
{
    public:
    //! Definicion del Constructor heredado para esta clase
        Dealer_Class(std::string usr_def_name, std::string usr_def_lname) : Base_Player(usr_def_name, usr_def_lname) {};
        void coger_cartas_si_total_menor_17(Logica_Basica& Logica_placeholder);
        void change_value_aces_based_usr_and_amount();
    private:
    //! Definicion de variables numericas para el control del aspecto economico del juego
        int cantidad_de_victorias = {0};
        double cantidad_apuesta = {0.0};
        double cantidad_ganada = {0.0};
        double cantidad_perdida = {0.0};
        int cantidad_de_puntos = {0};
    //! Definicion de variables de texto para el control del usuario
        std::string nombre_usuario = {""};
        std::string apellido_usuario = {""};
    //! Defincion de arreglos y vectores para contener las tarjetas del usuario en forma de nombre
        std::vector<std::string> tarjetas_del_jugador{};
};

#endif