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

    void insert(T value){
        //add at end
        Node *newNode = new Node(value, sentinel->prev, sentinel);
        sentinel->prev->next = newNode;
        sentinel->prev = newNode;
    }

    bool insert(T key){
        Node *cur = search(key);
        if (cur==nullptr)
            return false;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        free(cur);
        return true;
    }

    Node* search(T key){
        // set sentinel's value to key
        sentinel->value = key;
        Node *cur = sentinel->next;
        while (cur->value.equal(key))
            cur = cur->next;
        if(cur == sentinel)
            return nullptr;
        return cur;
    }

    ~DoublyLinkedList(){
        free(sentinel);
    }
};

