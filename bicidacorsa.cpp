#include "bicidacorsa.h"

BiciDaCorsa::BiciDaCorsa(){
}
BiciDaCorsa::BiciDaCorsa(const Bicicletta &b,string s,string m,double p):Bicicletta(b),specialita(s),materiale(m),peso(p){}
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

string BiciDaCorsa::serializza() const{

    std::ostringstream p;
    p << peso;
    string Str_peso = p.str();
    string biciBase=Bicicletta::serializza();
    biciBase=biciBase.substr(0,biciBase.length()-1);    //tolgo il \n
    string s="[BiciDaCorsa]:"+biciBase+":"+specialita+":"+materiale+":"+Str_peso+"\n";
    return s;
}


Bicicletta* BiciDaCorsa::parse(string riga){//da controllare
    Bicicletta b( *(Bicicletta::parse(riga)));
    //occhio che qui dovrebbe esserci un carattere ':' all'inizio, occhio a non tirare su token vuoti.
    string array_temp[3];

    int pos = 0,i=0;
    std::string token;
    while ((pos = riga.find(':')) != std::string::npos) {   //npos~= -1 -> significa che il find è fallito
        i=i+1;
        token = riga.substr(0, pos);
        array_temp[i] = token;
        riga.erase(0, pos + 1);
    }

    double peso;
    stringstream convertPeso(array_temp[2]);
    if ( !(convertPeso >> peso) )
        peso=0;

     array_temp[5] = riga; //siccome ogni volta tolgo il pezzo che ho preso, stampo quello finale.
     return new BiciDaCorsa(b,array_temp[1],array_temp[2],peso);

}

