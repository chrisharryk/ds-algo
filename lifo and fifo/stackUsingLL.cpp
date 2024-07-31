#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node {
    public:
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Stack {
    public:
    int size;
    Node *top;
    
    Stack() {
        size = 0;
        top = NULL;
    }

    void print() {
        Node *t = top;
        while (t) {
            cout << t->val << " ";
            t = t->next;
        }
        cout << '\n';
    }

    void push(int x) {
        if (!size) {
            top = new Node(x);
            size++;
            return;
        }
        Node *tmp = new Node(x);
        tmp->next = top;
        top = tmp;
        size++;
    }

    void pop() {
        if (!top) {
            cout << "Empty stack\n";
            return;
        }
        if (!top->next) {
            top = NULL;
            size = 0;
            return;
        }
        top = top->next;
        size--;
    }

    void empty() {
        if (size) cout << "false\n";
        else cout << "true\n";
    }
};

int main() {
    Stack stack = Stack();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.print();
    stack.pop();
    stack.pop();
    stack.print();
    stack.empty();
}