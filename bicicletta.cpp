#include "bicicletta.h"

Bicicletta::Bicicletta():marca("white_label"),modello("sconosciuto"), lunghezza(-1), altezza(-1), quantita(1), prezzo(0){}
Bicicletta::Bicicletta(string ma, string mo, float l, float a, int q=1, double p=-1):
    marca(ma),modello(mo),lunghezza(l),altezza(a),quantita(q),prezzo(p){}

Bicicletta::~Bicicletta(){}

ostream& operator << (ostream& os, const Bicicletta& b){
    b.stampa();
    return os;
}
void Bicicletta::stampa() const{
    cout<<"Marca: \t"<< getMarca()<<endl
       <<"Modello: \t"<< getModello()<<endl
      <<"lunghezza: \t"<< getLunghezza()<<endl
     <<"Altezza: \t"<< getAltezza()<<endl
    <<"Quantità: \t"<< getQuantita()<<endl;
}

string Bicicletta::getMarca() const throw(){
    return this->marca;
}
string Bicicletta::getModello() const throw() {
    return this->modello;
}
float Bicicletta::getLunghezza() const  throw(){
    return this->lunghezza;
}
float Bicicletta::getAltezza() const throw(){
    return this->altezza;
}

double Bicicletta::getPrezzo() const throw(){
    return this->prezzo;
}
int Bicicletta::getQuantita() const throw(){
    return this->quantita;
}

void Bicicletta::setMarca(string s){
    marca= s;
}
void Bicicletta::setModello(string s){
    modello= s;
}
void Bicicletta::setLunghezza(float f){
    lunghezza= f;
}
void Bicicletta::setAltezza(float f){
    altezza= f;
}
void Bicicletta::setPrezzo(double p)throw(Ecc_num_negativo_inaspettato){
    (prezzo>=0)?prezzo = p:throw Ecc_num_negativo_inaspettato();
}
bool Bicicletta::operator==(const Bicicletta& b) const{
    return (
                (b.getAltezza()     ==this->getAltezza())   &&
                (b.getLunghezza()   ==this->getLunghezza()) &&
                (b.getMarca()       ==this->getMarca())     &&
                (b.getModello()     ==this->getModello())   &&
                (b.getPrezzo()       ==this->getPrezzo())
                //la quantità non la considero
                );
}

void Bicicletta::aggiungi(int quanti)throw(Ecc_num_negativo_inaspettato){
    (quanti>0)?quantita+=quanti:throw Ecc_num_negativo_inaspettato();
}

void Bicicletta::togli(int quanti)throw(Ecc_num_negativo_inaspettato,Ecc_tolti_troppi){
    if (quanti < 0) throw Ecc_num_negativo_inaspettato();
    if (quanti > quantita) throw Ecc_tolti_troppi();
    else
        quantita-=quanti;
}

void Bicicletta::modifica(string ma, string mo, float l, float a, int q, double p){
    marca=ma;
    modello=mo;
    lunghezza=l;
    altezza=a;
    prezzo=p;
}
void Bicicletta::modifica(const Bicicletta& b){
    marca=b.marca;
    modello=b.modello;
    lunghezza=b.lunghezza;
    altezza=b.altezza;
    prezzo=b.prezzo;
}


