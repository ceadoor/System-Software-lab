/* 
    Author     : abhijithvijayan
    Created on : 23 Sep,18 21:45
    Title      : FCFS Scheduling
*/

#include <stdio.h>

int i, n;
float tatAvg, wtAvg;

void read(int b[]) {
    for (i = 0; i < n; ++i) {
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &b[i]);
    }
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
        printf("%d\t%d\t\t%d\t%d\n", i, b[i], wt[i], tat[i]);
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

int main() {

    int b[20];
    printf("Number of Processes:");
    scanf("%d", &n);
    read(b);
    calcTime(b);

    return 0;
}

/* OUTPUT

    Number of Processes:3
    Enter the burst time of process 0: 23
    Enter the burst time of process 1: 33
    Enter the burst time of process 2: 11
    Process BurstTime WaitingTime  TurnAroundTime
    0       23              0       23
    1       33              23      56
    2       11              56      67
    average waiting time: 26.333334
    average turnaround time: 48.666668
    
*/