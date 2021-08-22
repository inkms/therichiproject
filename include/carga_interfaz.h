#ifndef _CARGA_INTERFAZ_H
#define _CARGA_INTERFAZ_H

#include "elemento.h"

class CargaInterfaz: public Elemento {
    public:
        CargaInterfaz(std::string nombre) : Elemento(nombre) {}
        CargaInterfaz() : Elemento() {}
        virtual bool completamenteDefinido() = 0;
        virtual double cargaEquivalente() = 0;
        bool esCaja() {return false;}
};

#endif // _CARGA_INTERFAZ_H