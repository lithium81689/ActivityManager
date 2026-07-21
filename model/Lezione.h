#ifndef LEZIONE_H
#define LEZIONE_H

#include "AgendaUniversitaria.h"
#include "Location.h"

#include <QString>
#include <QDate>
#include <QTime>
#include <QJsonObject>

class Lezione : public AgendaUniversitaria {
private:
    QTime oraInizio;
    QTime oraFine;
    QString materia;
    Location location;

public:
    Lezione(
        const QString& titolo,
        const QString& descrizione,
        const QDate& data,
        Priority priority,
        const QString& materia,
        const QTime& oraInizio,
        const QTime& oraFine,
        const Location& location,
        bool completata = false
    );

    QString getType() const override;
    QJsonObject toJson() const override;

    bool isExpiring(const QDate& rifDate, const QTime& rifTime) const override;

    QString getMateria() const;
    const QTime getOraInizio() const;
    const QTime getOraFine() const;
    const QString getLocation() const;


    void setMateria(const QString& materia) const;
    void setOraInizio(const QTime& oraInizio);
    void setOraFine(const QTime& oraFine);
    void setLocation(const Location& location);
};

#endif // LEZIONE_H
