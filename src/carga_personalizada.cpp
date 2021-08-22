#include "../include/carga_personalizada.h"

bool CargaPersonalizada::completamenteDefinido() {
if (!m_potencia) {
        return true;
    }
    return false;
}

double CargaPersonalizada::cargaEquivalente() {
    return m_potencia;
}

bool CargaPersonalizada::esCaja() {
    return false;
}

CargaPersonalizada::CargaPersonalizada(std::string nombre) : CargaPersonalizada( nombre, 0) {}

CargaPersonalizada::CargaPersonalizada(std::string nombre, double potencia) : 
                    CargaInterfaz(nombre),
                    m_potencia(potencia) {}

std::string CargaPersonalizada::getNombre() const {
    return m_nombre;
}

void CargaPersonalizada::setNombre(const std::string nombre) {
    m_nombre = nombre;
}

int CargaPersonalizada::getId() const {
    return m_id;
}