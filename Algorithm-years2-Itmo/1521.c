#include <stdio.h>
#include <stdlib.h>

// Remove 1 element in array by position
void delete(int *arr, int n, int pos){
    if(n <= 0){
        return;
    }
    for(int i = pos; i < n - 1; i++){
        arr[i] = arr[i+1];
    }
    n--;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    if(n == 1){
        printf("%d", 1);
        return 0;
    }
    int* list;
    list = (int *)malloc(n*sizeof(int));
    if(list == NULL){
        exit(0);
    }
    for(int i = 0; i < n; i++){
        *(list + i) = i+1;
    }
    k = k-1;
    int current = 0;
    while(n > 0){
        current = (current + k) % n;
        printf("%d ", *(list + current));
        delete(list,n,current);
        n--;
    }
    free(list);
    return 0;
}
