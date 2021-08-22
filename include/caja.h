#ifndef _CAJA_H
#define _CAJA_H

#include "elemento.h"
#include "carga_interfaz.h"
#include <vector>

class Caja: public Elemento {
    public:
        Caja(std::string nombre);
        Caja(std::string nombre, Caja* madre);
        bool completamenteDefinido();
        bool esCaja() { return true; }
        double cargaEquivalente();
        void setMadre(Caja* madre);
        CargaInterfaz* addCarga(std::string nombre, double potencia = 0);
        Caja* addCaja(std::string nombre);
        Caja* addCaja(Caja* hijo);
        bool delCarga(int id);
        bool delCaja(int id);
        std::string getNombre() const;
        void setNombre(const std::string nombre);
        int getId() const;
        Elemento* getHijo(int id) const;
        Elemento* getHijo(std::string nombre) const;
    private:
        bool delElemento (int id);
        std::vector<Elemento*> m_hijos;
        int m_id;
        std::string m_nombre;
        Caja* m_madre;
};

#endif // _CAJA_H