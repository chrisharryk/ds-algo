#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Stack {
    public:
    vector<int> S;
    int size;
    
    Stack() {
        S = {};
        size = 0;
    }

    void print() {
        for (int i = size-1; i >= 0; i--)
            cout << S[i] << " ";
        cout << '\n';
    }

    void push(int x) {
        S.push_back(x);
        size++;
    }

    void pop() {
        if (!size) {
            cout << "Empty stack";
            return;
        }
        S.erase(S.end()-1);
        size--;
    }

    void empty() {
        if (size) cout << "false";
        else cout << "true";
        cout << '\n';
    }
};

int main() {
    Stack stack = Stack();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.pop();
    stack.empty();
    stack.print();
}