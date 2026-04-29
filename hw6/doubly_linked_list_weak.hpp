#pragma once
#include <iostream>
#include <memory>

class DoublyLinkedListWeak {
private:
    struct Node {
        int value;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;

        Node(int value) : value(value), next(nullptr), prev() {}

        ~Node() {
            std::cout << "Destroying node " << value << "\n";
        }
    };

    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;

public:
    DoublyLinkedListWeak() = default;
    ~DoublyLinkedListWeak() = default;

    DoublyLinkedListWeak(const DoublyLinkedListWeak&) = delete;
    DoublyLinkedListWeak& operator=(const DoublyLinkedListWeak&) = delete;

    void push_back(int value) {
        auto newNode = std::make_shared<Node>(value);

        if (head_ == nullptr) {
            head_ = tail_ = newNode;
        } else {
            newNode->prev = tail_;
            tail_->next = newNode;
            tail_ = newNode;
        }
    }

    void print_forward(std::ostream& os) const {
        auto current = head_;
        while (current != nullptr) {
            os << current->value << " ";
            current = current->next;
        }
        os << "\n";
    }

    void print_backward(std::ostream& os) const {
        auto current = tail_;
        while (current != nullptr) {
            os << current->value << " ";
            current = current->prev.lock();
        }
        os << "\n";
    }
};
