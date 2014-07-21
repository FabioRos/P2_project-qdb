#include "negozio.h"
using namespace std;

/*

  E' una clase che mi serve per avere un controllo più customizzato del container
  riguardo alla classe Bicicletta offrendo funzionalità non generiche e quindo non
  comprendibili nel container.

*/

Negozio::Negozio(){}

void Negozio::inserisci_bicicletta(const Bicicletta& b){
            shop.aggiungiElemento(const_cast<Bicicletta*>(&b));
}



bool Negozio::isEmpty(){
    return shop.isEmpty();
}

void Negozio::rimuovi_bicicletta(const Bicicletta& b){
    shop.rimuoviElemento(const_cast<Bicicletta*>(&b));
}

void Negozio::modifica_bicicletta(const Bicicletta& b){
    modifica_bicicletta(b);
}

void Negozio::carica_dati(string str="") const throw(Ecc_File_Non_Trovato){
    if(str=="")throw(Ecc_File_Non_Trovato());

}

void Negozio::stampa() const{


    for (Container<Bicicletta*>::Iteratore it=shop.begin(); it != shop.end(); it++){
        //cout<<typename(this->shop[it]);
        (this->shop[it])->stampa();
        cout<<endl;
    }


}



void Negozio::salva_dati() const{
      ofstream myfile;
      myfile.open("example.txt");
      myfile << "Writing this to a file.\n";
      myfile << "Writing this to a file.\n";
      myfile << "Writing this to a file.\n";
      myfile << "Writing this to a file.\n";
      myfile.close();
}
