#include<stdio.h>
#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);

    int a[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int minSum = a[0] + a[1];
    int x = a[0], y = a[1];

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];

            if (sum < 0)
                sum = -sum;   

            if (sum < minSum || minSum < 0) {
                minSum = sum;
                x = a[i];
                y = a[j];
            }
        }
    }

    printf("%d %d", x, y);

    return 0;
}