/**
 * @file main.cpp
 * @brief Arquivo principal do programa.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Node.hpp"
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"
#include "menu.hpp"


/**
 * @brief Analisa uma linha de um arquivo de texto e cria um objeto Playlist.
 *
 * Esta função recebe uma linha de um arquivo de texto que representa uma
 * playlist com músicas e a analisa para criar um objeto Playlist. A linha
 * deve ter o seguinte formato:
 *    NomePlaylist;TituloMusica1:AutorMusica1,TituloMusica2:AutorMusica2,...
 *
 * @param line A linha do arquivo de texto que representa a playlist.
 * @param songs Uma referência para a LinkedList de músicas do sistema.
 *
 * @return O objeto Playlist analisado.
 */
Playlist parsePlaylist(const std::string& line, LinkedList<Song>& songs) {
    std::stringstream ss(line);
    std::string playlistName;
    std::getline(ss, playlistName, ';');

    Playlist playlist(playlistName);

    std::string songInfo;
    while (std::getline(ss, songInfo, ',')) {
        std::stringstream songSS(songInfo);
        std::string songTitle, songAuthor;
        std::getline(songSS, songTitle, ':');
        std::getline(songSS, songAuthor);

        Song song(songTitle, songAuthor);
        songs.add(song);

        playlist.addSong(song);
    }

    return playlist;
}


/**
 * @brief Lê as playlists e músicas de um arquivo de texto e adiciona ao sistema.
 * 
 * @param songs Lista encadeada (LinkedList) de músicas (Song) do sistema.
 * @param playlists Lista encadeada (LinkedList) de playlists (Playlist) do sistema.
 * @param filename Nome do arquivo de texto a ser lido.
 */
void readDataFromFile(LinkedList<Song>& songs, LinkedList<Playlist>& playlists, const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (!line.empty()) {
            playlists.add(parsePlaylist(line, songs));
        }
    }

    inputFile.close();
}

/**
 * @brief Setup inicial do programa, que adiciona exemplos de
 * músicas e playlists para demonstrar as funcionalidades do
 * programa.
 * 
 * @param songs Lista encadeada (LinkedList) de músicas (Song) do sistema.
 * @param playlists Lista encadeada (LinkedList) de playlists (Playlist) do sistema.
 */
void setup(LinkedList<Song> &songs, LinkedList<Playlist> &playlists){
    int choice;

    std::cout << "Deseja executar o setup inicial? Isso irá adicionar\n" <<
                 "alguns exemplos de músicas e playlists\n";
    std::cout << "1. Sim\n";
    std::cout << "0. Não\n";
    std::cout << "Digite sua escolha: ";

    std::cin >> choice;
    std::cin.ignore();

    if(choice == 0) return;


    std::string filename = "/home/mariemerenc/Downloads/playlist-main/test.txt"; // Nome do arquivo de texto contendo os exemplos
    readDataFromFile(songs, playlists, filename);

    

    std::cout << "Setup completo\n";
    std::cout << "Pressione ENTER para continuar.";
    std::cin.get();
}

/**
 * @brief Função principal do programa.
 *
 * A função `main` é responsável por iniciar a execução do programa.
 * Nela, são criadas as listas encadeadas para armazenar as playlists
 * e as músicas. Em seguida, é chamada a função `setup` para adicionar
 * exemplos de músicas e playlists. Após o setup, é iniciado um loop
 * que exibe o menu principal e permite a interação com o usuário.
 * Quando o usuário escolhe sair do programa, as listas são limpas e o
 * programa é encerrado.
 *
 * @param argc O número de argumentos de linha de comando passados para o programa.
 * @param argv Um array de strings contendo os argumentos de linha de comando.
 *
 * @return O valor de saída do programa. Neste caso, sempre será 0.
 */
int main(int argc,char *argv[]){
    LinkedList<Playlist> playlists;
    LinkedList<Song> songs;
    
    setup(songs, playlists);

    int exit{0};

    while(exit == 0){
        exit = mainMenu(songs, playlists);
    }

    playlists.clear();
    songs.clear();

    return 0;
}


