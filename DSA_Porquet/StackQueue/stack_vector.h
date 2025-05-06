template <typename T>
class Stack {
private:
    std::vector<T> items;
    
public:
    unsigned int Size();
    T& Top(void);
    void Pop();
    void Push(const T &item);
};

template <typename T>
unsigned int Stack<T>::Size() {
    return items.size();
}

template <typename T>
T& Stack<T>::Top(void) {
    if (!items.size())
        throw std::underflow_error("Emoty Stack!");
    return items.back();
}

template <typename T>
void Stack<T>::Pop() {
    if (!items.size())
        throw std::underflow_error("Emoty Stack!");
    items.pop_back();
}

template <typename T>
void Stack<T>::Push(const T &item) {
    items.push_back(item);
}
