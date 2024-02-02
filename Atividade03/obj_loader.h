#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief Estrutura para representar um vértice 3D.
 */
struct Vertex {
    float x, y, z;
};

/**
 * @brief Estrutura para representar uma face em um modelo OBJ.
 */
struct Face {
    int v1, v2, v3;
};

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
     * @brief Obtém os vértices do modelo carregado.
     * 
     * @return Um vetor de vértices.
     */
    std::vector<Vertex> getVertices() const {
        return vertices_;
    }

    /**
     * @brief Obtém as faces do modelo carregado.
     * 
     * @return Um vetor de faces.
     */
    std::vector<Face> getFaces() const {
        return faces_;
    }

private:
    std::vector<Vertex> vertices_; ///< Lista de vértices do modelo.
    std::vector<Face> faces_;      ///< Lista de faces do modelo.
};

#endif // OBJ_LOADER_H