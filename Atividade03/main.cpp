#include "obj_loader.h"

int main() {
    ObjLoader loader;
    if (loader.loadObj("model.obj")) {
        std::cout << "Vértices:" << std::endl;
        for (const auto& vertex : loader.getVertices()) {
            std::cout << "  " << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
        }

        std::cout << "Faces:" << std::endl;
        for (const auto& face : loader.getFaces()) {
            std::cout << "  " << face.v1 << " " << face.v2 << " " << face.v3 << std::endl;
        }
    }

    return 0;
}