#include "Esame.h"
#include "AgendaVisitor.h"
#include <QString>
#include <QTime>



    Esame::Esame (
        const QString& titolo,
        const QString& descrizione,
        const QDate& data,
        Priority priority,
        bool completata,
        const QTime& ora,
        const QString& materia,
        const Location& location,
        const QString& modalita

        )    : AgendaUniversitaria(
              titolo,
              descrizione,
              data,
              priority,
              completata
              ),
        ora(ora),
        materia(materia),
        location(location),
        modalita(modalita) {}




    //Getter

    QTime Esame::getOra() const {
        return ora;
    }

    QString Esame::getMateria() const {
        return materia;
    }

    Location Esame::getLocation() const {
        return location;
    }

    QString Esame::getModalita() const {
        return modalita;
    }



    //Setter

    void Esame::setOra(const QTime& ora){
        this->ora = ora;
    }
    void Esame::setMateria(const QString& materia){
        this->materia = materia;
    }
    void Esame::setLocation(const Location& location){
        this->location = location;
    }
    void Esame::setModalita(const QString& modalita){
        this->modalita = modalita;
    }



    QString Esame::getType() const
    {
        return QStringLiteral("Esame");
    }

    void Esame::accept(AgendaVisitor& visitor) const {
        visitor.visit(*this);
    }


    QJsonObject Esame::toJson() const
    {
        QJsonObject json;

        json["tipo"] = getType();
        json["titolo"] = titolo;
        json["descrizione"] = descrizione;
        json["data"] = data.toString(Qt::ISODate);
        json["priority"] = static_cast<int>(priority);
        json["completata"] = completata;

        json["ora"] = ora.toString(Qt::ISODate);
        json["materia"] = materia;
        json["modalita"] = modalita;

        json["location"] = QJsonObject{
            {"indirizzo", location.getIndirizzo()},
            {"edificio", location.getEdificio()},
            {"aula", location.getAula()}
        };

        return json;
    }


