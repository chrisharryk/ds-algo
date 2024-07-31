#include <bits/stdc++.h>
#define ll long long
using namespace std;

void bubbleSort(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (A[i] > A[j]) swap(A[i], A[j]);
        }
    }
}

int main() {
    vector<int> A {6, 2, 3, 1, 4, 5};
    bubbleSort(A);
    for (int x : A) cout << x << " ";
}