#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node {
    public:
    int val;
    Node *next, *prev;
    
    Node(int val) {
        this->val = val;
        this->next = this->prev = NULL;
    }
};

class DoublyLinkedList {
    public:
    int size;
    Node *head, *tail;
    
    DoublyLinkedList() {
        this->size = 0;
        this->head = this->tail = NULL;
    }

    void printListFromHead() {
        if (!this->head) {
            cout << "Empty list";
            return;
        }
        Node *h = this->head;
        while (h) {
            cout << h->val << " ";
            h = h->next;
        }
    }

    void printListFromTail() {
        if (!this->tail) {
            cout << "Empty list";
            return;
        }
        Node *t = this->tail;
        while (t) {
            cout << t->val << " ";
            t = t->prev;
        }
    }

    void addAtHead(int val) {
        Node *tmp = new Node(val);
        if (!this->head) {
            this->head = this->tail = tmp;
            this->size++;
            return;
        }
        tmp->next = this->head;
        this->head->prev = tmp;
        this->head = tmp;
        this->size++;
    }

    void addAtTail(int val) {
        Node *tmp = new Node(val);
        if (!this->tail) {
            this->tail = this->head = tmp;
            this->size++;
            return;
        }
        tmp->prev = this->tail;
        this->tail->next = tmp;
        this->tail = tmp;
        this->size++;
    }

    void addATNthNodeFromHead(int idx, int val) {
        if (idx == 0) {
            addAtHead(val);
            return;
        } else if (idx == size) {
            addAtTail(val);
            return;
        }
        Node *h = this->head;
        for (int i = 1; i < idx; i++) h = h->next;
        Node *nxt = h->next, *tmp = new Node(val);
        h->next = tmp;
        tmp->prev = h;
        tmp->next = nxt;
        nxt->prev = tmp;
        this->size++;
    }

    void addATNthNodeFromTail(int idx, int val) {
        if (idx == 0) {
            addAtTail(val);
            return;
        } else if (idx == size) {
            addAtHead(val);
            return;
        }
        Node *t = this->tail;
        for (int i = 1; i < idx; i++) t = t->prev;
        Node *prv = t->prev, *tmp = new Node(val);
        t->prev = tmp;
        tmp->next = t;
        prv->next = tmp;
        tmp->prev = prv;
        this->size++;
    }

    void deleteAtHead() {
        if (!this->head) {
            cout << "Empty list";
            return;
        }
        if (this->size == 1) {
            this->head = this->tail = NULL;
            this->size = 0;
            return;
        }
        this->head = this->head->next;
        this->head->prev = NULL;
        this->size--;
    }

    void deleteAtTail() {
        if (this->size == 0) {
            cout << "Empty list";
            return;
        }
        if (this->size == 1) {
            this->head = this->tail = NULL;
            this->size = 0;
            return;
        }
        this->tail = this->tail->prev;
        this->tail->next = NULL;
        this->size--;
    }

    void deleteAtNthIndexFromHead(int idx) {
        if (idx == 0) {
            deleteAtHead();
            return;
        } else if (idx == this->size-1) {
            deleteAtTail();
            return;
        }
        Node *h = this->head;
        for (int i = 0; i < idx; i++) h = h->next;
        Node *cur = h;
        Node *prv = cur->prev, *nxt = cur->next;
        prv->next = nxt;
        nxt->prev = prv;
        this->size--;
    }

    void deleteAtNthIndexFromTail(int idx) {
        if (idx == 0) {
            deleteAtTail();
            return;
        } else if (idx == this->size-1) {
            deleteAtHead();
            return;
        }
        Node *t = this->tail;
        for (int i = 0; i < idx; i++) t = t->prev;
        Node *cur = t;
        Node *prv = t->prev, *nxt = t->next;
        prv->next = nxt;
        nxt->prev = prv;
        this->size--;
    }
};

int main() {
    DoublyLinkedList list = DoublyLinkedList();
    // insertion
    list.addAtHead(1);
    list.addAtTail(4);
    list.addATNthNodeFromHead(1, 2);
    list.addATNthNodeFromTail(1, 3);
    // deletion
    list.deleteAtHead();
    list.deleteAtTail();
    list.deleteAtNthIndexFromHead(1);
    list.deleteAtNthIndexFromTail(0);
    list.printListFromHead();
    // list.printListFromTail();
}