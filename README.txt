Projeto 2 - Melhorias no Gerenciador de Playlists

Autor do Projeto Original: Pedro Vinícius Oliveira Maciel Pinho

Autoras das modificações: Ana Carolina Barbosa da Silva e Mariana Emerenciano Miranda

O programa permite a criação de músicas e playlists, e também permite 
"tocar" as músicas de uma playlist, mostrando sempre qual a próxima
música a ser tocada.

Uma limitação do programa é que não é possível ter duas músicas
diferentes com mesmo nome, mesmo que o autor das duas seja diferente.

Ao rodar o programa, é possível executar o setup, que automaticamente
adiciona algumas playlists e músicas para teste.

Esses são os dados adicionados no setup:

Playlist 1: Música 1, Música 2 e Música 3.

Playlist 2: Música 1 e Música 4.

Playlist 3: Nenhuma música.

//////////////////////////UPDATES//////////////////////////

Foram realizadas melhorias na classe da Lista Ligada. Agora, esta é capaz de:
1) Adicionar e remover elementos de uma lista en relação à outra;
2) Criar uma lista a partir de outra;
3) Concatenar duas listas, gerando uma nova lista que contém os elementos das duas;
4) Extrair o último elemento da lista;
5) e inserir um nó no fim da lista.

Também foram implementadas melhorias na classe de Playlist. Ela é capaz de:
1) Adicionar e remover músicas em uma playlist a partir de todas as músicas de uma outra;
2) Criar uma playlist a partir de outra;
3) Concatenar duas playlist, sgerando uma nova lista que contém os elementos das duas;
4) Criar uma nova playlist que contém uma música a mais do que a original;
5) Criar uma nova playlist que contém a diferença de músicas entre duas playlists;
6) Criar uma nova playlist que contém uma música a menos do que a original;
7) Extrair uma música da playlist;
8) e inserir uma música na última posição da playlist.


A documentação doxygen do projeto está disponível no arquivo docs/html/index.html



Como compilar:

Na pasta raiz do projeto, utilize os comandos a seguir:

cmake -B build
cmake --build build

Como rodar:

Utilize o comando a seguir:

./build/program
