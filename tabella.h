#ifndef TABELLA_H
#define TABELLA_H

#include <QtGui>
#include "negozio.h"
#include "container.h"
#include "record.h"

class tabella : public QTableWidget
{private:
    Q_OBJECT
    Negozio* ptrNegozio;
    Container<record*> righe;
    void inserisci_riga(record*riga);
public:
    explicit tabella(Negozio* n, QWidget *parent = 0);
    ~tabella();
signals:

public slots:
    void eliminaRiga();
    void aggiorna();
};

#endif // TABELLA_H
