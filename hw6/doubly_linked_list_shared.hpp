#pragma once
#include <iostream>
#include <memory>

class DoublyLinkedListShared {
private:
    struct Node {
        int value;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;

        Node(int value) : value(value), next(nullptr), prev(nullptr) {}
        ~Node(){
            std::cout << "Destroying node " << value << "\n";
        }
    };

    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;

public:
    DoublyLinkedListShared() = default;
    ~DoublyLinkedListShared() = default;

    DoublyLinkedListShared(const DoublyLinkedListShared&) = delete;
    DoublyLinkedListShared& operator=(const DoublyLinkedListShared&) = delete;

    void push_back(int value) {
        auto newNode = std::make_shared<Node>(value);

        if (head_ == nullptr) {
            head_ = tail_ = newNode;
        } else {
            tail_->next = newNode;
            newNode->prev = tail_;
            tail_ = newNode;
        }
    }

    void print_forward(std::ostream& os) const {
        auto current = head_;
        while (current != nullptr) {
            os << current->value << " ";
            current = current->next;
        }
        os << '\n';
    }
};
