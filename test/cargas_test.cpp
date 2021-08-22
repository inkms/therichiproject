#include "catch.h"
#include "../include/elemento.h"
#include "../include/carga_interfaz.h"
#include "../include/carga_personalizada.h"
#include "../include/caja.h"
#include <cmath>
#include <string>
#include <iostream>
#include <memory>
#include <set>

using namespace std;

TEST_CASE( "Las cargas personalizadas funcionan", "[cargas][stable]" ) {
    CargaPersonalizada carga = CargaPersonalizada("Uno", 7); // No tanto
    CargaPersonalizada carga2 = CargaPersonalizada("Dos");

    SECTION( "Creación de las cargas es correcta" ) {
        REQUIRE( carga.getId() != carga2.getId() );
        REQUIRE( carga.getNombre() == "Uno" );
        REQUIRE( carga2.getNombre() == "Dos" );
        REQUIRE( carga.esCaja() == false );
        REQUIRE( carga2.esCaja() == false );
    }

    SECTION( "Calculos de las cargas es correcto" ) {
        REQUIRE( carga.cargaEquivalente() == 7 ); // No tanto
        REQUIRE( carga2.cargaEquivalente() == 0 );
    }

    SECTION( "Modificar caracteristicas es posible" ) {
        int id1 = carga.getId();
        int id2 = carga2.getId();
        carga.setNombre("Farruco");
        carga2.setNombre("Wenceslao");
        carga.setPotencia(99);
        carga2.setPotencia(2);
        REQUIRE( carga.cargaEquivalente() == 99 );
        REQUIRE( carga2.cargaEquivalente() == 2 );
        REQUIRE( carga.getNombre() == "Farruco" );
        REQUIRE( carga2.getNombre() == "Wenceslao" );
        REQUIRE( carga.getId() == id1 );
        REQUIRE( carga2.getId() == id2 );
    }

    SECTION( "Completamente definido es correcto" ) {
        REQUIRE( carga.completamenteDefinido() == true );
        REQUIRE( carga2.cargaEquivalente() == 0 );
        REQUIRE( carga2.completamenteDefinido() == false );
    }
}