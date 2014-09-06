#include "negozio.h"
#define EMPTY_PLACEHOLDER "@_vuoto" //"@_vuoto" è un testo che prendo come convenzione

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



bool Negozio::isEmpty() const{
    return shop.isEmpty();
}

void Negozio::rimuovi_bicicletta(const Bicicletta& b){
    shop.rimuoviElemento(const_cast<Bicicletta*>(&b));
}

void Negozio::modifica_bicicletta(const Bicicletta& b){
    modifica_bicicletta(b);
}

Bicicletta* Negozio::getBicicletta(int n) const {
    Bicicletta* tmp = 0;
    if (n!=0){
        for(Container<Bicicletta*>::Iteratore it = shop.begin(); it != shop.end() && n>1; --n, ++it){
            tmp = *it;
        }
    }
    return tmp;
}

ostream& operator<< (ostream& os, const Negozio& n){
    n.stampa();
    return os;
}

void Negozio::stampa() const{


    for (Container<Bicicletta*>::Iteratore it=shop.begin(); it != shop.end(); it++){
        //cout<<typename(this->shop[it]);
        (this->shop[it])->stampa();
        cout<<endl;
    }


}
Container<Bicicletta*> Negozio::cerca_bicicletta(const Bicicletta& item) const{
    Container<Bicicletta*> db_temporaneo_risultati;
    for(Container<Bicicletta*>::Iteratore it=shop.begin(); it != shop.end(); it++){
        if(*(this->shop[it])==item)
            db_temporaneo_risultati.aggiungiElemento(shop[it]);
    }
    return db_temporaneo_risultati;
}

//string Negozio::getLineByFile(string s, int offset) const{ //da finire
//    string riga=EMPTY_PLACEHOLDER;
//    ifstream infile(NOME_FILE);
//    for(int i=0;i<=offset;i++)
//        getline (infile,riga);
//    return riga;
//}

//string OttieniToken(string s) {
//    int i=s.size();
//    if( i==0)
//        return EMPTY_PLACEHOLDER;
//    else{
//        string aux="";
//        for(;i<s.length() && s[i]!=':' && s[i]!='\n';++i){
//            aux=aux+s[i];
//        }
//        return aux;
//    }
//}

Container<Bicicletta*> Negozio::getAll() const{
    return shop;
}





