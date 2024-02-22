// Modificar para carregar um arquivo OBJ e criar os triângulos para visualização
// carrega um arquivo OBJ, cria uma lista de triângulos a partir dele e inicia a visualização.

#include "obj_loader.h"
#include "visualize.h"

/**
 * @brief Função principal.
 * 
 * @return O código de saída do programa.
 */
int main() {
    ObjLoader loader;
    if (loader.loadObj("model.obj")) {
        std::vector<Triangle> triangles = loader.getTriangles();
        
        // Configurar visualização com tamanho da janela
        Visualize visualize(800, 400);

        // Adicionar triângulos ao mundo
        Hitable *list[triangles.size()];
        for (size_t i = 0; i < triangles.size(); ++i) {
            list[i] = &triangles[i];
        }
        Hitable *world = new HitableList(list, triangles.size());

        visualize.setWorld(world);

        visualize.run();
    }

    return 0;
}
