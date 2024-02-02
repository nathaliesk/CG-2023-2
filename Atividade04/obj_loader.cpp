// define a classe ObjLoader para carregar arquivos OBJ e criar triângulos a partir deles.

#include "obj_loader.h"

bool ObjLoader::loadObj(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Erro: Não foi possível abrir o arquivo: " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        iss >> token;

        if (token == "v") {
            Vertex v;
            iss >> v.x >> v.y >> v.z;
            vertices_.push_back(v);
        } else if (token == "f") {
            Face f;
            iss >> f.v1 >> f.v2 >> f.v3;
            // Índices em arquivos OBJ começam de 1, então subtraímos 1 para começar de 0
            f.v1--; f.v2--; f.v3--;
            faces_.push_back(f);
        }
    }

    // Criar triângulos a partir das faces
    for (const auto& face : faces_) {
        triangles_.push_back(Triangle(vertices_[face.v1], vertices_[face.v2], vertices_[face.v3]));
    }

    file.close();
    return true;
}
