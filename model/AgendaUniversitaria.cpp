#include "AgendaUniversitaria.h"

AgendaUniversitaria::AgendaUniversitaria(
    QString& titolo,
    QString& descrizione,
    QDate& data,
    Priority priority,
    bool completata
    )
    : titolo(titolo),
    descrizione(descrizione),
    data(data),
    priority(priority),
    completata(completata) {}


QString AgendaUniversitaria::getTitolo() const {
    return titolo;
}

QDate AgendaUniversitaria::getData() const {
    return data;
}

QString AgendaUniversitaria::getDescrizione() const {
    return descrizione;
}

Priority AgendaUniversitaria::getPriority() const {
    return priority;
}

void AgendaUniversitaria::setTitolo(const QString& titolo) {
    this->titolo = titolo;
}

void AgendaUniversitaria::setDescrizione(const QString& descrizione) {
    this->descrizione = descrizione;
}

void AgendaUniversitaria::setData(const QDate& data) {
    this->data = data;
}

void AgendaUniversitaria::setCompletata(bool completata) {
    this->completata = completata;
}

bool AgendaUniversitaria::isCompletata() const {
    return completata;
}





























