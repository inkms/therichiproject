#include "../include/caja.h"
#include "../include/carga_personalizada.h" //Cuando haya factory, quitamos esto

Caja::Caja(std::string nombre) : Caja(nombre, nullptr) {}

Caja::Caja(std::string nombre, Caja* madre) : m_id(Elemento::m_contador++), m_nombre(nombre), m_madre(madre) {}

bool Caja::completamenteDefinido() {
    for (auto it = m_hijos.begin(); it < m_hijos.end(); it++) {
        if (!(*it)->completamenteDefinido()) {
            return false;
        }
    }
    return true;
}

double Caja::cargaEquivalente() {
    double equivalente = 0;
    for (auto it = m_hijos.begin(); it < m_hijos.end(); it++) {
        equivalente += (*it)->cargaEquivalente();
    }
    return equivalente;
}

void Caja::setMadre(Caja* madre) {
    m_madre = madre;
}

void Caja::addCarga(std::string nombre, double potencia) {
    m_hijos.push_back(&CargaPersonalizada(nombre, potencia));
    return; // PENDIENTE, cuando tengamos la fabrica, mejoramos
}

void Caja::addCaja(std::string nombre) {
    m_hijos.push_back(&Caja(nombre));
    return;
}

bool Caja::delElemento(int id) {
    for (auto it = m_hijos.begin(); it < m_hijos.end(); it++) {
        if ((*it)->getId()==id ) {
            m_hijos.erase(it);
            return true; //Se ha encontrado el elemento
        }
    }
    return false; //No se ha encontrado el elemento
}

bool Caja::delCarga(int id) {
    return delElemento(id);
}

bool Caja::delCaja(int id) {
    return delElemento(id);
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