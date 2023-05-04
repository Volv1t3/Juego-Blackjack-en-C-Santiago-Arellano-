/**==============================================
 * ?                    ABOUT
 * @author      : Santiago Arellano
 * @email       : sarellanoj@estud.usfq.edu.ec
 * @uni         : Universidad San Francisco de Quito
 * @clase       : Programacion en C++ y Ejercicios
 * @description : Implementacion de la logica basica del programa, sort, generacion, seleccion de tarjetas.
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
#include "PF_Logica_Basica.h"


//! Implementacion de funcion para generar las cartas 

    void Logica_Basica::generate_cards()
    {
        //? For loop para generar valores desde 0 hasta 51
            for (std::size_t val_to_generate = 0; val_to_generate < Card_number_holder_array.size(); val_to_generate +=1)
            {
               Card_number_holder_array.at(val_to_generate) = val_to_generate;
            }
        //? Generacion de los pesos de cada carta
            int index = 0;  
            for (int repetitions = 0; repetitions < size_of_a_deck / amount_cards_per_type; repetitions++)
            {
                for (int real_value_per_card = 1; real_value_per_card <= amount_cards_per_type; real_value_per_card++)
                {
                    if (real_value_per_card == 11 or real_value_per_card == 12 or real_value_per_card == 13)
                    {
                        Card_number_real_values_array[index] = 10;
                    }
                    else {Card_number_real_values_array[index] = real_value_per_card;}

                    index++;
                }
            }

    }
//! Implementacion de funcion para imprimir las cartas, esto solo sirve como debug
    void Logica_Basica::print_out_cards()
    {
        std::cout << "Card Indeces" << std::endl;
        for (std::size_t index = 0; index < Card_number_holder_array.size(); index++)
        {
            std::cout << Card_number_holder_array.at(index)  << " ";
        }
        std::cout << std::endl;
        std::cout << "Card Values \n";
        for (std::size_t index = 0; index < Card_number_real_values_array.size(); index++)
        {
            std::cout << Card_number_real_values_array.at(index)  << " ";
        } 
        std::cout << std::endl;
    }
//! Fucion para randomizar las cartas en el sistema
    void Logica_Basica::shuffle_cards_randomly()
    {
        //? Para el shuffle de las tarjetas se decidio utilizar una semillia utilizando la funcion srand con time null del include ctime y pasarla por un generador de numeros aleatorios con la funcion rand para obtener una semilla diferente en cada ejecucion
        std::random_device metodo_tarjetas_y_shuffle_random;
        std::mt19937 generador_de_tarjetas_random(metodo_tarjetas_y_shuffle_random());
        //? Funcion de la libreria #include <algorithm> que permite aleatorizar los indices de las cartas en un arrego.
        std::shuffle(Card_number_holder_array.begin(), Card_number_holder_array.end(),generador_de_tarjetas_random);
    }
//! Implementacion de funcion para seleccionar una carta
    Card_Details Logica_Basica::select_a_card()
    {
        //? Seleccionar una carta basada en un numero aleatorio
            std::random_device metodo_tarjetas_y_shuffle_random; //Creando random device usando #include <random>
            std::mt19937 generador_de_tarjetas_random(metodo_tarjetas_y_shuffle_random()); //Creando generador de numeros aleatorios usando #include <random>
            std::uniform_int_distribution<int> distribucion_uniforme_tarjetas_random(0,51); 
            int rand_card_index = distribucion_uniforme_tarjetas_random(metodo_tarjetas_y_shuffle_random);
            int tarjeta_a_anadir= Card_number_holder_array.at(rand_card_index);
        //? Check si la carta ya fue usada durante ejecucion
            for (auto const& cards: cards_alreay_used_here)
            {
                if (tarjeta_a_anadir== cards) {rand_card_index = {0+ std::rand() % 52};}
            }
            cards_alreay_used_here.push_back(tarjeta_a_anadir);
        //? Calculo del valor de la tarjeta basada en su posicion en el arreglo
            int valor_de_la_carta = {0};   
            std::string nombre_de_la_carta = "";
            int peso_de_la_carta = {tarjeta_a_anadir    % amount_cards_per_type};
            switch(peso_de_la_carta)
            {
                case 0:{valor_de_la_carta = 1; break;}
                case 1: {valor_de_la_carta = 2;break;}
                case 2: {valor_de_la_carta = 3;break;}
                case 3: {valor_de_la_carta = 4;break;}
                case 4: {valor_de_la_carta = 5;break;}
                case 5: {valor_de_la_carta = 6;break;}
                case 6: {valor_de_la_carta = 7;break;}
                case 7: {valor_de_la_carta = 8;break;}
                case 8: {valor_de_la_carta = 9;break;}
                case 9: {valor_de_la_carta = 10;break;}
                case 10:
                case 11:
                case 12:
                {
                    valor_de_la_carta = 10;
                    break;
                }
            }
            //! Sistema para obtener el nombre de la tarjeta basada en su posicion y el valor en el arreglo
            int palo_de_la_carta = (tarjeta_a_anadir/ amount_cards_per_type);
            switch(palo_de_la_carta)
            {
                case 0:
                {
                    switch(peso_de_la_carta)
                    {
                        case 10:{nombre_de_la_carta =  "Jack de Corazones Rojos";break;}
                        case 11:{nombre_de_la_carta = "Reina de Corazones Rojos";break;}
                        case 12:{nombre_de_la_carta = "Rey de Corazones Rojos";break;}
                        default:
                        {
                            nombre_de_la_carta =  std::to_string(valor_de_la_carta) + " de" + " Corazones Rojos";
                            break;
                        }
                    }
                    break;

                }
                case 1:
                {
                    switch(peso_de_la_carta)
                    {
                        case 10:{nombre_de_la_carta =  "Jack de Corazones Negros";break;}
                        case 11:{nombre_de_la_carta = "Reina de Corazones Negros";break;}
                        case 12:{nombre_de_la_carta = "Rey de Corazones Negros";break;}
                        default:
                        {
                            nombre_de_la_carta =  std::to_string(valor_de_la_carta) + " de" + " Corazones Negros";
                            break;
                        }
                    }
                    break;
                }
                case 2:
                {
                    switch(peso_de_la_carta)
                    {
                        case 10:{nombre_de_la_carta =  "Jack de Diamantes";break;}
                        case 11:{nombre_de_la_carta = "Reina de Diamantes";break;}
                        case 12:{nombre_de_la_carta = "Rey de Diamantes";break;}
                        default:
                        {
                            nombre_de_la_carta =  std::to_string(valor_de_la_carta) + " de" + " Diamantes";
                            break;
                        }
                    }
                    break;
                }
                case 3: 
                {
                   switch(peso_de_la_carta)
                    {
                        case 10:{nombre_de_la_carta =  "Jack de Treboles";break;}
                        case 11:{nombre_de_la_carta = "Reina de Treboles";break;}
                        case 12:{nombre_de_la_carta = "Rey de Treboles";break;}
                        default:
                        {
                            nombre_de_la_carta =  std::to_string(valor_de_la_carta) + " de" + " Treboles";
                            break;
                        }
                    }
                    break;
                }
            }

        //! Control de aparicion de datos
            auto flow_control = check_if_card_was_used(peso_de_la_carta, palo_de_la_carta);

         //! Localizacion de los datos en los valores del struct para regresarlos al programa general usando recursion 
            if (flow_control == false)
            {
                Cards_already_played.at(peso_de_la_carta).at(palo_de_la_carta) = 1;
                Card_Details selected_card;
                selected_card.Card_Name = nombre_de_la_carta;
                selected_card.Card_Value = valor_de_la_carta;
                return selected_card;
            }
            else if (flow_control == true) 
            {
                return select_a_card();
            }   
    }

//! Implementacion de funcion secundaria para evaluar aparicion de la carta 
bool Logica_Basica::check_if_card_was_used(int card_position, int card_type)
{
    int counter_of_occurrences = 0;

    for (std::size_t column = 0; column < amount_of_types; column+=1)
    {
        if( Cards_already_played.at(card_position).at(column) == 1)
        {
            counter_of_occurrences++;
        }
    }

    if( counter_of_occurrences == 4 or Cards_already_played.at(card_position).at(card_type) == 1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

//! Implementacion de funcion principal para resetear tarjetas usadas
void Logica_Basica::reset_already_played_cards()
{
    //! Reset the array multidimensaional de tarjetas usadas
        for (std::size_t row = 0; row <amount_cards_per_type; row+=1)
        {
            for (std::size_t column = 0; column < amount_of_types; column+=1)
            {
                Cards_already_played.at(row).at(column) = 0;
            }
        }

    //! Reset the vector de tarjetas usadas en el select_card();
        cards_alreay_used_here.clear();
}

