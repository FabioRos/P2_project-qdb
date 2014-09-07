#include <iostream>
//#include "container.h"
#include "negozio.h"
#include "bicicletta.h"

#include <QApplication>
#include <QIcon>
#include "finestra_principale.h"



int main(int argc, char* argv[]){



    QApplication app(argc,argv);

    Negozio rivenditore;
    BiciDaCorsa *bcorsa=new BiciDaCorsa("Cannondale", "strada1",48,60,4500,"Strada","Carbonio",7.2);
    rivenditore.inserisci_bicicletta(*bcorsa);
    BiciDaCorsa *bcorsa2=new BiciDaCorsa("Pinarello", "Montello",55,62,7800,"Cronometro","Carbonio",6.8);
    rivenditore.inserisci_bicicletta(*bcorsa2);
    BiciComuni *bcomune=new BiciComuni("Bottecchia","astro",55,55,300,1,1,1,1,1);
    rivenditore.inserisci_bicicletta(*bcomune);
    BiciDaCorsa *bcorsa3=new BiciDaCorsa("Willier", "izoard",48,50,4500,"Strada","Carbonio",7.6);
    rivenditore.inserisci_bicicletta(*bcorsa3);
    BiciDaCorsa *bcorsa4=new BiciDaCorsa("Specialized", "special",58,65,5200,"Strada","Carbonio",7.4);
    rivenditore.inserisci_bicicletta(*bcorsa4);
    BiciDaCorsa *bcorsa5=new BiciDaCorsa("Colnago", "E-1",57,57,4200,"Strada","Carbonio",7.2);
    rivenditore.inserisci_bicicletta(*bcorsa5);

    BiciComuni *bcomune2=new BiciComuni("Bottecchia","stella",65,65,150,1,0,0,1,1);
    rivenditore.inserisci_bicicletta(*bcomune2);

    Finestra_Principale Pannello(rivenditore,0);

    Pannello.show();    //show() è virtuale di qWidget e implementato da qMainWindow
    QObject::connect(qApp,SIGNAL(lastWindowClosed()),qApp,SLOT(quit()));
    return QApplication::exec();



}
