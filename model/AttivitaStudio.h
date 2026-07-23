#ifndef ATTIVITASTUDIO_H
#define ATTIVITASTUDIO_H



#include "AgendaUniversitaria.h"
#include <QString>


class AttivitaStudio : public AgendaUniversitaria {

    private:
        QString materia;
        QString argomento;
        int minutiPrevisti;
        int minutiSvolti;

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
            int minutiSvolti
        );


    //Getter
        QString getMateria() const;
        QString getArgomento() const;
        int getMinutiPrevisti() const;
        int getMinutiSvolti() const;

    //Setter
        void setMateria(QString& materia);
        void setArgomento(QString& argomento);
        void setMinutiPrevisti(int minutiPrevisti);
        void setMinutiSvolti(int minutiPrevisti);


    // Comportamenti polimorfi
    // void accept(AgendaVisitor&)...
    bool isExpiring(const QDate& date, const QTime& time) const override;
    QString getType() const override;

    QJsonObject toJson() const override;

};


#endif ATTIVITASTUDIO_H