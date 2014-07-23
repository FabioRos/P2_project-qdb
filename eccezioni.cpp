#include <iostream>
#include "eccezioni.h"

Ecc_tolti_troppi::Ecc_tolti_troppi(){
    std::cerr<<"Stai cercando di togliere più elementi di quanti ne sono disponibili."<<std::endl;
}

Ecc_num_negativo_inaspettato::Ecc_num_negativo_inaspettato(){
    std::cerr<<"il valore richiesto deve essere maggiore o uguale a 0."<<std::endl;
}

Ecc_File_Non_Trovato::Ecc_File_Non_Trovato(){
    std::cerr<<"Non è stato possibile trovare il file richiesto.";
}

//Ecc_dereferenziazione_non_valida::Ecc_dereferenziazione_non_valida(){
//    std::cerr<<"Non  posibile dereferenziare questo puntatore";
//}
