#include "AttivitaStudio.h"

#include <QString>
#include <QTime>



    AttivitaStudio::AttivitaStudio (
        const QString& titolo,
        const QString& descrizione,
        const QDate& data,
        Priority priority,
        bool completata,
        const QString& materia,
        const QString& argomento,
        int minutiPrevisti,
        int minutiSvolti,
        const QTime oraInizio

    )    : AgendaUniversitaria(
            titolo,
            descrizione,
            data,
            priority,
            completata
        ),
        materia(materia),
        argomento(argomento),
        minutiPrevisti(minutiPrevisti),
        minutiSvolti(minutiSvolti),
        oraInizio(oraInizio) {}




    //Getter

    QString AttivitaStudio::getMateria() const {
        return materia;
    }

    QString AttivitaStudio::getArgomento() const {
        return argomento;
    }

    int AttivitaStudio::getMinutiPrevisti() const {
        return minutiPrevisti;
    }

    int AttivitaStudio::getMinutiSvolti() const {
        return minutiSvolti;
    }

    QTime AttivitaStudio::getOraInizio() const {
        return oraInizio;
    }



    //Setter


    void AttivitaStudio::setMateria(const QString& materia){
        this->materia = materia;
    }
    void AttivitaStudio::setArgomento(const QString& argomento){
        this->argomento = argomento;
    }
    void AttivitaStudio::setMinutiPrevisti(int minutiPrevisti){
        this->minutiPrevisti = minutiPrevisti;
    }
    void AttivitaStudio::setMinutiSvolti(int minutiSvolti){
        this->minutiSvolti = minutiSvolti;
    }
    void AttivitaStudio::setOraInizio(const QTime& oraInizio){
        this->oraInizio = oraInizio;
    }


    double AttivitaStudio::getPercentualeCompletamento() const
    {
        if (minutiPrevisti <= 0)
            return 0.0;
        double percentuale = (static_cast<double>(minutiSvolti) / minutiPrevisti) * 100.0;

        // Se non vuoi superare il 100%
        if (percentuale > 100.0)
            percentuale = 100.0;

        return percentuale;
    }


    QString AttivitaStudio::getType() const
    {
        return QStringLiteral("AttivitaStudio");
    }



    QJsonObject AttivitaStudio::toJson() const
    {
        QJsonObject json;

        json["tipo"] = getType();
        json["titolo"] = titolo;
        json["descrizione"] = descrizione;
        json["data"] = data.toString(Qt::ISODate);
        json["priority"] = static_cast<int>(priority);
        json["completata"] = completata;

        json["materia"] = materia;
        json["argomento"] = argomento;
        json["minutiPrevisti"] = minutiPrevisti;
        json["minutiSvolti"] = minutiSvolti;
        json["oraInizio"] = oraInizio.toString(Qt::ISODate);

        return json;
    }



