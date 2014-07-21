#include "bicidacorsa.h"

BiciDaCorsa::BiciDaCorsa(){
}
BiciDaCorsa::BiciDaCorsa(string s,string m,double p):specialita(s),materiale(m),peso(p){}
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
