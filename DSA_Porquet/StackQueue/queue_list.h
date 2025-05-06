#include <list>

template <typename T>
class Queue {
private:
    std::list<T> items;
public:
    unsigned int Size();
    T& Front();
    void Pop();
    void Push(const T &item);
};

template <typename T>
unsigned int Queue<T>::Size() {
    return items.size();
}

template <typename T>
T& Queue<T>::Front() {
    if (!items.size())
        throw std::underflow_error("Empty Queue!");
    return items.front();
}

template <typename T>
void Queue<T>::Pop() {
    if (!items.size())
        throw std::underflow_error("Empty Queue!");
    items.pop_front(); 
}

template <typename T>
void Queue<T>::Push(const T &item) {
    items.push_back(item);
}