#include <iostream>

using namespace std;

void clean_toilet(int* a, int len, int pos);

int main() {
    int n, k;
    cin >> n >> k;

    int* soldier = new int[n];
    // int* result = new int[n];

    for (int i = 1; i <= n; i++) soldier[i] = i;

    int cur = 1, next = 0;
    while (n > 0) {
        if ( n < cur ) {
            cur = 1;
            next = k % n;
            cout << " when n<cur: next= " << next;
        }
        else if ( n - cur + 1 >= k ) {
            next = cur + k - 1;
        } else {
            next = cur + k - n - 1;
        }
        cout << soldier[next] << ' ';
        clean_toilet(soldier, n, next);
        cur = next;
        --n;
        
        cout << "array: ";
        for (int i = 1; i <=n; i++) cout << soldier[i] << " " ;

        cout << "n= " << n;
        cout << " cur= " << cur << endl;
    }

    return 0;
}

void clean_toilet(int* a, int len, int pos) {
    for (int i = pos; i < len; i++) {
        a[i] = a[i+1];
    }
    // --len;
}
