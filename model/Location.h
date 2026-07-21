#ifndef LOCATION_H
#define LOCATION_H

#include<QString>

class Location {
    private:
        QString indirizzo;
        QString edificio;
        QString aula;

    public:
        Location() = default;

        Location(
            const QString& indirizzo,
            const QString& edificio,
            const QString& aula
        )
            : indirizzo(indirizzo),
              edificio(edificio),
              aula(aula) {}

        // getters
        const QString& getIndirizzo() const { return indirizzo; }
        const QString& getAula() const { return aula; }
        const QString& getEdificio() const { return edificio; }

        // setters
        void setIndirizzo(const QString& ind) { indirizzo = ind; }
        void setEdificio(const QString& edi) { edificio = edi; }
        void setAula(const QString& aul) { aula = aul; }
};

#endif // LOCATION_H
