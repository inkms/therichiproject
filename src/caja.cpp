#include "../include/caja.h"

Caja::Caja(std::string nombre) : Caja(nombre, nullptr) {}

Caja::Caja(std::string nombre, Caja* madre) : m_id(Elemento::m_contador++), m_nombre(nombre), m_madre(madre) {}

bool Caja::completamenteDefinido() {
    for (auto it = m_hijos.begin(); it < m_hijos.end(); it++) {
        if (!it->completamenteDefinido()) {
            return false;
        }
    }
    return true;
}

double Caja::cargaEquivalente() {
    double equivalente = 0;
    for (auto it = m_hijos.begin(); it < m_hijos.end(); it++) {
        equivalente += it->cargaEquivalente();
    }
    return equivalente;
}

void Caja::setMadre(Caja* madre) {
    m_madre = madre;
}

void Caja::addCarga() {
    return; // PENDIENTE
}

void Caja::addCaja() {
    return; //PENDIENTE
}

void Caja::delCarga(int id) {
    return; //PENDIENTE
}
void Caja::delCaja(int id) {
    return; //PENDIENTE
}
std::string Caja::getNombre() const {
    return m_nombre;
}

void Caja::setNombre(const std::string nombre) {
    m_nombre = nombre;
}

int Caja::getId() const {
    return m_id;
}