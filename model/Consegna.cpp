#include "Consegna.h"

#include <QDateTime>
#include <QJsonObject>

Consegna::Consegna(
    QString& titolo,
    QString& descrizione,
    QDate& data,
    Priority priority,
    const QString& materia,
    const QTime& orarioConsegna,
    bool lavoroDiGruppo,
    bool completata
    )
    : AgendaUniversitaria(
          titolo,
          descrizione,
          data,
          priority,
          completata
          ),
    materia(materia),
    lavoroDiGruppo(lavoroDiGruppo),
    orarioConsegna(orarioConsegna) {}


// Getter

QString Consegna::getMateria() const {
    return materia;
}

QTime Consegna::getOrarioConsegna() const {
    return orarioConsegna;
}

bool Consegna::isLavoroDiGruppo() const {
    return lavoroDiGruppo;
}


// Setter

void Consegna::setMateria(const QString& materia) {
    this->materia = materia;
}

void Consegna::setOrarioConsegna(const QTime& consTime) {
    orarioConsegna = consTime;
}

void Consegna::setLavoroDiGruppo(bool lavoroDiGruppo) {
    this->lavoroDiGruppo = lavoroDiGruppo;
}


// Comportamenti polimorfi

bool Consegna::isExpiring(const QDate& date, const QTime& time) const {
    if (completata ||
        !data.isValid() ||
        !orarioConsegna.isValid() ||
        !date.isValid() ||
        !time.isValid()) {

        return false;
    }

    const QDateTime riferimento(date, time);
    const QDateTime scadenza(data, orarioConsegna);

    const qint64 secondiRimanenti =
        riferimento.secsTo(scadenza);

    constexpr qint64 secondiInUnGiorno = 24 * 60 * 60;

    return secondiRimanenti >= 0 && secondiRimanenti <= secondiInUnGiorno;
}

QString Consegna::getType() const
{
    return QStringLiteral("Consegna");
}


// Persistenza

QJsonObject Consegna::toJson() const
{
    QJsonObject json;

    json["tipo"] = getType();
    json["titolo"] = titolo;
    json["descrizione"] = descrizione;
    json["data"] = data.toString(Qt::ISODate);
    json["priority"] = static_cast<int>(priority);
    json["completata"] = completata;

    json["materia"] = materia;
    json["orarioConsegna"] = orarioConsegna.toString(Qt::ISODate);
    json["lavoroDiGruppo"] = lavoroDiGruppo;

    return json;
}