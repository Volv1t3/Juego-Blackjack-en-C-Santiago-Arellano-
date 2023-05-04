/**==============================================
 * ?                    ABOUT
 * @author      : Santiago Arellano
 * @email       : sarellanoj@estud.usfq.edu.ec
 * @uni         : Universidad San Francisco de Quito
 * @clase       : Programacion en C++ y Ejercicios
 * @description : Definicion de las funciones principales para la aplicacion
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

#ifndef PF_Functions_Main_Game_H
#define PF_Functions_Main_Game_H

//! Funcion para la opcion uno del menu inicial
void PF_Func_Jugar_una_Partida(Base_Player& Player_placeholder, Dealer_Class& Dealer_placeholder, Logica_Basica& Logica_placeholder);

//! Funcion para la opcion dos del menu inicial
void PF_Func_Revisar_sus_Estadisticas(Base_Player& Player_placeholder, Dealer_Class& Dealer_placeholder);

//! Funcion para la opcion tres del menu inicial

void PF_Func_Reiniciar_Scores(Base_Player& Player_placeholder, Dealer_Class& Dealer_placeholder,Logica_Basica& Logica_placeholder);

#endif