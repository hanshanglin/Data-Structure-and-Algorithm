#include <iostream>
#include "LinkedList.cpp"
using namespace std;
int main()
{
    LinkedList<int> list;
    list.insert(15);
    list.insert(12);
    list.insert(15);
    list.insert(156);
    list.insert(123);
    list.printList();
    list.delet(15);
    list.delet(12);
    list.printList();
    return 0;
}