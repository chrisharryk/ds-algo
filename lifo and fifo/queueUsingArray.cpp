#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Queue {
    public:
    int size;
    vector<int> Q;

    Queue() {
        size = 0;
        Q = {};
    }

    void print() {
        if (!size) {
            cout << "Empty Queue\n";
            return;
        }
        for (int x : Q) cout << x << " ";
        cout << '\n';
    }

    void push(int x) {
        Q.push_back(x);
        size++;
    }

    void pop() {
        if (!size) {
            cout << "Empty Queue\n";
            return;
        }
        if (size == 1) {
            Q = {};
            size--;
            return;
        }
        vector<int> newQ(size-1,0);
        for (int i = 1; i < size; i++) newQ[i-1] = Q[i];
        Q = newQ;
        size--;
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
    queue.push(4);
    queue.push(4);
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    queue.print();
    queue.empty();
}