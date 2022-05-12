#include <iostream>

using namespace std;

void clean_toilet(int* a, int len, int pos);

int main() {
    int n, k;
    cin >> n >> k;
    
    if (n == 1) {
        cout << 1;
        return 0;
    }

    int* soldier = new int[n];

    for (int i = 1; i <= n; i++) {
        soldier[i] = i;
    }

    int cur = 1;
    while (n > 0) {
        cur = (cur + k -1) % n;
        if (cur == 0) cur = n;
        cout << soldier[cur] << ' ';

        clean_toilet(soldier, n, cur);
        n--;
    }

    delete[] soldier;
    return 0;
}

void clean_toilet(int* a, int len, int pos) {
    for (int i = pos; i < len; i++) {
        a[i] = a[i+1];
    }
}
