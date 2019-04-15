#include <iostream>
#include <vector>
using namespace std;
class Stack
{
private:
    int capacity;
    int top;
    int* stack_container;

public:
    Stack(int capacity=20){
        this->capacity =  capacity;
        stack_container = new int[capacity];
        top = -1;
    }

    inline bool isEmpty(){
        return top==-1;
    }

    int peek(){
        if (isEmpty())
            return -1;
        return stack_container[top];
    }

    int pop(){
        if (isEmpty())
            return -1;
        top--;
        return stack_container[top+1];
    }
    void push(int value){
        //overflow
        if(top == capacity-1){
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        stack_container[top] = value;
    }

    ~Stack(){
        free(stack_container);
    }
};
