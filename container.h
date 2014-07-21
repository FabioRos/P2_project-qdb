#ifndef CONTAINER_H
#define CONTAINER_H

/************************************************************************************
 *                                                                                  *
 *                                  DEFINIZIONE                                     *
 *                                                                                  *
 * *********************************************************************************/

template <class T>

class Container
{friend class Iteratore;
private:
    class Nodo; //dichiarazione incompleta perchè serve a SmartP

    class SmartP{
    public:
        Nodo* punt;
        SmartP(Nodo* p=0);
        SmartP(const SmartP&);  //dichiaro il costruttore di copia per il ref count
        ~SmartP();

        SmartP& operator=(const SmartP&);
        Nodo& operator*() const;
        Nodo* operator->() const;
        bool operator==(const SmartP&)const;
        bool operator!=(const SmartP&)const;
        SmartP& operator++();
    };//SMARTP END

    class Nodo{
    public:         //tutto public ma sono in una classe privata, ok
        Nodo();
        Nodo(const T& elemento, const SmartP& n= 0);
        T info;
        SmartP next;
        int riferimenti;
    };//NODO END

    SmartP first;   //primo elemento della lista
//parte pubblica
public:
    Container();
    Container(const SmartP& smp);
    bool isEmpty() const;
    T aggiungiElemento(const T&);               //restituisco l'elemento
    bool rimuoviElemento(const T&);
    bool sostituisciElemento(const T&,const T&);
    //SmartP cercaElemento(const T&);               //restituisco il puntatore all'elemento
    void stampa() const;

    class Iteratore{
        friend class Container;
        private:
            SmartP punt;
        public:
            bool operator==(Iteratore);
            bool operator!=(Iteratore);
            Iteratore& operator++();    //prefisso
            Iteratore& operator++(int); //postfisso
            T& operator*();
    };//ITERATORE END
    Iteratore begin() const;
    Iteratore end() const;
    T& operator[](Iteratore) const;



};//CONTAINER END


/************************************************************************************
 *                                                                                  *
 *                              IMPLEMENTAZIONE                                     *
 *                                                                                  *
 * *********************************************************************************/

/************************************************************************************
 *                                   SmartP                                         *
 * *********************************************************************************/
template <class T>
Container<T>::SmartP::SmartP(Nodo *p):punt(p){
    if(punt)
        punt->riferimenti++;
}

template <class T>
Container<T>::SmartP::SmartP(const SmartP& ptr):punt(ptr.punt){
    if(punt)
        punt->riferimenti++;
}

template <class T>
Container<T>::SmartP::~SmartP(){
    if(punt){
        punt->riferimenti--;
        if( punt->riferimenti)
            delete punt;
    }
}

template <class T>
typename Container<T>::SmartP& Container<T>::SmartP::operator=(const Container<T>::SmartP& s){  //perchè ritorna uno SmartP
    if(this != &s){
        Nodo* t= punt;
        punt=s.punt;
        if(punt)
            punt->riferimenti++;
        if(t){
            t->riferimenti--;

            if(t->riferimenti == 0)
                delete t;       //delete standard di Nodo che richiama quelo ridefinito di SmartP
        }
    }
    return *this;
}
/*
*Quando ho il tipo di ritorno che dipande da T ci devo mettere il typename
*/
template <class T>
typename Container<T>::Nodo& Container<T>::SmartP::operator *()const{
    return *punt;
}

template <class T>
typename Container<T>::Nodo* Container<T>::SmartP::operator ->()const{
    return punt;
}

//bool operator==(const SmartP&)const;

template <class T>
bool Container<T>::SmartP::operator==(const SmartP& ptr)const{
    return punt==ptr.punt;
}

template <class T>
bool Container<T>::SmartP::operator!=(const SmartP& ptr)const{
    return punt!=ptr.punt;
}

template <class T>
typename Container<T>::SmartP& Container<T>::SmartP::operator++(){
    punt->riferimenti--;
    punt=punt->next;
    punt->riferimenti++;
}


