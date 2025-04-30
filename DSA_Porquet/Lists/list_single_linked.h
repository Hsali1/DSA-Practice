#include <memory>
#include <cassert>

template <typename T>
class ListSingleLinked {
private:
    struct Node {
        T item;
        std::unique_ptr<Node> next = nullptr;
    };
    std::unique_ptr<Node> head = nullptr;
    unsigned int cur_size = 0;

    Node * GetNode(unsigned int pos){
        assert(pos < cur_size);

        Node* n = head.get();
        while(pos--){
            n = n->next.get();
        }
        return n;
    }
public:
    ListSingleLinked() = default;
    ~ListSingleLinked() = default;

    unsigned int Size(){
        return cur_size;
    }

    const T& Get(const unsigned int pos){
        if (pos >= cur_size){
            throw std::out_of_range("Position out of range!");
        }
        auto n = GetNode(pos);
        return n->item;
    }

    int Find(const T &item){
        int i = 0;
        for (auto n = head.get(); n; n = n->next.get(), i++){
            if (n->item == item){
                return i;
            }
        }
        return -1;
    }

    void Remove(const unsigned int pos){
        if (pos >= cur_size){
            throw std::out_of_range("Position out of range!");
        }
        if (!pos){
            // Remove from the top of list
            auto n = std::move(head);
            head = std::move(n->next);
        } else {
            // Remove after existing item(s)
            auto prev = GetNode(pos - 1);
            auto n = std::move(prev->next);
            prev->next = std::move(n->next);
        }
        cur_size--;
    }

    void Insert(const T &item, const unsigned int pos) {
        if (pos > cur_size){
            throw std::out_of_range("Position out of range!"); 
        }

        auto n = std::unique_ptr<Node> (new Node);
        n->item = item;

        if(!pos) {
            // Insert in front
            n->next = std::move(head);
            head = std::move(n);
        } else {
            // Insert after existing items
            auto prev = GetNode(pos - 1);
            n->next = std::move(prev->next);
            prev->next = std::move(n);
        }
        cur_size++;
    }
};