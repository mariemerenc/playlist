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

//Adicione um método capaz de sobrecarregar a função void addSong(Song song); que pertence ao objeto Playlist, tendo agora como parâmetro uma referência à outra Playlist. Ao fim do método, todos os elementos da lista recebida devem ser adicionados no fim da Playlist atual.
void Playlist::addSong(Playlist &playlist){
    Node<Song> *aux = playlist.getSongs().getHead();
    while(aux != nullptr){
        this->addSong(aux->getValue());
        aux = aux->getNext();
    }
}

//Adicione um método capaz de sobrecarregar a função void void removeSong(Song song); que pertence ao objeto Playlist, tendo agora como parâmetro uma referência à outra Playlist. Ao fim do método, todos os elementos da lista recebida devem ser removidos no fim da Playlist atual.
void Playlist::removeSong(Playlist &playlist){
    Node<Song> *aux = playlist.getSongs().getHead();
    while(aux != nullptr){
        this->removeSong(aux->getValue());
        aux = aux->getNext();
    }
}

//Implemente o operador + na classe Playlist, que une duas Playlists em uma nova Playlist. A nova Playlist deve conter todas as músicas das duas Playlists que estão sendo unidas e não deve conter músicas repetidas.
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

//Implemente uma versão sobrecarregada do operador + na classe Playlist, que recebe uma música como parâmetro e deve adicioná-la ao final de uma nova playlist, que é retornada como resultado do operador, pois a playlist original não pode ser alterada.
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

//Implemente o operador - na classe Playlist, que remove todas as músicas de uma Playlist que estão presentes em outra Playlist. A Playlist original não deve ser alterada.
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

//Implemente uma versão sobrecarregada do operador - na classe Playlist, que recebe uma música como parâmetro e deve removê-la de uma nova playlist, que é retornada como resultado do operador, pois a playlist original não pode ser alterada.

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

//Implemente o operador >> na classe Playlist, que reomve a última música da playlist atual e preenche na Música recebida como argumento. Caso não existam músicas na playlist, nullptr deve ser preenchido no parâmetro.
void Playlist::operator>>(Song &song){
    Node<Song> *aux = this->getSongs().getHead();
    
        while(aux->getNext() != nullptr){
            aux = aux->getNext();
        }
        song = aux->getValue();
        this->removeSong(song);
}

//Implemente o operador << na classe Playlist, que adiciona a Música recebida como argumento no final da playlist atual. Caso nullptr seja recebido, nada deve ser feito.
void Playlist::operator<<(Song &song){
    if(song.operator==(song)){
        this->addSong(song);
    }
}

//Implemente o construtor cópia da classe Playlist, que recebe uma Playlist como argumento e deve copiar todos os elementos da Playlist recebida para a Playlist atual.


//Implemente um construtor cópia de Playlist adequado para receber uma Playlist como argumento e deve copiar todos os elementos da Playlist recebida para a Playlist atual.
Playlist::Playlist(Playlist *playlist){
    this->name = playlist->getName();
    Node<Song> *aux = playlist->getSongs().getHead();
    while(aux != nullptr){
        this->addSong(aux->getValue());
        aux = aux->getNext();
    }
}


