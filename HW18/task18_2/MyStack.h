#pragma once
#include <stdexcept>
#include <iostream>

namespace MySpace {

    template <typename T>
    struct Node {
        T data;
        Node* next;
        Node(T val) : data(val), next(nullptr) {}
    };

    template <typename T>
    class Stack {
    private:
        Node<T>* topNode; 
        size_t count;

    public:
        Stack() : topNode(nullptr), count(0) {}

        // Destructor
        ~Stack() {
            while (!empty()) {
                pop();
            }
        }

        // Add elem
        void push(T value) {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = topNode;
            topNode = newNode;
            count++;
        }

        // DDelete elem
        void pop() {
            if (empty()) {
                throw std::out_of_range("Stack is empty");
            }
            Node<T>* temp = topNode;
            topNode = topNode->next;
            delete temp;
            count--;
        }

        T top() const {
            if (empty()) {
                throw std::out_of_range("Stack is empty");
            }
            return topNode->data;
        }

        bool empty() const {
            return topNode == nullptr;
        }

        size_t size() const {
            return count;
        }
    };
}