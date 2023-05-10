/**==============================================
 * ?                    ABOUT
 * @author      : Santiago Arellano
 * @email       : sarellanoj@estud.usfq.edu.ec
 * @uni         : Universidad San Francisco de Quito
 * @clase       : Programacion en C++ y Ejercicios
 * @description : Implementacion de las funciones principales de la aplicacion
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
#include "PF_Functions_Main_Game.h"

void PF_Func_Jugar_una_Partida(Base_Player& Player_placeholder, Dealer_Class& Dealer_placeholder, Logica_Basica& Logica_placeholder)
{
    //! Declaracion de variables para el control del menu de la subseccion
        int seleccion_del_menu = {0};
    //! Impresion de los titulos primarios
        std::cout << std::setw(38) << std::setfill('=') << "|Iniciando la Partida|" << std::setw(19) << "" << std::setfill('=') << std::endl;
        std::cout << std::endl;
        std::cout << std::setw(46) << std::setfill('=') << "|Generando y Mezclando las tarjetas|" << std::setw(11) << "" << std::setfill('=') << std::endl;
        std::cout << std::endl;
    //! Llamada a los metodos del placeholder de logica. 
        Logica_placeholder.generate_cards();
        Logica_placeholder.shuffle_cards_randomly();
    //!Asignacion inicial cartas a los jugadores
        const int max_amount_players = {2};
        const int max_amount_cards_inicio = {2};

        for (std::size_t players = 1; players <= max_amount_players; players +=1)
        {
            for (std::size_t cards = 1; cards <= max_amount_cards_inicio; cards +=1)
            {
                if (players == 1)
                {
                    auto card_helper = Logica_placeholder.select_a_card();
                    Player_placeholder.anadir_tarjeta_al_usr(card_helper.Card_Name);
                    Player_placeholder.aumentar_cantidad_puntos_usr(card_helper.Card_Value);
                }
                else if (players  == 2)
                {
                    auto  card_helper = Logica_placeholder.select_a_card();
                    Dealer_placeholder.anadir_tarjeta_al_usr(card_helper.Card_Name);
                    Dealer_placeholder.aumentar_cantidad_puntos_usr(card_helper.Card_Value);
                }
            }
        }
    //! Impresion de tarjetas y decision del usuario sobre la partida
        //? Solicitud de apuesta inicial
        double auxiliar_cantidad_apuesta = {0.0};
        std::cout << std::setw(42) << std::setfill('=') << "|Cuanto dinero desea apostar?|" << std::setw(15) << std::setfill('=') <<  "" <<std::endl;
        std::cout << "Cantidad:  ";
        std::cin >> auxiliar_cantidad_apuesta;
        //? Impresion de tarjetas
        std::cout << std::setw(40) << std::setfill('=') << "|Imprimiendo las Tarjetas|" << std::setw(17) << "" << std::setfill('=') << std::endl;
        Player_placeholder.imprimir_tarjetas_del_usr(3); 
        Dealer_placeholder.imprimir_tarjetas_del_usr(2);
        std::cout << std::setw(57) << std::setfill('=') <<"" << std::endl;
        Player_placeholder.set_cantidad_apuestas(auxiliar_cantidad_apuesta);
        std::cout << std::setw(57) << std::setfill('=') <<"" << std::endl;
        //? Impresion de menu subseccion
        std::cout << "Teniendo en cuenta la informacion presentada\nen la impresion de las tarjetas, Que desea hacer?" << std::endl;
        std::cout << std::setw(57) << std::setfill('=') <<"" << std::endl;
    //! Vars temporales para evaluar victoria o perdida
        int player_pcounter =  0;
        int dealer_pcounter =  0;
        bool result_achieved = false;
        int card_auxiliary_counter = 3;
    //! Bloque de codigo que se encarga del juego y los casos
        do
        {
            std::cout << "1. Hit (Soliticar otra carta)\n2. Stand (Contabilizar cartas hasta el momento)\nSu eleccion es: ";
            std::cin >> seleccion_del_menu;
            switch (seleccion_del_menu)
            {
                case 1:
                {
                    std::cout << std::setw(57) << std::setfill('=') <<"" << std::endl;
                    std::cout << std::setw(46) << std::setfill('=') << "|Incrementando una carta al usuario|" << std::setw(11) << std::setfill('=') <<  "" <<std::endl;
                    //? Mismo proceso para anadir la tarjeta al usuario
                    auto card_helper = Logica_placeholder.select_a_card();
                    Player_placeholder.anadir_tarjeta_al_usr(card_helper.Card_Name);
                    Player_placeholder.aumentar_cantidad_puntos_usr(card_helper.Card_Value);
                    Player_placeholder.imprimir_tarjetas_del_usr(card_auxiliary_counter +1);
                    card_auxiliary_counter += 1;
                    Dealer_placeholder.tomar_cartas_hasta_puntos_mejor_17();
                    //! Check para ver is la cantidad de puntos del usuario luego de anadir la tarjeta no sobrepasa 21
                        //! Variables auxiliares para counters de puntos
                        player_pcounter =  Player_placeholder.get_cantidad_puntos();
                        dealer_pcounter =  Dealer_placeholder.get_cantidad_puntos();
                        if (player_pcounter > 21 || dealer_pcounter > 21) 
                        {
                            std::cout << std::setw(45) << std::setfill('=') << "|La puntuacion cruzo los 21 puntos|" << std::setw(12) << std::setfill('=') <<"" <<std::endl; 
                            std::cout << std::setw(41) << std::setfill('=') << "|Se pierde por default :C|" << std::setw(16) << std::setfill('=') << "" << std::endl;
                            if (player_pcounter > 21)
                            {
                                std::cout << std::setw(48) << std::setfill('=') << "|Jugador 1 ha perdido la partida :C|" << std::setw(9) << std::setfill('=') <<  "" <<std::endl;
                                std::cout << "Puntos Jugador : " << Player_placeholder.get_cantidad_puntos() << std::endl;
                                Player_placeholder.aumentar_cantidad_perdida_usr(auxiliar_cantidad_apuesta);
                                result_achieved = true;
                                break;
                            }
                            else if (dealer_pcounter > 21)
                            {
                                std::cout << std::setw(45) << std::setfill('=') << "|Dealer ha perdido la partida :D|" << std::setw(12) << std::setfill('=') <<  "" <<std::endl;
                                //! Impresion de Lineas para el Jugador y el Dealer
                                std::cout << "Puntos Dealer : " << Dealer_placeholder.get_cantidad_puntos() << std::endl;
                                result_achieved = true;
                                break;
                            }
                        }
                        else {break;}
                }
                case 2: 
                {
                    //! Check para ver is la cantidad de puntos del usuario luego de anadir la tarjeta no sobrepasa 21
                    //! Variables auxiliares para counters de puntos
                    player_pcounter =  Player_placeholder.get_cantidad_puntos();
                    dealer_pcounter =  Dealer_placeholder.get_cantidad_puntos();
                    std::cout << std::setw(57) << std::setfill('=') <<"" << std::endl;
                    std::cout << std::setw(51) << std::setfill('=') << "|Contabilizando las cartas hasta este momento|" << std::setw(6) << std::setfill('=') <<  "" <<std::endl;
                    if (player_pcounter > 21 || dealer_pcounter > 21) 
                    {
                        std::cout << std::setw(45) << std::setfill('=') << "|La puntuacion cruzo los 21 puntos|" << std::setw(12) << std::setfill('=') <<"" <<std::endl; 
                        std::cout << std::setw(41) << std::setfill('=') << "|Se pierde por default :C|" << std::setw(16) << std::setfill('=') << "" << std::endl;
                        if (player_pcounter > 21)
                        {
                            std::cout << std::setw(48) << std::setfill('=') << "|Jugador 1 ha perdido la partida :C|" << std::setw(9) << std::setfill('=') <<  "" <<std::endl;
                            //! Impresion de Lineas para el Jugador y el Dealer
                            std::cout << "Puntos Jugador : " << Player_placeholder.get_cantidad_puntos() << std::endl;
                            Player_placeholder.aumentar_cantidad_perdida_usr(auxiliar_cantidad_apuesta);
                            result_achieved = true;
                            break;
                        }
                        else if (dealer_pcounter > 21)
                        {
                            std::cout << std::setw(45) << std::setfill('=') << "|Dealer ha perdido la partida :D|" << std::setw(12) << std::setfill('=') <<  "" <<std::endl;
                            //! Impresion de Lineas para el Jugador y el Dealer
                            std::cout << "Puntos Dealer : " << Dealer_placeholder.get_cantidad_puntos() << std::endl;
                            result_achieved = true;
                            break;
                        }
                    }
                    else if (player_pcounter <=21 && dealer_pcounter <= 21)
                    {
                        //! If compuesto para casos especificos de victorias
                        if (player_pcounter == 21)
                        {
                            std::cout << std::setw(52) << std::setfill('=') << "|Jugador 1 ha ganado la partida, felicitaciones!|" << std::setw(5) << std::setfill('=') <<  "" <<std::endl;
                            //! Impresion de Lineas para el Jugador y el Dealer
                            std::cout << "Puntos Jugador : " << Player_placeholder.get_cantidad_puntos() << std::endl;
                            std::cout << "Puntos Dealer : " << Dealer_placeholder.get_cantidad_puntos() << std::endl;
                            Player_placeholder.aumentar_cantidad_ganada_usr(auxiliar_cantidad_apuesta);
                            Player_placeholder.aumentar_cantidad_victorias_usr(1);
                            result_achieved = true;
                            break;
                        }
                        else if (dealer_pcounter == 21)
                        {
                            std::cout << std::setw(52) << std::setfill('=') << "|Dealer ha ganado la partida, suerte la proxima!|" << std::setw(5) << std::setfill('=') <<  "" <<std::endl;
                            //! Impresion de Lineas para el Jugador y el Dealer
                            std::cout << "Puntos Jugador : " << Player_placeholder.get_cantidad_puntos() << std::endl;
                            std::cout << "Puntos Dealer : " << Dealer_placeholder.get_cantidad_puntos() << std::endl;
                            Player_placeholder.aumentar_cantidad_perdida_usr(auxiliar_cantidad_apuesta);
                            Dealer_placeholder.aumentar_cantidad_victorias_usr(1);
                            result_achieved = true;
                            break;
                        }
                        else if (player_pcounter == dealer_pcounter)
                        {
                            std::cout << std::setw(45) << std::setfill('=') << "|Tablas! Nadie tuvo mayor puntaje|" << std::setw(12) << std::setfill('=') <<  "" <<std::endl;
                            //! Impresion de Lineas para el Jugador y el Dealer
                            std::cout << "Puntos Jugador : " << Player_placeholder.get_cantidad_puntos() << std::endl;
                            std::cout << "Puntos Dealer : " << Dealer_placeholder.get_cantidad_puntos() << std::endl;
                            result_achieved = true;
                            break;
                        }
                        else if (player_pcounter > dealer_pcounter)
                        {
                            std::cout << std::setw(52) << std::setfill('=') << "|Jugador 1 ha ganado la partida, felicitaciones!|" << std::setw(5) << std::setfill('=') <<  "" <<std::endl;
                            //! Impresion de Lineas para el Jugador y el Dealer
                            std::cout << "Puntos Jugador : " << Player_placeholder.get_cantidad_puntos() << std::endl;
                            std::cout << "Puntos Dealer : " << Dealer_placeholder.get_cantidad_puntos() << std::endl;
                            Player_placeholder.aumentar_cantidad_ganada_usr(auxiliar_cantidad_apuesta);
                            Player_placeholder.aumentar_cantidad_victorias_usr(1);
                            result_achieved = true;
                            break;
                        }
                        else if (player_pcounter < dealer_pcounter)
                        {
                            std::cout << std::setw(52) << std::setfill('=') << "|Dealer ha ganado la partida, suerte la proxima!|" << std::setw(5) << std::setfill('=') <<  "" <<std::endl;
                            //! Impresion de Lineas para el Jugador y el Dealer
                            //! Impresion de Lineas para el Jugador y el Dealer
                            std::cout << "Puntos Jugador : " << Player_placeholder.get_cantidad_puntos() << std::endl;
                            std::cout << "Puntos Dealer : " << Dealer_placeholder.get_cantidad_puntos() << std::endl;
                            Player_placeholder.aumentar_cantidad_perdida_usr(auxiliar_cantidad_apuesta);
                            Dealer_placeholder.aumentar_cantidad_victorias_usr(1);
                            result_achieved = true;
                            break;
                        }
                    }

                }
                default:
                {
                    std::cout << std::setw(55) << std::setfill('=') << "|Su seleccion no se encuentra en el menu presentado|" << std::setw(2)  << "" << std::setfill('=') << std::endl; 
                    std::cout << "Solucion: Favor Cerciorarse de que la opcion que elige\neste en un rango de 1 a 2.\n\nGracias! :D"<< std::endl;
                    std::cout << std::endl;
                    continue;
                }

            }
        }
        while (result_achieved == false);

        //! Reset the las cartas al ganar y reshuffle de las cartas 
            Logica_placeholder.shuffle_cards_randomly();
            Player_placeholder.reset_cartas_y_puntos_del_usr();
            Dealer_placeholder.reset_cartas_y_puntos_del_usr();
            card_auxiliary_counter = 3;
}   


void PF_Func_Revisar_sus_Estadisticas(Base_Player& Player_placeholder, Dealer_Class& Dealer_placeholder)
{
    //! Impresion de header de seccion 
        std::cout << std::setw(57) << std::setfill('=') << "" << std::endl;
        std::cout << std::setw(42) << std::setfill('=') << "|Revisando sus estadisticas|" << std::setw(15) << std::setfill('=') << "" << std::endl;
        std::cout << std::endl;

    //! Cuerpo de la Impresion de los Datos
        std::cout << std::setw(57) << std::setfill('=') << "" << std::endl;

        std::cout << "Jugador 1 : " << Player_placeholder.get_nombre_usuario() << " " << Player_placeholder.get_apellido_usuario() << std::endl;
        std::cout << std::setw(43) << std::setfill('=') << "|Estas son sus estadisticas|"  << std::setw(14) << std::setfill('=') << "" << std::endl;
        std::cout << "Cantidad de Victorias : " << Player_placeholder.get_cantidad_victorias() << std::endl;
        std::cout << "Dinero Ganado: $" <<Player_placeholder.get_cantidad_ganada() << std::endl;
        std::cout << "Dinero Perdido: $" << Player_placeholder.get_cantidad_perdida() << std::endl;
    //! Impresion de un grafico de barras en donde cada 25 dolares es una estrella
        std::cout << std::setw(43) << std::setfill('=') << "|Grafico de Barras con los datos|" << std::setw(14) << std::setfill('=') << "" << std::endl;

    //! Determinacion de cantidad de estrellas y division hecha por estrella
        std::string nota_ganancias = {"\b"};
        std::string nota_perdidas = {"\b"};
        auto max_amount_cols_won = 0; //Valor para hacer grafico en vertical
        auto max_amount_cols_lost = 0; //Valor para hacer grafico en vertical
        const int  max_amount_rows = 2; //Valor para distribuir grafico en horizontal
        auto cantidad_ganada_usr = std::ceil(Player_placeholder.get_cantidad_ganada());
        auto cantidad_perdida_usr = std::ceil(Player_placeholder.get_cantidad_perdida());
        int amount_division = {0};
    
    //! If prinicipal para la impresion de las ganancias
        if (cantidad_ganada_usr > 0 && cantidad_ganada_usr < 1000)
        {
            amount_division = 100;
            max_amount_cols_won = cantidad_ganada_usr / amount_division;
            nota_ganancias = "Nota: Cada estrella simboliza " + std::to_string(amount_division) + " dolares";
        }
        else if (cantidad_ganada_usr >= 1000 && cantidad_ganada_usr < 5000) 
        {
            amount_division = 500;
            max_amount_cols_won = cantidad_ganada_usr / amount_division;
            nota_ganancias = "Nota: Cada estrella simboliza " + std::to_string(amount_division) + " dolares";
        }
        else if (cantidad_ganada_usr >= 5000 && cantidad_ganada_usr < 10000) 
        {
            amount_division = 1000;
            max_amount_cols_won = cantidad_ganada_usr / amount_division;
            nota_ganancias = "Nota: Cada estrella simboliza " + std::to_string(amount_division) + " dolares";
        }
        else if (cantidad_ganada_usr >= 10000 && cantidad_ganada_usr < 50000) 
        {
            amount_division = 5000;
            max_amount_cols_won = cantidad_ganada_usr / amount_division;
            nota_ganancias = "Nota: Cada estrella simboliza " + std::to_string(amount_division) + " dolares";
        }
        else if (cantidad_ganada_usr >= 50000 ) 
        {
            amount_division = 10000;
            max_amount_cols_won = cantidad_ganada_usr / amount_division;
            nota_ganancias = "Nota: Cada estrella simboliza " + std::to_string(amount_division) + " dolares";
        }

    //! If Secundario para la impresion de perdidas
        if (cantidad_perdida_usr > 0 && cantidad_perdida_usr < 1000)
        {
            amount_division = 100;
            max_amount_cols_lost = cantidad_perdida_usr / amount_division;
            nota_perdidas = "Nota: Cada estrella simboliza " + std::to_string(amount_division) + " dolares";
        }
        else if (cantidad_perdida_usr >= 1000 && cantidad_perdida_usr < 5000) 
        {
            amount_division = 500;
            max_amount_cols_lost = cantidad_perdida_usr / amount_division;
            nota_perdidas = "Nota: Cada estrella simboliza " + std::to_string(amount_division) + " dolares";
        }
        else if (cantidad_perdida_usr >= 5000 && cantidad_perdida_usr < 10000) 
        {
            amount_division = 1000;
            max_amount_cols_lost = cantidad_perdida_usr / amount_division;
            nota_perdidas = "Nota: Cada estrella simboliza " + std::to_string(amount_division) + " dolares";
        }
        else if (cantidad_perdida_usr >= 10000 && cantidad_perdida_usr < 50000) 
        {
            amount_division = 5000;
            max_amount_cols_lost = cantidad_perdida_usr / amount_division;
            nota_perdidas = "Nota: Cada estrella simboliza " + std::to_string(amount_division) + " dolares";
        }
        else if (cantidad_perdida_usr >= 50000 ) 
        {
            amount_division = 10000;
            max_amount_cols_lost = cantidad_perdida_usr / amount_division;
            nota_perdidas = "Nota: Cada estrella simboliza " + std::to_string(amount_division) + " dolares";
        }

    //! Impresion del mensaje y las columnas
    
    for (std::size_t row = 1; row <= max_amount_rows; row +=1)
    {
        switch(row)
        {
            case 1:
            {
                if (nota_ganancias == "\b" || max_amount_cols_won == 0) {std::cout << "Cantidad de Dinero Muy pequena o cero" <<std::endl;}
                else {std::cout << nota_ganancias << std::endl;}
                std::cout  << std::setw(20) << std::setfill(' ') << "|Dinero Ganado $|";
                for (std::size_t col = 0; col < max_amount_cols_won; col +=1)
                {           
                    std::cout << "* ";       
                }           
                std::cout << std::endl;
                break;
            }
            case 2:
            {
                if (nota_perdidas == "\b" || max_amount_cols_lost == 0) {std::cout << "Cantidad de Dinero Muy pequena o cero" <<std::endl;}
                else {std::cout << nota_perdidas << std::endl;}
                std::cout << std::setw(20) << std::setfill(' ')<< "|Dinero Perdidas $|";
                for (std::size_t col = 0; col < max_amount_cols_lost; col +=1)
                {
                    std::cout << "* ";   
                }
                std::cout << std::endl;
                break;
            }
        }
    }

    //! Reset de variables para volver a imprimir de manera correcta
        amount_division = 0;
}

void PF_Func_Reiniciar_Scores(Base_Player& Player_placeholder, Dealer_Class& Dealer_placeholder, Logica_Basica& Logica_placeholder)
{
    //! Impresion de las acciones en orden que informe al usuario del proceso sin que tenga que intervenir
        std::cout << std::setw(57) << std::setfill('=') << "" << std::endl;
        std::cout << std::setw(39) << std::setfill('=') << "|Reiniciando Scores|" << std::setw(18) << std::setfill('=') << "" << std::endl;
    //! Funciones de reseteo al user y al dealer
        Player_placeholder.reset_cartas_y_puntos_del_usr();
        Player_placeholder.reset_cantidad_perdida_y_ganada_usr_y_puntos();
        Dealer_placeholder.reset_cartas_y_puntos_del_usr();
        Dealer_placeholder.reset_cantidad_perdida_y_ganada_usr_y_puntos();
        std::cout << std::setw(41) << std::setfill('=') << "|Mezclando las Tarjetas|" << std::setw(16) << std::setfill('=') << "" << std::endl;
    //! Funciones de reseteo a la logica del juego
        Logica_placeholder.shuffle_cards_randomly();
        Logica_placeholder.reset_already_played_cards();
        std::cout << std::setw(57) << std::setfill('=') << "" << std::endl;
        std::cout << std::setw(50) << std::setfill('=') << "|Reset terminado, listos para mas diversion!|" << std::setw(7) << std::setfill('=') << "" << std::endl;
}
    

    
