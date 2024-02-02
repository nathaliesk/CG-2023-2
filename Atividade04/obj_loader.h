// define a classe ObjLoader para carregar arquivos OBJ e criar triângulos a partir deles.

#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "triangle.h"

/**
 * @brief Classe para carregar modelos no formato OBJ.
 */
class ObjLoader {
public:
    ObjLoader() {}

    /**
     * @brief Carrega um arquivo OBJ.
     * 
     * @param filename Nome do arquivo OBJ a ser carregado.
     * @return Verdadeiro se o carregamento foi bem-sucedido, falso caso contrário.
     */
    bool loadObj(const std::string& filename);

    /**
     * @brief Obtém uma lista de triângulos do modelo carregado.
     * 
     * @return Um vetor de triângulos.
     */
    std::vector<Triangle> getTriangles() const {
        return triangles_;
    }

private:
    std::vector<Vertex> vertices_; ///< Lista de vértices do modelo.
    std::vector<Face> faces_;      ///< Lista de faces do modelo.
    std::vector<Triangle> triangles_; ///< Lista de triângulos do modelo.
};

#endif // OBJ_LOADER_H
