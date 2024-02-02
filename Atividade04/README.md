# Computação Gráfica 2023-2

  Atividades da disciplina de Computação Gráfica para o semestre 2023/2.

  Professor: Mario Liziér
  Discente: Nathalie Santos Komatsu
  RA: 771055

# Visualização Inicial

    Este programa implementa uma visualização básica de objetos 3D usando ray tracing.

## Compilação e Execução

1. Clone este repositório.
2. Navegue até a pasta raiz do projeto.
3. Compile os arquivos `.cpp` utilizando um compilador C++ de sua escolha, incluindo a biblioteca SDL2.
    - Exemplo de comando de compilação usando g++ no Linux:
      ```
      g++ -o main main.cpp visualize.cpp obj_loader.cpp -lSDL2
      ```
4. Execute o programa gerado.

## Uso do OBJ

    - A visualização renderizará o modelo carregado a partir do arquivo `model.obj`.
    - Você pode fechar a janela clicando no botão de fechar ou pressionando `Esc`.

## Testes Unitários

    - Os testes unitários verificam se a leitura de arquivos OBJ está funcionando corretamente.

## Dependências

    - Este programa requer a biblioteca SDL2 para renderização gráfica.
