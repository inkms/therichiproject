#include "../include/caja.h"
#include "../include/carga_personalizada.h" //Cuando haya factory, quitamos esto

Caja::Caja(std::string nombre) : Caja(nombre, nullptr) {}

Caja::Caja(std::string nombre, Caja* madre) : m_id(Elemento::m_contador++), m_nombre(nombre), m_madre(madre) {}

bool Caja::completamenteDefinido() {
    if (m_hijos.empty()) {
        return false;
    }
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
    madre->addCaja(this);
}

CargaInterfaz* Caja::addCarga(std::string nombre, double potencia) {
    CargaPersonalizada* carga = new CargaPersonalizada(nombre, potencia);
    m_hijos.push_back(carga);
    return carga; // PENDIENTE, cuando tengamos la fabrica, mejoramos
}

Caja* Caja::addCaja(std::string nombre) {
    Caja* caja = new Caja(nombre, this);
    m_hijos.push_back(caja);
    return caja;
}

Caja* Caja::addCaja(Caja* hijo) {
    m_hijos.push_back(hijo);
    return hijo;
}

bool Caja::delElemento(int id) {
    for (auto it = m_hijos.begin(); it < m_hijos.end(); it++) {
        if ((*it)->getId()==id ) {
            delete *it;
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

Elemento* Caja::getHijo(int id) const {
    for (auto it = m_hijos.begin(); it < m_hijos.end(); it++) {
        if ((*it)->getId()==id ) {
            return *it;
        }
    }
    return nullptr; //No se ha encontrado el elemento
}

Elemento* Caja::getHijo(std::string nombre) const {
    for (auto it = m_hijos.begin(); it < m_hijos.end(); it++) {
        if ((*it)->getNombre()==nombre ) {
            return *it;
        }
    }
    return nullptr; //No se ha encontrado el elemento
}