#include "ListFixedArray.h"
#include "list_dynamic_array.h"
#include "list_single_linked.h"
int main(){

    ListFixedArray<int> some_list;
    some_list.Insert(3, 0);
    some_list.Insert(4, 0);
    some_list.Insert(5, 0);

    // std::cout << "0: " << some_list.Get(0) << "\n";
    // std::cout << "1: " << some_list.Get(1) << "\n";
    // std::cout << "2: " << some_list.Get(2) << "\n";

    // some_list.printAll();

    ListDynamicArray<int> some_list2;
    some_list2.Insert(3, 0);
    some_list2.Insert(4, 1);
    some_list2.Insert(5, 2);
    some_list2.printAll();

    std::cout << "Max capacity reached \n";

    some_list2.Insert(6, 3);
    some_list2.printAll();

    return 0;
}