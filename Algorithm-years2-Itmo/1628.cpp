#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

bool compare_1(PII a, PII b) {
	if (a.first != b.first) return a.first<b.first;
	return a.second<b.second;
}

bool compare_2(PII a, PII b) {
	if (a.second != b.second) return a.second<b.second;
	return a.first<b.first;
}

int main() {
    int m,n,k;
    int result = 0;
    PII black[180000];
    set<PII> S;
	cin >> n >> m >> k;

	for (long i = 0, x, y; i < k; ++i) {
		cin >> x >> y;
		black[i] = make_pair(x, y);
	}

    // Blacken around
	for (long i = 1; i <= m; i++) {
		black[k++] = make_pair(0, i);
		black[k++] = make_pair(n + 1, i);
	}
	for (long i = 1; i <= n; i++) {
		black[k++] = make_pair(i, 0);
		black[k++] = make_pair(i, m + 1);
	}

	sort(black, black + k, compare_1);
	for (int i = 0; i+1 < k ; i++) {
		int diff = black[i + 1].second - black[i].second;
		if (black[i].first == black[i + 1].first && diff >= 2) {
			if (diff == 2) S.insert(make_pair(black[i].first, black[i].second + 1));
			else ++result;
		}
	}

	sort(black, black + k, compare_2);
	for (int i = 0;i + 1 < k;++i) {
		int diff = black[i + 1].first - black[i].first;
		if (black[i].second == black[i + 1].second && diff >= 2) {
			if (diff == 2) {
				if (S.find(make_pair(black[i].first + 1, black[i].second)) != S.end())
					++result;
			}
			else ++result;
		}
	}
	cout << result << endl;

	return 0;
}