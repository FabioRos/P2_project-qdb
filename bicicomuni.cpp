#include "bicicomuni.h"

BiciComuni::BiciComuni():cestino(0),seggiolino(0),portapacchi(0),copricatena(0),fanale(0){}
BiciComuni::BiciComuni(const Bicicletta& b,bool c,bool s,bool p,bool cc,bool f):Bicicletta(b),cestino(c),seggiolino(s),portapacchi(p),
    copricatena(cc),fanale(f){}
BiciComuni::BiciComuni(string marca_,string mod_,float lung_,float alt_,double prezzo_ ,bool ce_,bool s_,bool p_, bool c_,bool f_)
    :Bicicletta(marca_,mod_,lung_,alt_,prezzo_),cestino(ce_),seggiolino(s_),portapacchi(p_),copricatena(c_),fanale(f_){}
bool BiciComuni::getCestino() const{
    return cestino;
}
bool BiciComuni::getSeggiolino() const{
    return seggiolino;
}
bool BiciComuni::getPortapacchi() const{
    return portapacchi;
}
bool BiciComuni::getCopricatena() const{
    return copricatena;
}
bool BiciComuni::getFanale() const{
    return fanale;
}

void BiciComuni::setCestino(bool b){
    cestino=b;
}
void BiciComuni::setSeggiolino(bool b){
    seggiolino=b;
}
void BiciComuni::setPortapacchi(bool b){
    portapacchi=b;
}
void BiciComuni::setCopricatena(bool b){
    copricatena=b;
}
void BiciComuni::setFanale(bool b){
    fanale=b;
}
ostream& operator << (ostream& os, const BiciComuni& b){
    b.stampa();
    return os;
}
void BiciComuni::stampa() const{
    cout<<"Bicicletta comune"<<endl;
    this->Bicicletta::stampa();
    if(!cestino && !seggiolino && !portapacchi && !copricatena && !fanale)
        return;
    else{
        cout<<"equipaggiamento:\n";
        if(getCestino())    cout<<"-cestino \n"     ;
        if(getSeggiolino()) cout<<"-seggiolino \n"  ;
        if(getPortapacchi())cout<<"-portapacchi \n" ;
        if(getCopricatena())cout<<"-copricatena \n" ;
        if(getFanale())     cout<<"-fanale \n"      ;
    }
}

void BiciComuni::modifica(const Bicicletta& b){
    Bicicletta::modifica(b);
    BiciComuni* bc= dynamic_cast<BiciComuni*>(const_cast<Bicicletta*>(&b));
    if(bc!=0){
        cestino=bc->cestino;
        seggiolino=bc->seggiolino;
        portapacchi=bc->portapacchi;
        copricatena=bc->copricatena;
        fanale=bc->fanale;
    }
}
