#ifndef CONSEGNA_H
#define CONSEGNA_H

#include "AgendaUniversitaria.h"

#include <QString>
#include <QTime>
#include <QJsonObject>

class Consegna : public AgendaUniversitaria
{
private:
    QString materia;
    bool lavoroDiGruppo;
    QTime orarioConsegna;


public:
    Consegna(
        const QString& titolo,
        const QString& descrizione,
        const QDate& data,
        Priority priority,
        const QString& materia,
        const QTime& orarioConsegna,
        bool lavoroDiGruppo = false,
        bool completata = false
        );

    // Getter
    QString getMateria() const;
    QTime getOrarioConsegna() const;
    bool isLavoroDiGruppo() const;

    // Setter
    void setMateria(const QString& materia);
    void setOrarioConsegna(const QTime& consTime);
    void setLavoroDiGruppo(bool lavoroDiGruppo);

    // Comportamenti polimorfi
    void accept(AgendaVisitor& visidor) const override;
    bool isExpiring(const QDate& date, const QTime& time) const override;
    QString getType() const override;

    // Persistenza
    QJsonObject toJson() const override;
};




#endif // CONSEGNA_H
