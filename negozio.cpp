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
    else{
        ifstream input_file(NOME_FILE);
        while(!input_file.eof()){
            //... chiama i parser
        }
    }

}

void Negozio::stampa() const{


    for (Container<Bicicletta*>::Iteratore it=shop.begin(); it != shop.end(); it++){
        //cout<<typename(this->shop[it]);
        (this->shop[it])->stampa();
        cout<<endl;
    }


}

// r_w

void Negozio::salva_dati(){ //ok
    ofstream stream_di_output_su_file;
    stream_di_output_su_file.open(NOME_FILE);
    for(Container<Bicicletta*>::Iteratore it=shop.begin(); it != shop.end(); it++)
        stream_di_output_su_file<<shop[it]->serializza();
    stream_di_output_su_file.close();
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






