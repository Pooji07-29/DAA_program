#include <stdio.h>

int n, sum;
int w[20], x[20];

void subset(int s, int k, int r) {
    x[k] = 1;

    if (s + w[k] == sum) {
        printf("Subset: ");
        for (int i = 0; i <= k; i++) {
            if (x[i] == 1)
                printf("%d ", w[i]);
        }
        printf("\n");
    }
    else if (s + w[k] + w[k+1] <= sum) {
        subset(s + w[k], k + 1, r - w[k]);
    }

    if ((s + r - w[k] >= sum) && (s + w[k+1] <= sum)) {
        x[k] = 0;
        subset(s, k + 1, r - w[k]);
    }
}

int main() {
    int total = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (in increasing order):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        total += w[i];
    }

    printf("Enter required sum: ");
    scanf("%d", &sum);

    subset(0, 0, total);

    return 0;
}
