#include<bits/stdc++.h>

using namespace std;
// Swap two elements - Utility function  
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

void quickSort(int arr[], int start, int end) {

    int i = start, j = end, pivot_index = start + (end - start) / 2;
    int pivot = arr[pivot_index];
    while (i < end || j > start) {

        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {

            swap(&arr[i], &arr[j]); // Swap two elements
            i++; j--;

        } else {
            if (i < end) quickSort(arr, i, end);
            if (j > start) quickSort(arr, start, j);
            return;
        }
    }
}


int main(){
    long long n;
    cin>>n;
    int X_coord[n];
    int Y_coord[n];

    for(long long i = 0; i < n; i++){
        cin>>X_coord[i] >> Y_coord[i];
    }

    quickSort(X_coord, 0, n-1);
    quickSort(Y_coord, 0, n-1);

    long long res = 0;

    for(long long i = 1; i < n; i++){
        int X = X_coord[i] - X_coord[i-1];
        int Y = Y_coord[i] - Y_coord[i-1];
        res += (X+Y) * i * (n-i) * 2; 
    }
    res = res / (n * (n-1));
    cout<<res<<endl;
    return 0;

}