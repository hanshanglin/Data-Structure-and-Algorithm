#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T value;
    Node *next;
    Node(T value, Node *next)
    {
        this->value = value;
        this->next = next;
    }
    ~Node();
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert(T value)
    {
        if (head == nullptr)
        {
            head = new Node<T>(value, nullptr);
            return;
        }
        //insert at head O(1)
        head = new Node<T>(value, head);
        return;
    }

    void printList()
    {
        Node<T> *cur = head;
        while (cur != nullptr)
        {
            cout << cur->value << " -> ";
            cur = cur->next;
        }
        cout << "null" << endl;
    }

    Node* search(T key)
    {
        if (head == nullptr)
            return false;
        Node *cur = head;
        while (cur != nullptr)
        {
            if (cur->value == key)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }

    bool delet(T key)
    {
        if (head == nullptr)
            return false;
        if (head->value == key)
        {
            Node<T> *temp = head->next;
            free(head);
            head = temp;
            return true;
        }
        Node<T> *cur_ptr = head;
        while (cur_ptr->next != nullptr)
        {
            if (cur_ptr->next->value == key)
            {
                Node<T> *temp = cur_ptr->next;
                cur_ptr->next = cur_ptr->next->next;
                free(temp);
                return true;
            }
            cur_ptr = cur_ptr->next;
        }
        return false;
    }
};
