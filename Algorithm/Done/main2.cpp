#include <iostream>
using namespace std;

struct Sign_type {
	int id;
	int count;
};

pair <int, int> find_min_max(Sign_type* arr, int k) {
    static pair <int, int> cur_min_max = make_pair(0, 0);
    int min_cnt = 10001, max_cnt = 0;

    for (int i = 0; i < k; i++){
        if (arr[i].count != 0 && arr[i].count < min_cnt) {
            min_cnt = arr[i].count;
            cur_min_max.first = i;
        }

        if (arr[i].count != 0 && arr[i].count >= max_cnt) {
            max_cnt = arr[i].count;
            cur_min_max.second = i;
        }
    }

    return cur_min_max;
}
int main() {
	int k, n = 0;
	cin >> k;
	Sign_type signs[k];

	for (int i = 0; i < k; i++) {
		cin >> signs[i].count;
		signs[i].id = i + 1;
        n += signs[i].count;
	}  

    int min_id, max_id;
    pair <int, int> min_max;
	while (n > 0) {
        min_max = find_min_max(signs, k); 
		min_id = min_max.first;
        max_id = min_max.second;

		if (signs[max_id].count > 0) {
			cout << signs[max_id].id << " ";
			signs[max_id].count--;
            n--;
		}
		if (signs[min_id].count > 0) {
			cout << signs[min_id].id << " ";
			signs[min_id].count--;
            n--;
		}
	} 

    return 0;
}
