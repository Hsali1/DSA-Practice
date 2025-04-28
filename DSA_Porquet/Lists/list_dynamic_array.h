#include <memory>
#include <cassert>

template <typename T>
class ListDynamicArray {
private:
    unsigned int capacity = 3;   // Initial capacity
    std::unique_ptr<T[]> items; // smart pointer managing array of T
    unsigned int cur_size = 0;  // how many items are currently stored

public:
    ListDynamicArray() 
        : items(std::unique_ptr<T[]>(new T[capacity])) {}
    ~ListDynamicArray() = default;

    void Resize(unsigned int new_cap){
        // for checking internal invariants
        assert(new_cap && new_cap >= cur_size);

        std::unique_ptr<T[]> new_items(new T[new_cap]);
        // Moves elements from [start, end) into dest.
        std::move(
            items.get(),
            std::next(items.get(),cur_size),
            new_items.get());
        std::swap(items, new_items);
        capacity = new_cap;
    }

    void Insert(const T &item, const unsigned int pos){
        if (pos > cur_size){
            throw std::out_of_range("Position out of range!");
        }
        if (cur_size == capacity){
            Resize(2 * capacity);
        }
        if (pos != cur_size){
            auto i = cur_size - 1;
            do {
                items[i + 1] = items[i];
            } while (i-- != pos);
        }
        items[pos] = item;
        cur_size++;
    }

    void remove(const unsigned int pos){
        if (pos >= cur_size){
            throw std::out_of_range("Position out of range!");
        }
        for (auto i = pos + 1; i < cur_size; i++){
            items[i - 1] = items[i];
        }
        cur_size--;
        if (cur_size <= capacity / 4){
            Resize(capacity / 2);
        }
    }

    void printAll(){
        if (cur_size == 0){
            std::cout << "List is empty\n";
        }
        for (unsigned int i = 0; i < cur_size; i++){
            std::cout << items[i] << "\n";
        }
    }
};