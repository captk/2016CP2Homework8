/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: k
 *
 * Created on 5 October 2016, 3:57 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;
class Stack;

class Stack {

    struct Node {
        int value;
        Node* next;
    };
public:

    Stack() {
        top_ = NULL;
    }

    bool empty() const {
        return top_ == NULL;
    }

    int top() const {
        return top_->value;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        if(this->empty()){
            newNode->next = NULL;
            top_ = newNode;
        }
        else{
            newNode->next = top_;
            top_ = newNode;
        }
    }
    int pop(){
        int result = top_->value;
        Node* oldTop = top_;
        top_ = top_->next;
        
        delete oldTop;
        return result;
    }
private:
    Node* top_;
};

int main() {
    Stack s; // top line in diagram 
    cout << s.empty() << endl; // display "true" 
    s.push(42);
    s.push(666); // middle line 
    cout << s.top() << endl; // display "666" 
    int n = s.pop(); // bottom line 
    cout << n << " " << s.top() << endl; // display "666 42" 
} 