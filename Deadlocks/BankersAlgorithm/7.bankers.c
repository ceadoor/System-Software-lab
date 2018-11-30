/* 
    Author     : abhijithvijayan
    Created on : 27 Oct 18, 15:50
    Title      : Banker’s Algorithm
*/

#include <stdio.h>

int n, m;
void read(int alloc[][10], int max[][10], int avail[10], int need[][10], int n, int m);
void display(int temp[][10], int n, int m);
int safety(int alloc[][10], int avail[10], int need[][10], int n, int m);

int main()
{
    int alloc[10][10], max[10][10], avail[10], need[10][10];

    printf("DEADLOCK AVOIDANCE USING BANKER'S ALGORITHM\n");
    read(alloc, max, avail, need, n, m);
    return 0;
}

//Banker's Algorithm
void read(int alloc[][10], int max[][10], int avail[10], int need[][10], int n, int m) {

    int i, j;
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    printf("Enter total number of resources: ");
    scanf("%d", &m);

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Allocation Resource: ");
        for (j = 0; j < m; ++j) {
            scanf("%d", &alloc[i][j]);
        }
        printf("Maximum Resource: ");
        for (j = 0; j < m; ++j) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nAvailable System Resources: ");
    for (i = 0; i < m; ++i) {
        scanf("%d", &avail[i]);
    }
    // Calculating Need matrix
    for (i = 0; i < n; ++i) {
        for (j = 0; j < m; ++j) {
            need[i][j] = max[i][j] - alloc[i][j];        /* need = max - allocated */
        }
    }

    printf("\nProcess\tCurrently-Allocated-Resources\n");
    display(alloc, n, m);
    printf("\nProcess\tMaximum-Resources\n");
    display(max, n, m);
    printf("\nProcess\tPossibly-Needed-Resources\n");
    display(need, n, m);

    safety(alloc, avail, need, n, m);
}

//Safety algorithm

/* available >= need, then available += allocated */

int safety(int alloc[][10], int avail[10], int need[][10], int n, int m)  {

    int i, j, k, index = 0;
    int isDone[10], sequence[10], count = 0;            /* array to store safety sequence */

    for (i = 0; i < n; ++i) {
        isDone[i] = 0;                                  /* array-> |0|0|0|0|0| */
    }

    for (k = 0; k < n; ++k) {                           /* Iterating for possible deadlock to prevent infinite loop */

        // main process starts
        for (i = 0; i < n; ++i)
        {
            if (isDone[i] == 0) {                       /* pending */
                for (j = 0; j < m; ++j)
                {
                    if (avail[j] >= need[i][j]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
                if (j == m) {                           /* True: avail >= need */
                    for (j = 0; j < m; ++j) {
                        avail[j] += alloc[i][j];
                    }
                    count++;                            /* done process's count */
                    isDone[i] = 1;
                    sequence[count - 1] = i + 1;        /* safe state sequence */
                }
            }
        }
        
        if (count == n) {                               /* safe state */
            printf("\nIT'S A SAFE STATE\n");
            printf("The safe sequence is\n");
            int i;
            for (i = 0; i < n; ++i) {
                printf("P%d ", sequence[i]);
            }
            printf("\n");
            break;
        }
        // main process ends

    } /* deadlock check loop ends */

    if (count != n) {
        printf("\nDeadlock has occured.\n");            /* deadlock */
    }
}

void display(int temp[][10], int n, int m)
{
    int i, j;
    for (i = 0; i < n; ++i) {
        printf("P%d", i + 1);
        for (j = 0; j < m; ++j) {
            printf("\t%d", temp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* OUTPUT

    DEADLOCK AVOIDANCE USING BANKER'S ALGORITHM
    Enter total number of processes: 3
    Enter total number of resources: 4

    Process 1
    Allocation Resource: 1 2 2 1
    Maximum Resource: 3 3 2 2

    Process 2
    Allocation Resource: 1 0 3 3
    Maximum Resource: 1 2 3 4

    Process 3
    Allocation Resource: 1 2 1 0
    Maximum Resource: 1 3 5 0

    Available System Resources: 3 1 1 2

    Process Currently-Allocated-Resources
    P1      1       2       2       1
    P2      1       0       3       3
    P3      1       2       1       0

    Process Maximum-Resources
    P1      3       3       2       2
    P2      1       2       3       4
    P3      1       3       5       0

    Process Possibly-Needed-Resources
    P1      2       1       0       1
    P2      0       2       0       1
    P3      0       1       4       0

    IT'S A SAFE STATE
    The safe sequence is
    P1 P2 P3
    
*/