#include "DettaglioVisitor.h"

#include "../model/Lezione.h"
#include "../model/Consegna.h"
#include "../model/Ricevimento.h"
#include "../model/Esame.h"
#include "../model/AttivitaStudio.h"

#include <QFormLayout>
#include <QLabel>
#include <QWidget>

DettaglioVisitor::DettaglioVisitor()
    : risultato(nullptr)
{
}

QWidget* DettaglioVisitor::getRisultato() const
{
    return risultato;
}


void DettaglioVisitor::visit(const Lezione& lezione) {
    risultato = new QWidget;

    auto* layout = new QFormLayout(risultato);

    layout->addRow("Tipo: ", new QLabel("Lezione", risultato));

    layout->addRow("Titolo:", new QLabel(lezione.getTitolo(), risultato));

    layout->addRow("Descrizione:", new QLabel(lezione.getDescrizione(), risultato));

    layout->addRow("Data:", new QLabel(lezione.getData().toString("dd/MM/yyyy"),risultato));

    layout->addRow("Materia:", new QLabel(lezione.getMateria(), risultato));

    layout->addRow("Ora inizio:", new QLabel(lezione.getOraInizio().toString("HH:mm"), risultato));

    layout->addRow("Ora fine:", new QLabel(lezione.getOraFine().toString("HH:mm"), risultato));

    layout->addRow("Aula:", new QLabel(lezione.getLocation().getAula(), risultato));
}


void DettaglioVisitor::visit(const Consegna& consegna)
{
    risultato = new QWidget;

    auto* layout = new QFormLayout(risultato);

    layout->addRow("Tipo:", new QLabel("Consegna", risultato));

    layout->addRow("Titolo:", new QLabel(consegna.getTitolo(), risultato));

    layout->addRow("Descrizione:", new QLabel(consegna.getDescrizione(), risultato));

    layout->addRow("Data:",new QLabel(consegna.getData().toString("dd/MM/yyyy"), risultato));

    layout->addRow("Materia:", new QLabel(consegna.getMateria(), risultato));

    layout->addRow("Ora limite:", new QLabel(consegna.getOrarioConsegna().toString("HH:mm"), risultato));
}