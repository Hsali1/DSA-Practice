#include <iostream>
#include <array>
template <typename T>
class ListFixedArray {
  private:
    // fixed capacity of 3 items
    static constexpr int capacity = 3;
    std::array<T, capacity> items;
    unsigned int curr_size = 0;
  public:
    ListFixedArray() = default;
    ~ListFixedArray() = default;

    unsigned int size(){
        return curr_size;
    }

    const T& Get(const unsigned int pos){
        if (pos >= curr_size)
            throw std::out_of_range("Position out of range!");
        return items[pos];
    }

    void printAll(){
        if (curr_size == 0){
            std::cout << "List is empty\n";
        }
        for (unsigned int i = 0; i < curr_size; i++){
            std::cout << items[i] << "\n";
        }
    }

    int Find(const T &item){
        for (unsigned int i = 0; i < curr_size; i++){
            if (items[i] == item){
                return i;
            }
        }
        return -1;
    }

    void Remove(const unsigned int pos){
        if (pos >= curr_size){
            throw std::out_of_range("Position out of range!");
        }

        for (auto i = pos + 1; i < curr_size; i++){
            items[i - 1] = items[i];
        }
        curr_size--;
    }

    void Insert(const T &item, const unsigned int pos){
        if (pos > curr_size){
            throw std::out_of_range("Position out of range!");
        }
        if (curr_size == capacity){
            throw std::overflow_error("List full!");
        }
        if (pos != curr_size){
            // Move existing items(s) if insertion before them
            auto i = curr_size - 1;
            do {
                items[i + 1] = items[i];
            } while (i-- != pos);
        }
        items[pos] = item;
        curr_size++;
    }
};