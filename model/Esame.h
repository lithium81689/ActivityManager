#ifndef ESAME_H
#define ESAME_H
#include "AgendaUniversitaria.h"
#include <QString>
#include <QDate>

class Esame : public AgendaUniversitaria {

private:

    QTime ora;
    QString materia;
    QString aula;
    QString modalita;

    std::optional<int> voto;

};

#endif // ESAME_H
