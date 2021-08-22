#include "catch.h"
#include "../include/elemento.h"
#include "../include/carga_interfaz.h"
#include "../include/carga_personalizada.h"
#include "../include/caja.h"
#include <string>
#include <iostream>


using namespace std;

TEST_CASE( "Las cajas funcionan", "[cargas][stable]" ) {
    Caja caja = Caja("Uno");
    Caja caja2 = Caja("Dos");
    

    SECTION( "Creación de las cargas es correcta" ) {
        REQUIRE( caja.getId() != caja2.getId() );
        REQUIRE( caja.getNombre() == "Uno" );
        REQUIRE( caja2.getNombre() == "Dos" );
        REQUIRE( caja.esCaja() == true );
        REQUIRE( caja.esCaja() == true );
    }

    SECTION( "Calculos de las cargas es correcto" ) {
        caja.addCarga("Uno-A", 1);
        caja.addCarga("Uno-B", 3);

        caja2.addCarga("Dos-A", 2);
        Caja* caja21 = caja2.addCaja("Dos-Uno");
        caja21->addCarga("Dos-Uno-A", 40);
        caja21->addCarga("Dos-Uno-B", 60);
        REQUIRE( caja.cargaEquivalente() == 4 );
        REQUIRE( caja2.cargaEquivalente() == 102 );
    }

    SECTION( "Podemos acceder a elementos de las cajas" ) {
        caja.addCarga("Uno-A", 1);
        CargaInterfaz* carga = caja.addCarga("Uno-B", 3);
        caja2.addCarga("Dos-A", 2);
        Caja* caja21 = caja2.addCaja("Dos-Uno");
        caja21->addCarga("Dos-Uno-A", 40);
        caja21->addCarga("Dos-Uno-B", 60);

        REQUIRE( caja.getHijo("Uno-A")->cargaEquivalente() == 1 );
        REQUIRE( caja.getHijo(carga->getId())->cargaEquivalente() == 3 );
        REQUIRE( caja.getHijo(caja21->getId()) == nullptr );
        REQUIRE( caja2.getHijo(caja21->getId()) == caja21 );
        REQUIRE( caja21->getHijo("Dos-Uno-A")->cargaEquivalente() == 40 );
    }

    SECTION( "Completamente definido es correcto" ) {
        caja.addCarga("Uno-A", 1);
        CargaInterfaz* carga = caja.addCarga("Uno-B", 3);
        caja2.addCarga("Dos-A", 2);
        Caja* caja21 = caja2.addCaja("Dos-Uno");
        caja21->addCarga("Dos-Uno-A", 40);
        caja21->addCarga("Dos-Uno-B");

        REQUIRE( caja.completamenteDefinido() == true );
        REQUIRE( caja2.completamenteDefinido() == false ); //Una carga sin definir

        Caja caja3 = Caja("Tres");
        REQUIRE( caja3.completamenteDefinido() == false ); //Una caja sin salidas
    }

    SECTION( "SetMadre funciona" ) {
        caja.addCarga("Uno-A", 1);
        CargaInterfaz* carga = caja.addCarga("Uno-B", 3);
        caja2.addCarga("Dos-A", 2);
        Caja* caja21 = caja2.addCaja("Dos-Uno");
        caja21->addCarga("Dos-Uno-A", 40);
        caja21->addCarga("Dos-Uno-B", 60);

        caja2.setMadre(&caja);
        REQUIRE( caja.cargaEquivalente() == 106 );
    }

    SECTION( "Se pueden quitar hijos" ) {
        caja.addCarga("Uno-A", 1);
        CargaInterfaz* carga = caja.addCarga("Uno-B", 3);
        caja2.addCarga("Dos-A", 2);
        Caja* caja21 = caja2.addCaja("Dos-Uno");
        caja21->addCarga("Dos-Uno-A", 40);
        caja21->addCarga("Dos-Uno-B", 60);
        
        REQUIRE( caja2.cargaEquivalente() == 102);
        caja21->delCarga(caja21->getHijo("Dos-Uno-B")->getId());
        REQUIRE( caja2.cargaEquivalente() == 42);
        caja2.delCaja(caja21->getId());
        REQUIRE( caja2.cargaEquivalente() == 2);
    }
}