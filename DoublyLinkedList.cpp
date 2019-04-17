#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T value;
    Node *next;
    Node *prev;
    Node(T value, Node *prev, Node *next)
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
    Node<T>* sentinel;
public:
    DoublyLinkedList(){
        sentinel = new Node<T>(-1,nullptr,nullptr);
        sentinel->next = sentinel;
        sentinel->prev = sentinel;
    }

    void insert(T value){
        //add at end
        Node<T> *newNode = new Node<T>(value, sentinel->prev, sentinel);
        sentinel->prev->next = newNode;
        sentinel->prev = newNode;
    }

    void print(){
        Node<T> *cur = sentinel->next;
        while (cur!= sentinel)
        {
            cout << cur->value << " <==> ";
            cur = cur->next;
        }
        cout << endl;
        return;
    }

    bool delet(T key){
        Node<T> *cur = search(key);
        if (cur==nullptr)
            return false;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        free(cur);
        return true;
    }

    Node<T>* search(T key){
        // set sentinel's value to key
        sentinel->value = key;
        Node<T> *cur = sentinel->next;
        while (cur->value!=key)
            cur = cur->next;
        if(cur == sentinel)
            return nullptr;
        return cur;
    }

    ~DoublyLinkedList(){
        free(sentinel);
    }
};

