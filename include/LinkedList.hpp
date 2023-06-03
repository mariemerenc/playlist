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
    //Adiciona todos os elementos da lista passada por referência à lista atual
    void addElements(const LinkedList<T>& otherList):
    //Remove todos os elementos da lista passada por referência da lista atual
    void removeElements(const LinkedList<T>& removeList);
    //Retorna uma cópia da lista passada por referência
    LinkedList(const LinkedList<T>& otherlist);
    //Sobrecarrega o operador +
    LinkedList operator+(const LinkedList<T>& list1, const LinkedList<T>& list2);
    //Sobrecarga do operador >>
    LinkedList operator>>(const T* data, LinkedList<T>& list1);
    //Sobrecarga do operador <<
    LinkedList operator<<(const T* data, LinkedList<T>& list);
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

 
template <typename T>
void LinkedList<T>::addElements(const LinkedList<T>& otherList) {
    Node<T>* currentNode = otherList.head;

    while (currentNode != nullptr) {
        add(currentNode->data);
        currentNode = currentNode->next;
    }
}


template <typename T>
void LinkedList<T>::removeElements(const LinkedList<T>& removeList) {
    Node<T>* currentNode = removeList.head;

    while (currentNode != nullptr) {
        removeValue(currentNode->data);
        currentNode = currentNode->next;
    }
}


template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherList) {
    head = nullptr;
    tail = nullptr;

    Node<T>* currentNode = otherList.head;

    while (currentNode != nullptr) {
        add(currentNode->data);
        currentNode = currentNode->next;
    }
}


template <typename T>
LinkedList<T> operator+(const LinkedList<T>& list1, const LinkedList<T>& list2) {
    LinkedList<T> result = list1;

    result.addElements(list2);

    return result;
}


template <typename T>
LinkedList<T>& operator>>(const T* data, LinkedList<T>& list) {
    if (data == nullptr) {
        return list;
    }

    list.add(*data);
    return list;
}


template <typename T>
LinkedList<T>& operator<<(LinkedList<T>& list, const T* data) {
    if (data != nullptr) {
        list.add(*data);
    }

    return list;
}


#endif
