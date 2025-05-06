#include <list>

template <typename T>
class Stack {
private:
    unsigned int cur_size = 0;
    std::forward_list<T> items;
public:
    unsigned int Size();
    T& Top(void);
    void Pop();
    void Push(const T &item);
};

template <typename T>
unsigned int Stack<T>::Size(){
    if (!cur_size)
        throw std::underflow_error("Empty Stack!");
    return cur_size;
}

template <typename T>
T& Stack<T>::Top(void) {
    if (!cur_size)
        throw std::underflow_error("Empty Stack!");
    return items.front();
}

template <typename T>
void Stack<T>::Pop(){
    if (!cur_size)
        throw std::underflow_error("Empty Stack!");
    items.pop_front();
    cur_size--;
}

template <typename T>
void Stack<T>::Push(const T &item){
    items.push_front(item);
    cur_size++;
}
