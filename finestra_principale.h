#ifndef FINESTRA_PRINCIPALE_H
#define FINESTRA_PRINCIPALE_H

#include <QMainWindow>
#include <QTabWidget>

#include <QtGui>
//#include <QGroupBox>
#include "negozio.h"
#include "tabella.h"
#include "inserimento.h"
#include "ricerca.h"

class Finestra_Principale : public QMainWindow{
    Q_OBJECT                        //macro per gestire signal-slot
    Negozio* shop;
    QTabWidget* mng_schede;
    QPushButton* elimina;
public:
    explicit Finestra_Principale(Negozio& n, QWidget *parent = 0);

signals:

public slots:
    void aggiuntabici();
    void disabilita_status_bar(int);
};

#endif // FINESTRA_PRINCIPALE_H
