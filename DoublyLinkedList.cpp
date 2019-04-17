#include <iostream>
template <class T>
class Node
{
public:
    T value;
    Node *next;
    Node *prev;
    Node(T value, Node *next, Node *prev)
    {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }
    ~Node();
};

template <class T>
class DoublyLinkedList
{
private:
    Node* sentinel;
public:
    DoublyLinkedList(){
        sentinel = new Node();
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
    }

    insert(T value){
        //add at end
        Node *newNode = new Node(value, sentinel->prev, sentinel);
        sentinel->prev->next = newNode;
        sentinel->prev = newNode;
    }

    
    ~DoublyLinkedList(){
        free(sentinel);
    }
};

