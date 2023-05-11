/**==============================================
 * ?                    ABOUT
 * @author      : Santiago Arellano
 * @email       : sarellanoj@estud.usfq.edu.ec
 * @uni         : Universidad San Francisco de Quito
 * @clase       : Programacion en C++ y Ejercicios
 * @description : Definicion de la clase Base Player, controla a los usuarios.
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


#ifndef PF_BASE_PLAYER_CLASS_H
#define PF_BASE_PLAYER_CLASS_H

class Base_Player
{
    public:
    //! Constructor de la Clase
        Base_Player(std::string usr_def_name, std::string usr_def_lname);
    //! Definicion de metodos para las cantidades numericas
        int get_cantidad_victorias();
        void aumentar_cantidad_victorias_usr(int cantidad_victorias_usr);
        void set_cantidad_apuestas(double cantidad_apuesta_usr);
        double get_cantidad_apuestas();
        double get_cantidad_ganada();
        void aumentar_cantidad_ganada_usr(double cantidad_ganada_usr);
        double get_cantidad_perdida();
        void aumentar_cantidad_perdida_usr(double cantidad_perdida_usr);
        void aumentar_cantidad_puntos_usr(int cantidad_puntos_usr);
        int get_cantidad_puntos();
        void reset_cantidad_perdida_y_ganada_usr_y_puntos();
    //! Checkeo numerico para tarjetas as
        void change_value_aces_based_usr_and_amount();
    //! Definicionde metodos para los valores de texto
        std::string get_nombre_usuario();
        void set_nombre_usuario(std::string nombre_usuario_new);
        std::string get_apellido_usuario();
        void set_apellido_usuario(std::string apellido_usuario_new);
    //! Definicion de metodos para la adicion e impresion de tarjetas
        void anadir_tarjeta_al_usr(std::string nombre_tarjeta_nueva);
        void imprimir_tarjetas_del_usr(unsigned int cantidad_de_tarjetas_a_imprimir);
        void reset_cartas_y_puntos_del_usr();
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