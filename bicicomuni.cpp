#include "bicicomuni.h"

BiciComuni::BiciComuni():cestino(0),seggiolino(0),portapacchi(0),copricatena(0),fanale(0){}
BiciComuni::BiciComuni(const Bicicletta& b,bool c,bool s,bool p,bool cc,bool f):Bicicletta(b),cestino(c),seggiolino(s),portapacchi(p),
    copricatena(cc),fanale(f){}

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

string BiciComuni::serializza() const{
    std::ostringstream ce,se,p,co,f;
    ce << cestino;
    se << seggiolino;
    p << portapacchi;
    co << copricatena;
    f << fanale;
    string Str_cestino = ce.str();
    string Str_seggiolino = se.str();
    string Str_portapacchi = p.str();
    string Str_copricatena = co.str();
    string Str_fanale = f.str();
    string biciBase=Bicicletta::serializza();
    biciBase=biciBase.substr(0,biciBase.length()-1);
    string s="[BiciComuni]:"+biciBase+":"+Str_cestino+":"+Str_seggiolino+":"+Str_portapacchi+":"+Str_copricatena+":"+Str_fanale+"\n";
    return s;

}

BiciComuni* BiciComuni::parse(const string& riga) {//da controllare
   //tolgo "[Bicicletta]:"
    string & rigac=const_cast<string&>(riga);
    int pos = rigac.find(':');
    rigac.erase(0, pos+1);
    cout<<rigac<<endl;

    Bicicletta* b= Bicicletta::parse(rigac);
    //occhio che ora la stringa inizia con un carattere ':' !!
    b->stampa();

    string array_temp[5];
    pos = 0;
    int i=0;
    std::string token;
    pos = rigac.find(':');

    while ((pos = rigac.find(':')) != std::string::npos) {   //npos~= -1 -> significa che il find(':') è fallito
        token = rigac.substr(0, pos);

        cout<<'T'<<i<<' '<<token<<"riga rimanente ->  "<<rigac<<endl;

        array_temp[i] = token;
        rigac.erase(0, pos+1);
        i=i+1;
        pos = rigac.find(':');
    }
    array_temp[4] = riga; //siccome ogni volta tolgo il pezzo che ho preso, stampo quello finale.
    bool cestino;
    bool seggiolino;
    bool portapacchi;
    bool copricatena;
    bool fanale;
    stringstream conv_cestino(array_temp[0]);
    if ( !(conv_cestino >> cestino) )
        cestino=0;
    stringstream conv_seggiolino(array_temp[1]);
    if ( !(conv_seggiolino >> seggiolino) )
        seggiolino=0;
    stringstream conv_portapacchi(array_temp[2]);
    if ( !(conv_portapacchi >> portapacchi) )
        portapacchi=0;
    stringstream conv_copricatena(array_temp[3]);
    if ( !(conv_copricatena >> copricatena) )
        copricatena=0;
    stringstream conv_fanale(array_temp[4]);
    if ( !(conv_fanale >> fanale) )
        fanale=0;

//    BiciComuni test(b,cestino,seggiolino,portapacchi,copricatena,fanale);
//    test.stampa();

    cout<<"ok";

   // return new BiciComuni(*b,cestino,seggiolino,portapacchi,copricatena,fanale);

    BiciComuni* bc= new BiciComuni(*b,cestino,seggiolino,portapacchi,copricatena,fanale);
    bc->stampa();
    return bc;

}
