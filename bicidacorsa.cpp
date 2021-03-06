#include "bicidacorsa.h"

BiciDaCorsa::BiciDaCorsa(){
}
BiciDaCorsa::BiciDaCorsa(string marca_, string mod_, float lung_, float alt_, double prezzo, string s, string m, double p)
     : Bicicletta(marca_, mod_, lung_,alt_,prezzo),specialita(s),materiale(m),peso(p){

}

BiciDaCorsa::BiciDaCorsa(const Bicicletta& b, string s, string m, double p)
:Bicicletta(b),specialita(s),materiale(m),peso(p){}



string BiciDaCorsa::getSpecialita() const{
    return this->specialita;
}
string BiciDaCorsa::getMateriale() const{
    return this->materiale;
}
double BiciDaCorsa::getPeso() const{
    return this->peso;
}
void BiciDaCorsa::stampa() const{
    cout<< "Bicicletta da corsa"<<endl;
    this->Bicicletta::stampa();
    cout<<"Specialità: \t"<< getSpecialita()<<endl
        <<"Materiale: \t"<< getMateriale()<<endl
        <<"Peso: \t"<< getPeso()<<endl;
}
ostream& operator << (ostream& os, const BiciDaCorsa& b){
    b.stampa();
    return os;
}
bool BiciDaCorsa::operator==(const BiciDaCorsa& b) const{
    return (
                (b.getSpecialita()  ==this->getSpecialita())   &&
                (b.getMateriale()   ==this->getMateriale()) &&
                (b.getPeso()        ==this->getPeso())
            );
}
void BiciDaCorsa::setSpecialita(string s){
    specialita=s;
}
void BiciDaCorsa::setMateriale(string s){
    materiale=s;
}
void BiciDaCorsa::setPeso(double d){
    peso=d;
}

void BiciDaCorsa::modifica(const Bicicletta& b){
    Bicicletta::modifica(b);
    BiciDaCorsa* bc= dynamic_cast<BiciDaCorsa*>(const_cast<Bicicletta*>(&b));
    if(bc!=0){
      specialita=bc->specialita;
      materiale=bc->materiale;
      peso=bc->peso;
    }
}

