/**==============================================
 * ?                    ABOUT
 * @author      : Santiago Arellano
 * @email       : sarellanoj@estud.usfq.edu.ec
 * @uni         : Universidad San Francisco de Quito
 * @clase       : Programacion en C++ y Ejercicios
 * @description : Definicion de las funciones prinicipales de la logica del programa
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

#ifndef PF_LOGICA_BASICA_H
#define PF_LOGICA_BASICA_H

//! Definicion de un struct para el retorno de la tarjeta al juego
struct Card_Details
{
    std::string Card_Name;
    int Card_Value;
};  

//! Definicion de la clase

class Logica_Basica
{
    public:
        //! Definicion de funciones para esta clase
            void generate_cards(); 
            void shuffle_cards_randomly();  
            Card_Details select_a_card(); 
            void print_out_cards();
            bool check_if_card_was_used(int card_position, int card_type); 
            void reset_already_played_cards(); 
            
    private:
        //! Declaracion de variables para las cartas del juego
             std::array<size_t, 52> Card_number_holder_array{};   
             std::array<int, 52> Card_number_real_values_array{}; 
             const std::array<std::string, 4> Card_Palos{"Corazon Rojo","Corazon Negro", "Diamantes", "Treboles"};
        //! Declaracion de variable para medir las cartas ya jugadas
            std::array<std::array<int,4>,13> Cards_already_played{};
            std::vector<int> cards_alreay_used_here{};
        //! Declaracion de constantes utilizables para el juego
            const int size_of_a_deck = {52};
            const int amount_of_types = {4};
            const int amount_cards_per_type = {13};
};



#endif