/************************************************************************************
 *                                  Nodo                                            *
 ***********************************************************************************/
template <class T>
Container<T>::Nodo::Nodo():riferimenti(0){
    //info e next vengono cosruiti con i rispettivi costruttori di default
    //Container<T>::num++;
}
template <class T>
Container<T>::Nodo::Nodo(const T &elemento, const SmartP &n):riferimenti(0), info(elemento), next(n){
    //Container<T>::num++;
}

//template <class T>
//Container<T>::Nodo::~Nodo(){
//    Container::num--;
//    delete this;
//}

/************************************************************************************
 *                                  Container                                       *
 ***********************************************************************************/
template <class T>
bool Container<T>::isEmpty() const{
    return (first==0);
}


template <class T>
Container<T>::Container():first(0){}    //first ok per la conerversione da smartP

template <class T>
Container<T>::Container(const SmartP& smp):first(smp){}

template <class T>
T Container<T>::aggiungiElemento(const T& elemento){    //in testa
    SmartP aux(new Nodo(elemento,first));
    first=aux;
    return elemento;
}

template <class T>
bool Container<T>::rimuoviElemento(const T& elemento){ //rimuovo un elemento che mi viene passato
    SmartP p=first;
    SmartP prec=0;
    while (p!=0 && !(p->info==elemento)){
        prec=p;
        p=p->next;
    }
    if(p!=0){
        if(prec!=0)
            first=p->next;
        else
            prec->next=p->next;
            p->next=0;
            //p->riferimenti--;     lo fa il distruttore di smartP, perchè p è locale alla funzione
        return true;
    }
    return false;
}

template <class T>
bool Container<T>::sostituisciElemento(const T& _old,const T& _new){
    SmartP p=first;

    while (p && !(p->info==_old)){
        p=p->next;
    }
    if(p && (p->info==_old)){
        p->info=_new;
        return true;
    }
    return false;
}

/*
template <class T>
typename Container<T>::SmartP Container<T>::cercaElemento(const T& elemento){
    SmartP p=first;
    while (p!=0){
        if(p->info==elemento)
            return p;
        p=p->next;
        }
    return 0;
}
*/
template <class T>
void Container<T>::stampa() const{
    //da fares
}


/************************************************************************************
 *                                  Iteratore                                       *
 ***********************************************************************************/
template <class T>
bool Container<T>::Iteratore::operator==(Iteratore it){
    return *punt==it->punt; //dereferenzio così richiamo quello dei tipi contenuti
}

template <class T>
bool Container<T>::Iteratore::operator!=(Iteratore it){
    return punt!=it.punt;
}

template <class T>
typename Container<T>::Iteratore& Container<T>::Iteratore::operator++(){  //prefisso
    if(punt)
        punt++;
    return *this;
    //altrimenti non fa nulla ed è quello che voglio.
}

template <class T>
typename Container<T>::Iteratore& Container<T>::Iteratore::operator++(int){ //postfisso
    //faccio l'incremento sull'iteratore ma ritorno l'elemento iniziale
    Container<T>::Iteratore aux=*this;
    if(punt!=0)
        punt=punt->next;
    return aux;
}

template <class T>
T& Container<T>::Iteratore::operator*() {
    return punt->info;  // per amicizia
}

template <class T>
typename Container<T>::Iteratore Container<T>::begin() const{
    Container<T>::Iteratore aux;
    aux.punt=first;
    return aux;
}

template <class T>
typename Container<T>::Iteratore Container<T>::end() const{
    Container<T>::Iteratore aux;
    aux.punt=0;
    return aux;
}


template <class T>
T& Container<T>::operator[](Container<T>::Iteratore it) const{
    if(it.punt!=0)
        return (it.punt)->info;
    else
        std::cerr<<"Non  posibile dereferenziare questo puntatore";
}

//Iteratore: fine implementazione
#endif // CONTAINER_H
