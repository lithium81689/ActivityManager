#ifndef AGENDAUNIVERSITARIA_H
#define AGENDAUNIVERSITARIA_H
#include <QString>
#include <QDate>
#include "Priority.h"


class AgendaUniversitaria {

protected:
    QString titolo;
    QString descrizione;
    QDate Data;
    Priority priority;
    bool completata;

public:
    virtual ~AgendaUniversitaria() = default;
    virtual QString riepilogo() const = 0;
    Priority getPriority() const ;
    void setPriority(Priority priority);
    virtual QJsonObject toJson() const = 0;

};


#endif // AGENDAUNIVERSITARIA_H
