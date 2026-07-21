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
    AgendaUniversitaria(
        QString titolo,
        QString descrizione,
        QDate data,
        Priority priority,
        bool completata
    );

    virtual ~AgendaUniversitaria() = default;

    virtual QString getType() const = 0;
    virtual bool isExpiring(const QDate& rifDate, const QTime& rifTime) const = 0;
    // virtual ...

    QString getTitolo() const;
    void setTitolo(const QString& titolo);

    QString getDescrizione() const;
    void setDescrizione(const QString& descrizione);

    QDate getData() const;
    void setData(const QDate& data);

    Priority getPriority() const;
    void setPriority(Priority priority);

    bool isCompletata() const;
    void setCompletata(bool completata);

    virtual QJsonObject toJson() const = 0;

};


#endif // AGENDAUNIVERSITARIA_H
