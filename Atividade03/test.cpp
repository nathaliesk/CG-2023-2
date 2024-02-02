#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "obj_loader.h"

TEST_CASE("Teste ObjLoader", "[obj_loader]") {
    ObjLoader loader;
    REQUIRE(loader.loadObj("cube.obj"));

    SECTION("Verificar Vértices") {
        std::vector<Vertex> vertices = loader.getVertices();
        REQUIRE(vertices.size() == 8);
        REQUIRE(vertices[0].x == Approx(-0.5));
        REQUIRE(vertices[0].y == Approx(-0.5));
        REQUIRE(vertices[0].z == Approx(0.5));
        // Adicionar mais verificações conforme necessário...
    }

    SECTION("Verificar Faces") {
        std::vector<Face> faces = loader.getFaces();
        REQUIRE(faces.size() == 12);
        REQUIRE(faces[0].v1 == 0);
        REQUIRE(faces[0].v2 == 1);
        REQUIRE(faces[0].v3 == 2);
        // Adicionar mais verificações conforme necessário...
    }
}
