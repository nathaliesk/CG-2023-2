# Computação Gráfica 2023-2

  Atividades da disciplina de Computação Gráfica para o semestre 2023/2.

  Professor: Mario Liziér
  Discente: Nathalie Santos Komatsu
  RA: 771055

# ObjLoader

  Este programa é um exemplo simples de um carregador de modelos no formato OBJ.

## Requisitos

  - Compilador C++11
  - Catch2 (para executar testes)

## Como compilar

Para compilar o programa, você precisará de um compilador C++ e a biblioteca Catch2 para os testes unitários.

1. Clone este repositório.
2. Navegue até a pasta raiz do projeto.
3. Compile os arquivos `.cpp` usando o seu compilador C++ de escolha, e os testes unitários utilizando o Catch2.
   - Exemplo de compilação do programa principal:
     ```
     g++ main.cpp obj_loader.cpp -o obj_loader
     ```
   - Exemplo de compilação dos testes unitários:
     ```
     g++ test.cpp obj_loader.cpp -o test -std=c++11 -Wall
     ```
4. Execute o programa principal gerado.
5. Execute os testes unitários gerados.

## Como usar

O programa principal carrega um arquivo `.obj` especificado e imprime os vértices e faces do modelo.

## Testes unitários

Os testes unitários verificam o carregamento correto de um modelo OBJ e a precisão das informações carregadas.
