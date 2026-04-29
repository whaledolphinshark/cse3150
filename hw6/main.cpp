#include <iostream>
#include "linked_list_raw.hpp"
#include "linked_list_unique.hpp"
#include "doubly_linked_list_shared.hpp"
#include "doubly_linked_list_weak.hpp"

using std::cout;

int main() {
    {
        cout << "raw\n";
        LinkedListRaw list;
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        list.print(std::cout);
    }

    {
        cout << "unique\n";
        LinkedListUnique list;
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        list.print(std::cout);
    }

    {
        cout << "shared\n";
        DoublyLinkedListShared list;
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        list.print_forward(std::cout);
    }

    {
        cout << "weak\n";
        DoublyLinkedListWeak list;
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        list.print_forward(std::cout);
        list.print_backward(std::cout);
    }

    return 0;
}
