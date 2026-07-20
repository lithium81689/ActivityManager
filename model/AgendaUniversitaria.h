#ifndef AGENDAUNIVERSITARIA_H
#define AGENDAUNIVERSITARIA_H
#include <QString>
#include <QDate>
#include "Priority.h"


class AgendaUniversitaria {

protected:
    QString titolo;
    QString descrizione;
    QDate data;
    Priority priority;
    bool completata;

public:
    AgendaUniversitaria(QString titolo, QString descrizione, QDate data, Priority priority, bool completata);

    virtual ~AgendaUniversitaria() = default;
    virtual QString riepilogo() const = 0;
    Priority getPriority() const ;
    void setPriority(Priority priority);
    virtual QJsonObject toJson() const = 0;

};


#endif // AGENDAUNIVERSITARIA_H
