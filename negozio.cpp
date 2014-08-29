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

void Negozio::carica_dati(const char* str="") throw(Ecc_File_Non_Trovato){ //PROBLEMATICA
    if(!str)throw(Ecc_File_Non_Trovato());
    else{

        ifstream input_file;
        input_file.open(NOME_FILE);
        //1. prendo la riga
        string riga = "";
        int indice_delimiter=0;
        int indice_fine_riga=riga.find('\n');
        while (!input_file.eof())
        {
            getline(input_file, riga);
            indice_delimiter=riga.find(':');
            if(indice_delimiter==std::string::npos)
                indice_delimiter=indice_fine_riga;

            //2. estrapolo [tipo]

            string tipo=riga.substr(0,riga.find(':'));  //ritorna il primo token prima dei ':'
            if(tipo=="[Bicicletta]"){


                Bicicletta* b_=Bicicletta::parse(riga);
                //inserisci_bicicletta(Bicicletta::parse(riga));
                // cout<<" tipo: <<Bicicletta>> \n";
                // //riga.erase(0, indice_delimiter + 1);//rimuovo il token del tipo per avere la riga pulita

            }
           if(tipo=="[BiciComuni]"){
               cout<<"Riga_negozio: "<<riga<<"END"<<endl;
               BiciComuni* bici_da_inserire=BiciComuni::parse(riga);
               /* const_cast<Negozio*>(this)->inserisci_bicicletta(bici_da_inserire);
                cout<<" tipo: <<[BiciComuni]>> \n";

                riga.erase(0, indice_delimiter + 1);
                riga.erase(0, riga.find(':') + 1);    //devo togliere anche il tipo del sottooggetto bicicletta
            */}

        /*    if(tipo=="[BiciDaCorsa]"){
//                BiciDaCorsa bici_da_inserire=*(const_cast<Bicicletta*>(Bicicletta::parse(riga)));
//                const_cast<Negozio*>(this)->inserisci_bicicletta(bici_da_inserire);
//                cout<<" tipo: <<[BiciDaCorsa]>> \n";

                riga.erase(0, indice_delimiter + 1);
                riga.erase(0, riga.find(':') + 1);
            }

*/


        }

        input_file.close();













        // string tipo=riga.substr(0, pos = riga.find(':'));

        //3.mando la stringa senza quel pezzo dal parser giusto





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






