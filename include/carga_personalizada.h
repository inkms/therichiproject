#ifndef _CARGA_PERSONALIZADA_H
#define _CARGA_PERSONALIZADA_H

#include "carga_interfaz.h"

class CargaPersonalizada: public CargaInterfaz {
    private:
        double m_potencia;
    public:
        CargaPersonalizada(std::string nombre);
        CargaPersonalizada(std::string nombre, double potencia);
        bool completamenteDefinido();
        bool esCaja();
        double cargaEquivalente();
        std::string getNombre() const;
        void setNombre(const std::string nombre);
        void setPotencia(const double potencia);
        int getId() const;
};

#endif // _CARGA_PERSONALIZADA_H