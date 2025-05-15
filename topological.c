#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k, n, a[10][10], indeg[10], flag[10], count = 0;

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i < n; i++) {
        indeg[i] = 0;
        flag[i] = 0;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            indeg[i] += a[j][i];

    printf("Topological order is:\n");

    while (count < n) {
        int found = 0;
        for (k = 0; k < n; k++) {
            if (indeg[k] == 0 && flag[k] == 0) {
                printf("%d -> ", k + 1);
                flag[k] = 1;
                found = 1;
                count++;
                for (i = 0; i < n; i++) {
                    if (a[k][i] == 1)
                        indeg[i]--;
                }
                break; // restart scanning from beginning
            }
        }
        if (!found) {
            printf("\nGraph has a cycle. Topological sort not possible.\n");
            break;
        }
    }

    printf("END\n");
    return 0;
}
