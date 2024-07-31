#include <bits/stdc++.h>
#define ll long long
using namespace std;

void selectionSort(vector<int> &A) {
    int n = A.size();
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (A[j] < A[min]) min = j;
        }
        if (min != i) swap(A[i], A[min]);
    }
}

int main() {
    vector<int> A {6, 2, 3, 1, 4, 5};
    selectionSort(A);
    for (int x : A) cout << x << " ";
}