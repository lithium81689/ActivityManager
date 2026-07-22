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

Q





























