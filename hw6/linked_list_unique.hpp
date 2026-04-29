#pragma once
#include <iostream>
#include <memory>

class LinkedListUnique {
private:
    struct Node {
        int value;
        std::unique_ptr<Node> next;

        Node(int value) : value(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head_;

public:
    LinkedListUnique() : head_(nullptr) {}
    ~LinkedListUnique() = default;

    LinkedListUnique(const LinkedListUnique&) = delete;
    LinkedListUnique& operator=(const LinkedListUnique&) = delete;

    void push_back(int value) {
        if (head_ == nullptr) {
            head_ = std::make_unique<Node>(value);
            return;
        }

        Node *current = head_.get();
        while (current->next != nullptr) {
            current = current->next.get();
        }

        current->next = std::make_unique<Node>(value);
    }

    void print(std::ostream& os) const {
        const Node *current = head_.get();
        while (current != nullptr) {
            os << current->value << " ";
            current = current->next.get();
        }
        os << "\n";
    }
};
