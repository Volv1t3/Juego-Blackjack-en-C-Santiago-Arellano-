/**==============================================
 * ?                    ABOUT
 * @author      : Santiago Arellano
 * @email       : sarellanoj@estud.usfq.edu.ec
 * @uni         : Universidad San Francisco de Quito
 * @clase       : Programacion en C++ y Ejercicios
 * @description : Implementacion de la clase Base Player, controla los usuarios.
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



//! Implementacion del constructor para la clase Base Player
Base_Player::Base_Player(std::string usr_def_name, std::string usr_def_lname)
{
    if ((usr_def_name.length() > 0 && usr_def_lname.length() >0) && (usr_def_name.length() <= 32 && usr_def_lname.length() <= 32))
    {
        nombre_usuario = usr_def_name;
        apellido_usuario = usr_def_lname;
    }
    else 
    {
        nombre_usuario = "Cadena Vacia";
        apellido_usuario = "Cadena Vacia";
    }
}
//! Implementacion de metodos para las cantidades numericas

int Base_Player::get_cantidad_victorias()
{
    return cantidad_de_victorias;
}

void Base_Player::aumentar_cantidad_victorias_usr(int cantidad_victorias_usr)
{
    cantidad_de_victorias += cantidad_victorias_usr;
}

void Base_Player::set_cantidad_apuestas(double cantidad_apuesta_usr)
{
    if (cantidad_apuesta_usr > 0)
    {
        cantidad_apuesta = cantidad_apuesta_usr;
    }
}

double Base_Player::get_cantidad_apuestas()
{
    return cantidad_apuesta;
}

double Base_Player::get_cantidad_ganada()
{
    return cantidad_ganada;
}

void Base_Player::aumentar_cantidad_ganada_usr(double cantidad_ganada_usr)
{
    cantidad_ganada += cantidad_ganada_usr;
}

double Base_Player::get_cantidad_perdida()
{
    return cantidad_perdida;
}

void Base_Player::aumentar_cantidad_perdida_usr(double cantidad_perdida_usr)
{
    cantidad_perdida += cantidad_perdida_usr;
}

void Base_Player::aumentar_cantidad_puntos_usr(int cantidad_puntos_usr)
{
    cantidad_de_puntos += cantidad_puntos_usr;
}

int Base_Player::get_cantidad_puntos()
{
    return cantidad_de_puntos;
}

void Base_Player::reset_cantidad_perdida_y_ganada_usr_y_puntos()
{
    cantidad_apuesta = 0;
    cantidad_de_puntos = 0;
    cantidad_de_victorias = 0;
    cantidad_ganada = 0;
    cantidad_perdida = 0;
    tarjetas_del_jugador.clear();
}

//! Definicionde metodos para los valores de texto

std::string Base_Player::get_nombre_usuario()
{
    return nombre_usuario;
}

void Base_Player::set_nombre_usuario(std::string nombre_usuario_new)
{
  if (nombre_usuario_new.length() > 0 && nombre_usuario_new.length() <= 32)
    {
        nombre_usuario = nombre_usuario_new;
    }  
}

std::string Base_Player::get_apellido_usuario()
{
    return apellido_usuario;
}

void Base_Player::set_apellido_usuario(std::string apellido_usuario_new)
{
    if (apellido_usuario_new.length() > 0 && apellido_usuario_new.length() <= 32)
    {
        apellido_usuario = apellido_usuario_new;
    }
}


//! Definicion de metodos para la adicion e impresion de tarjetas

void Base_Player::anadir_tarjeta_al_usr(std::string nombre_tarjeta_nueva)
{
    tarjetas_del_jugador.push_back(nombre_tarjeta_nueva);
}

void Base_Player::imprimir_tarjetas_del_usr(unsigned int cantidad_de_tarjetas_a_imprimir)
{
    std::cout << std::setw(57) << std::setfill('=') <<"" << std::endl;
    std::cout << "Jugador: " << nombre_usuario << " " << apellido_usuario << "\n";
    std::cout << std::setw(48) << std::setfill('=') << "|Estas son tus tarjetas hasta el momento|"  << std::setw(9) << std::setfill('=') << "" << std::endl;
    for (std::size_t index = 0; index < cantidad_de_tarjetas_a_imprimir-1; index++)
    {
        
        try
        {
            std::cout  << index +1 << "\x7E ";
            {std::cout << tarjetas_del_jugador.at(index) << " \n";}
        }
        catch(const std::out_of_range)
        {
            continue;
        }
    }
    std::cout << std::setw(57) << std::setfill('=') <<"" << std::endl;
}

void Base_Player::reset_cartas_y_puntos_del_usr()
{
    //! Utilizamos el metodo clear() para resetear el vector a su extension original y quitarle los valores
    tarjetas_del_jugador.clear(); 
    cantidad_de_puntos = 0;
}
