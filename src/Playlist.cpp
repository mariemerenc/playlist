/**
 * @file Playlist.cpp
 * @brief Arquivo que implementa os métodos da classe Playlist.
 */

#include <string>
#include <iostream>
#include "LinkedList.hpp"
#include "Song.hpp"
#include "Playlist.hpp"

/**
 * @brief Construtor padrão da playlist.
 */
Playlist::Playlist(){
    this->name = "";
}

/**
 * @brief Construtor da playlist que recebe seu nome.
 * 
 * @param name Nome da playlist.
 */
Playlist::Playlist(std::string name){
    this->name = name;
}

/**
 * @brief Destrutor da playlist, que remove todas as músicas.
 */
Playlist::~Playlist(){
    getSongs().clear();
}

/**
 * @brief Retorna o tamanho da playlist.
 * 
 * @return Número de músicas.
 */
size_t Playlist::getSize(){
    return getSongs().getSize();
}

/**
 * @brief Retorna o nome da playlist.
 * 
 * @return Nome da playlist.
 */
std::string Playlist::getName(){
    return name;
}

/**
 * @brief Retorna uma referência para a lista encadeada de músicas.
 * 
 * @return Referência para a lista de músicas.
 */
LinkedList<Song> &Playlist::getSongs(){
    return songs;
}

/**
 * @brief Adiciona uma música à playlist.
 * 
 * @param song Música a ser adicionada.
 */
void Playlist::addSong(Song song){
    getSongs().add(song);
}

/**
 * @brief Remove a música especificada da playlist.
 * 
 * @param title Título da música.
 */
void Playlist::removeSong(Song song){
    getSongs().removeValue(song);
}

/**
 * @brief Procura uma música na playlist.
 * 
 * @param song Música a ser buscada.
 * @return Retorna o ponteiro para a música, caso ela esteja na lista, ou nullptr
 * caso contrário.
 */
Song *Playlist::searchSong(Song song){
    return getSongs().searchValue(song);
}

/**
 * @brief Imprime as músicas da playlist.
 */
void Playlist::printSongs(){
    getSongs().print();
}

/**
 * @brief Sobrecarga de operador de igualdade.
 * 
 * @return Retorna true se o nome das playlists for igual.
 * @return Retorna false caso contrário.
 */
bool Playlist::operator==(Playlist &b){
    return this->getName() == b.getName();
}

/**
 * @brief Sobrecarga de operador de inserção da playlist.
 */
std::ostream& operator<<(std::ostream& os, const Playlist& playlist){
    os << "\"" << playlist.name << "\" - " << playlist.songs.getSize() << " música(s).";
    return os;
}

/**
 * @brief Adiciona todas as músicas de uma playlist à playlist atual.
 *
 * @param playlist A playlist da qual as músicas serão adicionadas.
 */
void Playlist::addSong(Playlist &playlist){
    Node<Song> *aux = playlist.getSongs().getHead();
    while(aux != nullptr){
        this->addSong(aux->getValue());
        aux = aux->getNext();
    }
}

/**
 * @brief Remove todas as músicas de uma playlist da playlist atual.
 *
 * @param playlist A playlist da qual as músicas serão removidas.
 */
void Playlist::removeSong(Playlist &playlist){
    Node<Song> *aux = playlist.getSongs().getHead();
    while(aux != nullptr){
        this->removeSong(aux->getValue());
        aux = aux->getNext();
    }
}

/**
 * @brief Sobrecarga do operador de adição (+) para mesclar duas playlists.
 *
 * @param b A playlist que será mesclada com a playlist atual.
 * @return A nova playlist resultante da mesclagem.
 */
Playlist Playlist::operator+(Playlist &b){
    Playlist newPlaylist;
    Node<Song> *aux = this->getSongs().getHead();
    while(aux != nullptr){
        newPlaylist.addSong(aux->getValue());
        aux = aux->getNext();
    }
    aux = b.getSongs().getHead();
    while(aux != nullptr){
        if(newPlaylist.searchSong(aux->getValue()) == nullptr){
            newPlaylist.addSong(aux->getValue());
        }
        aux = aux->getNext();
    }
    return newPlaylist;
}

/**
 * @brief Sobrecarga do operador de adição (+) para adicionar uma música à playlist.
 *
 * @param song A música que será adicionada à playlist.
 * @return A nova playlist resultante da adição da música.
 */
Playlist Playlist::operator+(Song &song){
    Playlist newPlaylist;
    Node<Song> *aux = this->getSongs().getHead();
    while(aux != nullptr){
        newPlaylist.addSong(aux->getValue());
        aux = aux->getNext();
    }
    newPlaylist.addSong(song);
    return newPlaylist;
}

/**
 * @brief Sobrecarga do operador de subtração (-) para obter a diferença entre duas playlists.
 *
 * @param b A playlist que será subtraída da playlist atual.
 * @return A nova playlist resultante da diferença.
 */
Playlist Playlist::operator-(Playlist &b){
    Playlist newPlaylist;
    Node<Song> *aux = this->getSongs().getHead();
    while(aux != nullptr){
        if(b.searchSong(aux->getValue()) == nullptr){
            newPlaylist.addSong(aux->getValue());
        }
        aux = aux->getNext();
    }
    return newPlaylist;
}

/**
 * @brief Sobrecarga do operador de subtração (-) para remover uma música da playlist.
 *
 * @param song A música que será removida da playlist.
 * @return A nova playlist resultante da remoção da música.
 */
Playlist Playlist::operator-(Song &song){
    Playlist newPlaylist;
    Node<Song> *aux = this->getSongs().getHead();
    while(aux != nullptr){
        if(aux->getValue() != song){
            newPlaylist.addSong(aux->getValue());
        }
        aux = aux->getNext();
    }
    return newPlaylist;
}

/**
 * @brief Sobrecarga do operador de inserção (>>) para retirar a última música da playlist.
 *
 * @param song A música que receberá a última música retirada da playlist.
 */
void Playlist::operator>>(Song &song){
    Node<Song> *aux = this->getSongs().getHead();
    
        while(aux->getNext() != nullptr){
            aux = aux->getNext();
        }
        song = aux->getValue();
        this->removeSong(song);
}

/**
 * @brief Sobrecarga do operador de extração (<<) para adicionar uma música à playlist.
 *
 * @param song A música que será adicionada à playlist.
 */
void Playlist::operator<<(Song &song){
    if(song.operator==(song)){
        this->addSong(song);
    }
}

/**
 * @brief Construtor de cópia para criar uma nova playlist com base em outra playlist existente.
 *
 * @param playlist O ponteiro para a playlist que será copiada.
 */
Playlist::Playlist(Playlist *playlist){
    this->name = playlist->getName();
    Node<Song> *aux = playlist->getSongs().getHead();
    while(aux != nullptr){
        this->addSong(aux->getValue());
        aux = aux->getNext();
    }
}


