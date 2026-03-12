#include <stdio.h>
#define INF 999

int main() {
    int n, e;
    int u[50], v[50], w[50];
    int cost[50];
    int i, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for(i = 0; i < e; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    for(i = 1; i <= n; i++)
        cost[i] = INF;

    cost[n] = 0;

    for(i = n-1; i >= 1; i--) {
        for(j = 0; j < e; j++) {
            if(u[j] == i) {
                if(w[j] + cost[v[j]] < cost[i]) {
                    cost[i] = w[j] + cost[v[j]];
                }
            }
        }
    }

    printf("\nMinimum cost from node 1 to node %d = %d\n", n, cost[1]);

    return 0;
}
