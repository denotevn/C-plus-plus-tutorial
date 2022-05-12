#include <bits/stdc++.h>

using namespace std;

struct Country {
    vector<int> neighbors;
	bool isChecked;
	bool color;
};

int n;
bool CheckIsPosible();
vector<Country> countryList(101);
queue<int> q;

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		int x;
        scanf("%d", &x);
		while (x  != 0) {
			countryList[i].neighbors.push_back(x);
			countryList[x].neighbors.push_back(i);
            scanf("%d", &x);
		}
	}

    // start with country  1
	q.push(1);
	countryList[1].isChecked = true;
	countryList[1].color = 0;

	if (n != 0 && CheckIsPosible()) { // Check if you can color correctly with the required 
		for (int i = 1; i <= n; ++i) {
			printf("%d", countryList[i].color);
		}
	} else {
		cout << "-1";
	}

    return 0;

}

// If you color all the countries that satisfy the problem, return true
// otherwise return false	
bool CheckIsPosible() {

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < countryList[curr].neighbors.size();  i++) {
			int next = countryList[curr].neighbors[i];
			if (!countryList[next].isChecked) {
				countryList[next].isChecked = true;
				countryList[next].color = countryList[curr].color == 0 ? 1 : 0;
				q.push(next);
			}
			else if (countryList[next].color == countryList[curr].color) {
				return false;
			}
		}
	}

	return true;
}