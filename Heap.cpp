template <class T>
class Heap
{
private:
    T* container;
    int size;
    int end;
    void adjust_up();
    void adjust_down();
    void swap();
public:
    Heap(int size);
    ~Heap();
};

Heap::Heap(int size){
        this->container = new T[size];
        this->size  = size;
        this->end = 0;
}
void Heap::~Heap(){
    free(this->container);
}

void Heap::swap(int a,int b){
    T temp = container[a];
    container[a] = container[b];
    container[b] = temp;
}

void Heap::adjust_up(int cur){
    if(cur<=0 || cur>=end)
        return;
    int parent = (cur-1)/2;
    if(container[parent] > container[cur]){
        Heap::swap(parent,cur);
    }
    return;
}

void Heap::adjust_down(int cur){
    left_child = cur*2+1;
    right_child = left_child +1;
    
}