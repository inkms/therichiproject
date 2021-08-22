#ifndef _CAJA_H
#define _CAJA_H

#include "elemento.h"
#include <vector>

class Caja: public Elemento {
    public:
        Caja(std::string nombre);
        Caja(std::string nombre, Caja* madre);
        bool completamenteDefinido();
        bool esCaja() { return true; }
        double cargaEquivalente();
        void setMadre(Caja* madre);
        void addCarga();
        void addCaja();
        void delCarga(int id);
        void delCaja(int id);
        std::string getNombre() const;
        void setNombre(const std::string nombre);
        int getId() const;
    private:
        std::vector<Elemento> m_hijos;
        int m_id;
        std::string m_nombre;
        Caja* m_madre;
};

#endif // _CAJA_H