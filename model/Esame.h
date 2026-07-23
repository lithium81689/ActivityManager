#ifndef ESAME_H
#define ESAME_H
#include "AgendaUniversitaria.h"
#include "AgendaVisitor.h"
#include <QString>
#include <QDate>
#include <QTime>
#include "Location.h"

class Esame : public AgendaUniversitaria {

private:

    QTime ora;
    QString materia;
    Location location;
    QString modalita;

public:
    Esame(
        const QString& titolo,
        const QString& descrizione,
        const QDate& data,
        Priority priority,
        bool completata,
        const QTime& ora,
        const QString& materia,
        Location& location,
        const QString& modalita
    );

    //Getter
    QTime getOra() const;
    QString getMateria() const;
    Location getLocation() const;
    QString getModalita() const;

    //Setter
    void setOra(const QTime& ora);
    void setMateria(const QString& materia);
    void setLocation(const Location& location);
    void setModalita(const QString& modalita);


    // Comportamenti polimorfi
    // void accept(AgendaVisitor&)...
    bool isExpiring(const QDate& date, const QTime& time) const override;
    QString getType() const override;
    QJsonObject toJson() const override;
    void accept(AgendaVisitor& visitor) const override;


};

#endif // ESAME_H
