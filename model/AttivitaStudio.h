#ifndef ATTIVITASTUDIO_H
#define ATTIVITASTUDIO_H

#endif // ATTIVITASTUDIO_H

#include "AgendaUniversitaria.h"
#include <QString>

class AttivitaStudio : public AgendaUniversitaria {

    private:
        QString materia;
        QString argomento;
        int minutiPrevisti;
        int minutiSvolti;

    public AttivitaStudio(
            QString& titolo,
            QString& descrizione,
            QDate& data,
            Priority priority,
            bool completata,
            Qstring& materia,
            Qstring& argomento,
            int minutiPrevisti,
            int minutiSvolti
            )


};