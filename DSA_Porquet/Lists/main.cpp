#include "ListFixedArray.h"

int main(){

    ListFixedArray<int> some_list;
    some_list.Insert(3, 0);
    some_list.Insert(4, 0);
    some_list.Insert(5, 0);

    // std::cout << "0: " << some_list.Get(0) << "\n";
    // std::cout << "1: " << some_list.Get(1) << "\n";
    // std::cout << "2: " << some_list.Get(2) << "\n";

    some_list.printAll();

    return 0;
}