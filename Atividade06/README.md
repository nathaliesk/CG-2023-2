# Computação Gráfica 2023-2

  Atividades da disciplina de Computação Gráfica para o semestre 2023/2.

  Professor: Mario Liziér
  Discente: Nathalie Santos Komatsu
  RA: 771055

# Metal e Vidro

    Este programa implementa um sistema de renderização de objetos 3D com materiais de metal e vidro.

## Compilação e Execução

    1. Clone este repositório.
    2. Navegue até a pasta raiz do projeto.
    3. Compile os arquivos `.cpp` utilizando um compilador C++ de sua escolha.
    ```bash
    g++ -o ray_tracing main.cpp camera.cpp hitable_list.cpp material_glass.cpp material_metal.cpp ray.cpp sphere.cpp util.cpp vec3.cpp


## Uso

    Este programa renderiza uma cena com um objeto metálico e outro de vidro. A cena é renderizada em formato PPM, que pode ser visualizado com programas de visualização de imagens.

## Dependências

    - Nenhuma dependência além de um compilador C++ é necessária.


## Arquivos

    - `main.cpp`: Arquivo principal que contém a função `main` responsável por configurar a cena, criar a câmera e renderizar a imagem.
    - `camera.h` e `camera.cpp`: Definem a classe `Camera` que representa a câmera usada para capturar a cena.
    - `hitable_list.h` e `hitable_list.cpp`: Definem a classe `HitableList` que representa uma lista de objetos "atingíveis" na cena.
    - `material_metal.h` e `material_metal.cpp`: Definem a classe `MaterialMetal` que representa um material metálico.
    - `material_glass.h` e `material_glass.cpp`: Definem a classe `MaterialGlass` que representa um material de vidro.
    - `ray.h` e `ray.cpp`: Definem a classe `Ray` que representa um raio no espaço tridimensional.
    - `sphere.h` e `sphere.cpp`: Definem a classe `Sphere` que representa uma esfera na cena.
    - `util.h` e `util.cpp`: Contêm funções de utilidade, como funções para geração de números aleatórios e escrita de cores em formato PPM.
    - `vec3.h` e `vec3.cpp`: Definem a classe `Vec3` que representa um vetor tridimensional.