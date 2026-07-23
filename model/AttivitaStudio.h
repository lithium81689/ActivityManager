#ifndef ATTIVITASTUDIO_H
#define ATTIVITASTUDIO_H



#include "AgendaUniversitaria.h"
#include <QString>
#include <QTime>


class AttivitaStudio : public AgendaUniversitaria {

    private:
        QString materia;
        QString argomento;
        int minutiPrevisti;
        int minutiSvolti;
        QTime oraInizio;

    public:
        AttivitaStudio(
            const QString& titolo,
            const QString& descrizione,
            const QDate& data,
            Priority priority,
            bool completata,
            const QString& materia,
            const QString& argomento,
            int minutiPrevisti,
            int minutiSvolti,
            const QTime& oraInizio
        );


    //Getter
        QString getMateria() const;
        QString getArgomento() const;
        int getMinutiPrevisti() const;
        int getMinutiSvolti() const;
        QTime getOraInizio() const;

    //Setter
        void setMateria(const QString& materia);
        void setArgomento(const QString& argomento);
        void setMinutiPrevisti(int minutiPrevisti);
        void setMinutiSvolti(int minutiPrevisti);
        void setOraInizio(const QTime& oraInizio);


    // Comportamenti polimorfi
    // void accept(AgendaVisitor&)...
    double getPercentualeCompletamento() const;
    QString getType() const override;

    QJsonObject toJson() const override;

};


#endif ATTIVITASTUDIO_H