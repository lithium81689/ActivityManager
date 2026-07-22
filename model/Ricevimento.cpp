#include "Ricevimento.h"

#include <QJsonObject>

Ricevimento::Ricevimento(
    QString& titolo,
    QString& descrizione,
    QDate& data,
    Priority priority,
    const QString& docente,
    const QTime& oraInizio,
    const QTime& oraFine,
    const Location& luogo,
    bool online,
    const QString& link,
    bool prenotato
    )
    : AgendaUniversitaria(
          titolo,
          descrizione,
          data,
          priority,
          false
          ),
    docente(docente),
    oraInizio(oraInizio),
    oraFine(oraFine),
    luogo(luogo),
    online(online),
    link(link),
    prenotato(prenotato) {}

// getters

QString Ricevimento::getDocente() const {
    return docente;
}

QTime Ricevimento::getOraInizio() const {
    return oraInizio;
}

QTime Ricevimento::getOraFine() const {
    return oraFine;
}

Location Ricevimento::getLuogo() const {
    return luogo;
}

bool Ricevimento::isOnline() const {
    return online;
}

QString Ricevimento::getLink() const {
    return link;
}

bool Ricevimento::isPrenotato() const {
    return prenotato;
}

// setters

void Ricevimento::setDocente(const QString& docente) {
    this->docente = docente;
}

void Ricevimento::setOraInizio(const QTime& oraInizio) {
    this->oraInizio = oraInizio;
}

void Ricevimento::setOraFine(const QTime& oraFine) {
    this->oraFine = oraFine;
}

void Ricevimento::setLuogo(const Location& luogo) {
    this->luogo = luogo;
}

void Ricevimento::setOnline(bool online) {
    this->online = online;
}

void Ricevimento::setLink(const QString& link) {
    this->link = link;
}

void Ricevimento::setPrenotato(bool prenotato) {
    this->prenotato = prenotato;
}


QString Ricevimento::getType() const {
    return "Ricevimento";
}

bool Ricevimento::isExpiring(const QDate& rifDate, const QTime& rifTime) const {
    if (completata || data != rifDate) {
        return false;
    }

    int secondiRimanenti = rifTime.secsTo(oraInizio);

    return secondiRimanenti >= 0 && secondiRimanenti <= 60 * 60;
}

QJsonObject Ricevimento::toJson() const {
    QJsonObject json;

    // Attributi ereditati
    json["tipo"] = getType();
    json["titolo"] = titolo;
    json["descrizione"] = descrizione;
    json["data"] = data.toString(Qt::ISODate);
    json["priority"] = static_cast<int>(priority);
    json["completata"] = completata;

    // Attributi specifici di Ricevimento
    json["docente"] = docente;
    json["oraInizio"] = oraInizio.toString(Qt::ISODate);
    json["oraFine"] = oraFine.toString(Qt::ISODate);

    json["luogo"] = QJsonObject{
        {"indirizzo", luogo.getIndirizzo()},
        {"edificio", luogo.getEdificio()},
        {"aula", luogo.getAula()}
    };

    json["online"] = online;
    json["link"] = link;
    json["prenotato"] = prenotato;

    return json;
}



















