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

Container<Bicicletta*> Negozio::getAll() const{
    return shop;
}

Container<Bicicletta *> Negozio::ricerca_bicicletta(string tipo, string testo){
    Container<Bicicletta*> aux;
    if(tipo=="Bici da corsa"){
        for(Container<Bicicletta*>::Iteratore it=shop.begin();it!=shop.end();++it){
            if(dynamic_cast<BiciDaCorsa*>(*it) && (*it)->getMarca()==testo ||(*it)->getModello()==testo ){
                aux.aggiungiElemento(*it);
            }
        }
    }else if(tipo=="Bici Comuni"){
        for(Container<Bicicletta*>::Iteratore it=shop.begin();it!=shop.end();++it){
            if(dynamic_cast<BiciComuni*>(*it) && (*it)->getMarca()==testo ||(*it)->getModello()==testo ){
                aux.aggiungiElemento(*it);
            }
        }
    }else {
        for(Container<Bicicletta*>::Iteratore it=shop.begin();it!=shop.end();++it){
            if((*it)->getMarca()==testo ||(*it)->getModello()==testo ){
                aux.aggiungiElemento(*it);
            }
        }
    }

    return aux;
}





