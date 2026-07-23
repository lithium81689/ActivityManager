#ifndef DETTAGLIOVISITOR_H
#define DETTAGLIOVISITOR_H

#include "../model/AgendaVisitor.h"

class QWidget;

class DettaglioVisitor : public AgendaVisitor
{
private:
    QWidget* risultato;

public:
    DettaglioVisitor();

    void visit(const Lezione& lezione) override;
    void visit(const Consegna& consegna) override;
    void visit(const Ricevimento& ricevimento) override;
    void visit(const Esame& esame) override;
    void visit(const AttivitaStudio& attivitaStudio) override;

    QWidget* getRisultato() const;
};

#endif // DETTAGLIOVISITOR_H
