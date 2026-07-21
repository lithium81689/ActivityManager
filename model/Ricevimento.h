#ifndef RICEVIMENTO_H
#define RICEVIMENTO_H


#include "AgendaUniversitaria.h"
#include "Location.h"

#include <QString>
#include <QTime>
#include <QJsonObject>


class Ricevimento : public AgendaUniversitaria
{
private:
    QString docente;
    QTime oraInizio;
    QTime oraFine;
    Location luogo;
    bool online;
    QString link;
    bool prenotato;

public:
    Ricevimento(
        const QString& titolo,
        const QString& descrizione,
        const QDate& data,
        Priority priority,
        const QString& docente,
        const QTime& oraInizio,
        const QTime& oraFine,
        const Location& luogo,
        bool online = false,
        const QString& link = QString(),
        bool prenotato = false
        );

    // Getter
    QString getDocente() const;
    QTime getOraInizio() const;
    QTime getOraFine() const;
    Location getLuogo() const;
    bool isOnline() const;
    QString getLink() const;
    bool isPrenotato() const;

    // Setter
    void setDocente(const QString& docente);
    void setOraInizio(const QTime& oraInizio);
    void setOraFine(const QTime& oraFine);
    void setLuogo(const Location& luogo);
    void setOnline(bool online);
    void setLink(const QString& link);
    void setPrenotato(bool prenotato);

    // Metodi polimorfi
    bool isExpiring(const QDate& rifDate, const QTime& rifTime) const override;
    QJsonObject toJson() const override;
    // void accept(Visitor& visitor) override;
};



#endif // RICEVIMENTO_H
