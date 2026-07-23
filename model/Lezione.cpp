#include "Lezione.h"
#include "AgendaVisitor.h"
#include <QDateTime>

Lezione::Lezione (
    const QString& titolo,
    const QString& descrizione,
    const QDate& data,
    Priority priority,
    const QString& materia,
    const QTime& oraInizio,
    const QTime& oraFine,
    const Location& location,
    bool completata
)
    : AgendaUniversitaria(
          titolo,
          descrizione,
          data,
          priority,
          completata
      ),
    oraInizio(oraInizio),
    oraFine(oraFine),
    materia(materia),
    location(location) {}



QString Lezione::getType() const
{
    return QStringLiteral("Lezione");
}

void Lezione::accept(AgendaVisitor& visitor) const {
    visitor.visit(*this);
}


bool Lezione::isExpiring(const QDate& rifDate, const QTime& rifTime) const{
    if (completata) {
        return false;
    }

    const QDateTime riferimento(rifDate, rifTime);
    const QDateTime inizioLezione(data, oraInizio);

    if (!riferimento.isValid() || !inizioLezione.isValid()) {
        return false;
    }

    const qint64 secondiMancanti = riferimento.secsTo(inizioLezione);

    const qint64 dueOre = 2 * 60 * 60;

    return secondiMancanti >= 0 && secondiMancanti <= dueOre;
}

QJsonObject Lezione::toJson() const
{
    QJsonObject json;

    json["tipo"] = getType();
    json["titolo"] = titolo;
    json["descrizione"] = descrizione;
    json["data"] = data.toString(Qt::ISODate);
    json["priority"] = static_cast<int>(priority);
    json["completata"] = completata;

    json["materia"] = materia;
    json["oraInizio"] = oraInizio.toString(Qt::ISODate);
    json["oraFine"] = oraFine.toString(Qt::ISODate);

    json["location"] = QJsonObject{
        {"indirizzo", location.getIndirizzo()},
        {"edificio", location.getEdificio()},
        {"aula", location.getAula()}
    };

    return json;
}


QString Lezione::getMateria() const {
    return materia;
}

QTime Lezione::getOraInizio() const {
    return oraInizio;
}

QTime Lezione::getOraFine() const {
    return oraFine;
}

const Location& Lezione::getLocation() const {
    return location;
}

void Lezione::setMateria(const QString& nuovaMateria) {
    materia = nuovaMateria;
}

void Lezione::setOraInizio(const QTime& nuovaOraInizio) {
    oraInizio = nuovaOraInizio;
}

void Lezione::setOraFine(const QTime& nuovaOraFine) {
    oraFine = nuovaOraFine;
}

void Lezione::setLocation(const Location& nuovaLocation) {
    location = nuovaLocation;
}


































