#pragma once

class LinkedListRaw {
private:
    struct Node {
        int value;
        Node* next;
        
        Node(int value) : value(value), next(nullptr) {}
    };
    Node* head_;
    Node* tail_;
public:
        LinkedListRaw() : head_(nullptr), tail_(nullptr) {}
        ~LinkedListRaw(){
            Node *node = head_;
            while (node != nullptr){
                Node *temp = node;
                node = node->next;
                delete temp;
            }
        };
        
        LinkedListRaw(const LinkedListRaw&) = delete;
        LinkedListRaw& operator=(const LinkedListRaw&) = delete;
        
        void push_back(int value){
            if (head_ == nullptr){
                head_ = new Node(value);
                return;
            }

            Node *node = head_;
            while (node->next != nullptr){
                node = node->next;
            }
            node->next = new Node(value);
        };
        void print(std::ostream& os) const{
            Node *node = head_;
            while (node != nullptr){
                os << node->value << " ";
                node = node->next;
            }
            os << "\n";
        };
};
