#ifndef BICICOMUNI_H
#define BICICOMUNI_H

#include <iostream>
#include "bicicletta.h"

using namespace std;

class BiciComuni : public Bicicletta
{
public:
    BiciComuni();
    BiciComuni(const Bicicletta&,bool,bool,bool,bool,bool);
    bool getCestino ()      const;
    bool getSeggiolino ()   const;
    bool getPortapacchi ()  const;
    bool getCopricatena ()  const;
    bool getFanale ()       const;

    void setCestino     (bool);
    void setSeggiolino  (bool);
    void setPortapacchi (bool);
    void setCopricatena (bool);
    void setFanale      (bool);
    void stampa()       const;
    void modifica(const Bicicletta&);
    string serializza() const;
    static BiciComuni* parse(const string&);
private:
    bool cestino;
    bool seggiolino;
    bool portapacchi;
    bool copricatena;
    bool fanale;
};



#endif // BICICOMUNI_H
