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

class LinkedList {
    public:
    int size;
    Node *head;

    LinkedList() {
        this->size = 0;
        this->head = NULL;
    }

    void addAtHead(int val) {
        Node *tmp = new Node(val);
        if (!this->head) {
            this->head = tmp;
            this->size++;
            return;
        }
        tmp->next = this->head;
        this->head = tmp;
        this->size++;
    }

    void addAtTail(int val) {
        Node *tmp = new Node(val);
        if (!this->head) {
            this->head = tmp;
            this->size++;
            return;
        }
        Node *h = this->head;
        while (h->next) h = h->next;
        h->next = tmp;
        this->size++;
    }

    void addAtNthIndex(int idx, int val) {
        if (idx == 0) {
            addAtHead(val);
            return;
        } else if (idx == size) {
            addAtTail(val);
            return;
        }
        Node *h = this->head;
        for (int i = 1; i < idx; i++)  h = h->next;
        Node *nxt = h->next;
        h->next = new Node(val);
        h = h->next;
        h->next = nxt;
        this->size++;
    }

    void deleteAtHead() {
        if (!this->head) {
            cout << "Empty list";
            return;
        }
        this->head = this->head->next;
        this->size--;
    }

    void deleteAtTail() {
        if (!this->head) {
            cout << "Empty list";
            return;
        }
        while (this->head->next->next) {
            this->head = this->head->next;
        }
        this->head->next = NULL;
        this->size--;
    }

    void deleteAtNthIndex(int idx) {
        if (idx == 0) {
            deleteAtHead();
            return;
        } else if (idx == this->size-1) {
            deleteAtTail();
            return;
        }
        Node *h = this->head;
        for (int i = 1; i < idx; i++) h = h->next;
        h->next = h->next->next;
        this->size--;
    }
     
    void printList() {
        Node *h = this->head;
        if (!h) {
            cout << "Empty list\n"; return;
        }
        while (h) {
            cout << h->val << " ";
            h = h->next;
        }
    }
};

int main() {
    LinkedList list = LinkedList();
    // insertion
    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtNthIndex(1, 2);
    // deletion
    list.deleteAtHead();
    list.deleteAtTail();
    list.deleteAtNthIndex(0);
    list.printList();
}