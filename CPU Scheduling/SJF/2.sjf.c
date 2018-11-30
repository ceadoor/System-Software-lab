/* 
    Author     : abhijithvijayan
    Created on : 24 Sep,18 07:24
    Title      : SJF Scheduling
*/

#include <stdio.h>

int i, j, n, pId[20];
float tatAvg, wtAvg;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int b[]) {

    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - 1 - i; ++j) {
            if (b[j] > b[j + 1]) {
                swap(&b[j], &b[j + 1]);
                swap(&pId[j], &pId[j + 1]);
            }
        }
    }
}

void read(int b[]) {
    for (i = 0; i < n; ++i) {
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &b[i]);
        pId[i] = i + 1; /* process 1, process 2,... */
    }
    sort(b);
}

void findWaitingtime(int b[], int wt[]) {
    wt[0] = 0;
    int wtSum = 0;
    for (i = 1; i < n; ++i) {
        wt[i] = wt[i - 1] + b[i - 1];
        wtSum += wt[i];
    }
    wtAvg = (float)wtSum / n;
}

void findTurnAroundtime(int tat[], int b[], int wt[]) {
    int tatSum = 0;
    for (i = 0; i < n; ++i) {
        tat[i] = b[i] + wt[i];
        tatSum += tat[i];
    }
    tatAvg = (float)tatSum / n;
}

void display(int b[], int wt[], int tat[]) {
    printf("Process\tBurstTime WaitingTime  TurnAroundTime\n");
    for (i = 0; i < n; ++i) {
        printf("%d\t%d\t\t%d\t%d\n", pId[i], b[i], wt[i], tat[i]);
    }
    printf("average waiting time: %f", wtAvg);
    printf("\naverage turnaround time: %f", tatAvg);
    printf("\n");
}

void calcTime(int b[]) {
    int wt[20], tat[20];
    findWaitingtime(b, wt);
    findTurnAroundtime(tat, b, wt);
    display(b, wt, tat);
}

void main() {
    int b[20];
    printf("Number of Processes:");
    scanf("%d", &n);
    read(b);
    calcTime(b);
}

/* OUTPUT

    Number of Processes:4
    Enter the burst time of process 0: 6
    Enter the burst time of process 1: 8
    Enter the burst time of process 2: 7
    Enter the burst time of process 3: 3
    Process BurstTime WaitingTime  TurnAroundTime
    4       3               0       3
    1       6               3       9
    3       7               9       16
    2       8               16      24
    average waiting time: 7.000000
    average turnaround time: 13.000000
    
*/