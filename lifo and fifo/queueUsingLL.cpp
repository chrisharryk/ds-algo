#include <bits/stdc++.h>
#define MOD 1000000007
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

class Queue {
    public:
    int size;
    Node *front;

    Queue() {
        size = 0;
        front = NULL;
    }

    void push(int x) {
        if (!size) {
            front = new Node(x);
            size++;
            return;
        }
        Node *f = front;
        while (f->next) f = f->next;
        f->next = new Node(x);
        size++;
    }

    void pop() {
        if (!size) {
            cout << "Empty queue\n";
            return;
        }
        if (size == 1) {
            front = NULL;
            size = 0;
            return;
        }
        front = front->next;
        size--;
    }

    void print() {
        Node *f = front;
        while (f) {
            cout << f->val << " ";
            f = f->next;
        }
        cout << '\n';
    }

    void empty() {
        if (size) cout << "false\n";
        else cout << "true\n";
    }
};

int main() {
    Queue queue = Queue();
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.pop();
    queue.print();
    queue.empty();
}