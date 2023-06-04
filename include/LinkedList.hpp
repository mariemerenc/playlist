/**
 * @file LinkedList.hpp
 * @brief Arquivo que contém a classe LinkedList.
 */

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include "Song.hpp"
#include "Node.hpp"

/**
 * @brief Classe que implementa uma lista encadeada template.
 * 
 * @tparam T Tipo do valor armazenado na lista.
 */
template <typename T>
class LinkedList{

private:
    Node<T> *head; //!< Ponteiro para o primeiro elemento da lista
    Node<T> *tail; //!< Ponteiro para o último elemento da lista

public:
    // Construtor da lista encadeada. 
    LinkedList();
    LinkedList(const LinkedList<T>& otherList);
    ~LinkedList();
    // Remove todos os elementos da lista. 
    void clear();
    // Retorna o tamanho da lista encadeada. 
    size_t getSize() const;
    // Retorna a cabeça da lista. 
    Node<T> *getHead();
    // Retorna a cauda da lista. 
    Node<T> *getTail();
    // Altera o ponteiro cabeça da lista. 
    void setHead(Node<T> *head);
    // Altera o ponteiro cauda da lista. 
    void setTail(Node<T> *tail);
    // Adiciona um novo elemento com valor especificado ao final da lista. 
    void add(T value);
    // Procura um elemento específico na lista. 
    T *searchValue(T value);
    // Remove o elemento especificado da lista. 
    void removeValue(T value);
    // Imprime todos os elementos da lista recursivamente. 
    void print();
    //blablabla
    void addList(LinkedList<T>& otherList);
    //adlkfjs
    void removeList(LinkedList<T>& otherList);
    //abalbl
    //template <typename T>
    //LinkedList<T> LinkedList(const LinkedList<T>& otherList);
    //afsjgpçlask
    LinkedList<T> operator+(LinkedList<T>& otherList);
    //slkdfgj
    LinkedList<T> operator-(LinkedList<T>& otherList);
    //
    friend std::istream& operator>>(std::istream& is, LinkedList<T>& list);
    //sçgfjspkad
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list);

    bool operator!=(T &b);
    
    bool operator==(T &b);

    void operator=(T &b);
};

/**
 * @brief Construtor da lista encadeada.
 * 
 * 
 */
template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

/**
 * @brief Destrutor da lista encadeada, que remove todos os elementos.
 */
template <typename T>
LinkedList<T>::~LinkedList(){
    clear();
}

/**
 * @brief Remove todos os elementos da lista.
 */
template <typename T>
void LinkedList<T>::clear(){
    Node<T> *prev = nullptr;
    Node<T> *curr = head;

    while(curr != nullptr){
        prev = curr;
        curr = curr->getNext();
        delete prev;
    }
    head = nullptr;
    tail = nullptr;
}

/**
 * @brief Retorna o tamanho da lista encadeada.
 * 
 * @return Tamanho da lista.
 */
template <typename T>
size_t LinkedList<T>::getSize() const{
    size_t size = 0;
    Node<T> *curr = head;

    while(curr != nullptr){
        curr = curr->getNext();
        size++;
    }
    return size;
}

/**
 * @brief Retorna a cabeça da lista.
 * 
 * @return Ponteiro para o primeiro elemento da lista.
 */
template <typename T>
Node<T> *LinkedList<T>::getHead(){
    return head;
}

/**
 * @brief Retorna a cauda da lista.
 * 
 * @return Ponteiro para o último elemento da lista.
 */
template <typename T>
Node<T> *LinkedList<T>::getTail(){
    return tail;
}

/**
 * @brief Altera o ponteiro cabeça da lista.
 * 
 * @param head Novo ponteiro.
 */
template <typename T>
void LinkedList<T>::setHead(Node<T> *head){
    this->head = head;
}

/**
 * @brief Altera o ponteiro cauda da lista.
 * 
 * @param tail Novo ponteiro.
 */
template <typename T>
void LinkedList<T>::setTail(Node<T> *tail){
    this->tail = tail;
}

/**
 * @brief Adiciona um novo elemento com valor especificado ao final da lista.
 * 
 * @param value Valor a ser adicionado.
 */
