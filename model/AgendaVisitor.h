#ifndef AGENDAVISITOR_H
#define AGENDAVISITOR_H

class Lezione;
class Consegna;
class Ricevimento;
class Esame;
class AttivitaStudio;

class AgendaVisitor
{
public:
    virtual ~AgendaVisitor() = default;

    virtual void visit(const Lezione& lezione) = 0;
    virtual void visit(const Consegna& consegna) = 0;
    virtual void visit(const Ricevimento& ricevimento) = 0;
    virtual void visit(const Esame& esame) = 0;
    virtual void visit(const AttivitaStudio& attivitaStudio) = 0;
};

#endif // AGENDAVISITOR_H
