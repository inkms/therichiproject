#ifndef _ELEMENTO_H
#define _ELEMENTO_H

#include <string>

class Elemento {
    protected:
        static int m_contador;
        int m_id;
        std::string m_nombre = "Indefinido";
    public:
        Elemento() : m_id(m_contador++) {}
        Elemento(std::string nombre) : m_id(m_contador++), m_nombre(nombre) {}
        virtual bool completamenteDefinido() = 0;
        virtual bool esCaja() = 0;
        virtual double cargaEquivalente() = 0;
        virtual std::string getNombre() const = 0;
        virtual void setNombre(const std::string nombre) = 0;
        virtual int getId() const = 0;
};

#endif // _ELEMENTO_H