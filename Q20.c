#include <stdio.h>

#define MAX 1000

int countZeroSumSubarrays(int arr[], int n) {
    int sum = 0, count = 0;

    int hash[2 * MAX] = {0};  
    int offset = MAX; 

    hash[offset] = 1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        
        if (hash[sum + offset] > 0) {
            count += hash[sum + offset];
        }

        hash[sum + offset]++;
    }

    return count;
}

int main() {
    int n = 6;
    int arr[] = {1, -1, 2, -2, 3, -3};

    printf("%d\n", countZeroSumSubarrays(arr, n));

    return 0;
}