#include "bicicletta.h"
#include "container.h"

Bicicletta::Bicicletta():marca("white_label"),modello("sconosciuto"), lunghezza(-1), altezza(-1), quantita(1), prezzo(0){}
Bicicletta::Bicicletta(string ma, string mo, float l, float a, int q=1, double p=-1):
    marca(ma),modello(mo),lunghezza(l),altezza(a),quantita(q),prezzo(p){}

Bicicletta::Bicicletta(const Bicicletta& b){
    marca=b.marca;
    modello=b.modello;
    lunghezza=b.lunghezza;
    quantita=b.quantita;
    prezzo=b.prezzo;


}
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


string Bicicletta::serializza() const{
    //guarda se si riesce a fare con  il to_string .......

    std::ostringstream l,a,q,p;
    l << lunghezza;
    a << altezza;
    q << quantita;
    p << prezzo;
    string Str_lunghezza = l.str();
    string Str_altezza = a.str();
    string Str_quantita = q.str();
    string Str_prezzo = p.str();
    string s="[Bicicletta]:"+marca+":"+modello+":"+Str_lunghezza+":"+Str_altezza+":"+Str_quantita+":"+Str_prezzo+"\n";
    return s;
}


Bicicletta* Bicicletta::parse(string riga) const{//da controllare

    string array_temp[6];

    int pos = 0,i=0;
    std::string token;
    while (((pos = riga.find(':')) != std::string::npos)&&(i!=6)) {   //npos~= -1 -> significa che il find è fallito
        i=i+1;
        token = riga.substr(0, pos);
        array_temp[i] = token;
        riga.erase(0, pos + 1);
    }

    float lunghezza;
    stringstream convertLunghezza(array_temp[2]);
    if ( !(convertLunghezza >> lunghezza) )
        lunghezza=0;

    float altezza;
    stringstream convertAltezza(array_temp[3]);
    if ( !(convertAltezza >> altezza) )
        altezza=0;

    int quantita;
    stringstream convertQuantita(array_temp[4]);
    if ( !(convertQuantita >> quantita) )
        quantita=0;

    double prezzo;
    stringstream convertPrezzo(array_temp[5]);
    if ( !(convertPrezzo >> prezzo) )
        prezzo=0;

     array_temp[5] = riga; //siccome ogni volta tolgo il pezzo che ho preso, stampo quello finale.
     return new Bicicletta(array_temp[0],array_temp[1],lunghezza,altezza,quantita,prezzo);

}