template <typename T>
void LinkedList<T>::add(T value){
    Node<T> *newNode = new Node<T>(value);

    // Verifica se a lista é vazia
    if(head == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->setNext(newNode);
        tail = newNode;
    }
}

/**
 * @brief Procura um elemento específico na lista. 
 * 
 * 
 * @param value Valor a ser buscado.
 * @return Retorna o ponteiro para o valor, caso ele esteja na lista, ou nullptr, caso contrário.
 */
template <typename T>
T *LinkedList<T>::searchValue(T value){
    Node<T> *curr = head;

    while(curr != nullptr){
        if(curr->getValue() == value){
            return &(curr->getValue());
        }
        curr = curr->getNext();
    }
    return nullptr;
}

/**
 * @brief Remove o elemento especificado da lista.
 * 
 *
 * @param value Valor a ser removido.
 */
template <typename T>
void LinkedList<T>::removeValue(T value){
    Node<T> *curr = head;
    Node<T> *prev = nullptr;

    while(curr != nullptr){
        if(curr->getValue() == value){
            if(prev != nullptr){
                prev->setNext(curr->getNext());
                if(curr == tail){
                    tail = prev;
                }
            }
            else{
                head = curr->getNext();
                if(head == nullptr){
                    tail = nullptr;
                }
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->getNext();
    }
}


/**
 * @brief Imprime todos os elementos da lista recursivamente.
 */
template <typename T>
void LinkedList<T>::print(){
    printAux(head);
}

/**
 * @brief Auxiliar para a função print. Imprime a lista recursivamente a partir
 * do elemento especificado.
 * 
 * @param curr Primeiro elemento da lista a ser impresso.
 */
template <typename T>
void printAux(Node<T> *curr){
    if(curr != nullptr){
        std::cout << curr->getValue() << std::endl;
        printAux(curr->getNext());
    }
}

// Adiciona todos os elementos da lista recebida à lista atual
template <typename T>
void LinkedList<T>::addList(LinkedList<T>& otherList) {
    Node<T>* curr = otherList.head;

    while (curr != nullptr) {
        add(curr->getValue());
        curr = curr->getNext();
    }
}

// Remove os elementos da lista recebida da lista atual
template <typename T>
void LinkedList<T>::removeList(LinkedList<T>& otherList) {
    Node<T>* curr = otherList.head;

    while (curr != nullptr) {
        removeValue(curr->getValue());
        curr = curr->getNext();
    }
}

// Construtor cópia que retorna uma cópia da lista recebida como parâmetro
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherList) {
    head = nullptr;
    tail = nullptr;

    Node<T>* curr = otherList.head;

    while (curr != nullptr) {
        add(curr->getValue());
        curr = curr->getNext();
    }
}

// Sobrecarga do operador "+" para a concatenação de duas listas
template <typename T>
LinkedList<T> LinkedList<T>::operator+(LinkedList<T>& otherList) {
    LinkedList<T> result(*this);

    Node<T>* curr = otherList.head;
    while (curr != nullptr) {
        result.add(curr->getValue());
        curr = curr->getNext();
    }

    return result;
}

template <typename T>
std::istream& operator>>(std::istream& is, LinkedList<T>& list) {
    T value;
    is >> value;
    list.add(value);
    return is;
}

/**
 * @brief Sobrecarga do operador de inserção "<<" para a classe LinkedList.
 * 
 * @tparam T Tipo do valor armazenado na lista.
 * @param os O fluxo de saída.
 * @param list A lista encadeada.
 * @return O fluxo de saída.
 */
template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
    Node<T>* curr = list.getHead();

    while (curr != nullptr) {
        os << curr->getValue() << " ";
        curr = curr->getNext();
    }

    return os;
}

template <typename T>
LinkedList<T> LinkedList<T>::operator-(LinkedList<T>& otherList){
    LinkedList<T> result(*this);

    Node<T>* curr = otherList.head;
    while (curr != nullptr) {
        result.removeValue(curr->getValue());
        curr = curr->getNext();
    }

    return result;

}

#endif