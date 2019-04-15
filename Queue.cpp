#include <iostream>
#include <vector>
using namespace std;
class Queue
{
private:
    int capacity;
    int head;
    int tail;
    int* queue_container;

public:
    Queue(int capacity=20){
        this->capacity = capacity+1;
        queue_container = new int[this->capacity];
        head = 0;
        tail = 0;
    }

    inline bool isEmpty(){
        return head == tail;
    }

    void enqueue(int value){
        //overflow
        if ((tail + 1) % capacity == head)
        {
            cout << "error: queue over flow" << endl;
            return;
        }
        queue_container[tail] = value;
        tail = (tail + 1) % capacity;
    }

    int dequeue(){
        //underflow
        if(isEmpty())
            return -1;
        int sol = queue_container[head];
        head = (head + 1) % capacity;
        return sol;
    }

    ~Queue(){
        free(queue_container);
    }
};
