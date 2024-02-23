# Computação Gráfica 2023-2

  Atividades da disciplina de Computação Gráfica para o semestre 2023/2.

  Professor: Mario Liziér
  Discente: Nathalie Santos Komatsu
  RA: 771055

# Materiais Difusos

  Este programa implementa um sistema de renderização de objetos 3D com materiais difusos, seguindo o tutorial "Ray Tracing in One Weekend".

## Compilação e Execução

  1. Clone este repositório.
  2. Navegue até a pasta raiz do projeto.
  3. Compile os arquivos `.cpp` utilizando um compilador C++ de sua escolha, incluindo a biblioteca SDL2.
      - Exemplo de comando de compilação usando g++ no Linux:
        ```
        g++ -o main main.cpp sphere.cpp lambertian.cpp camera.cpp -lSDL
        ```
  4. Execute o programa gerado.

## Uso

  Este programa renderiza uma cena com três esferas, cada uma com um material difuso de cor diferente. A cena é renderizada em formato PPM, que pode ser visualizado com programas de visualização de imagens.

## Alternando Pontos de Vista

  Este programa suporta a visualização da cena de dois pontos de vista diferentes. Você pode alternar entre esses pontos de vista pressionando as teclas específicas durante a execução do programa:

  - Pressione `1` para o primeiro ponto de vista.
  - Pressione `2` para o segundo ponto de vista.

  Isso permite explorar a cena de ângulos variados, oferecendo uma visão mais completa dos objetos renderizados e dos efeitos dos materiais difusos.


## Dependências

- Este programa requer a biblioteca SDL para renderização gráfica.