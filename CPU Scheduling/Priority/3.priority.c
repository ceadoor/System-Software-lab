/* 
    Author     : abhijithvijayan
    Created on : 29 Sep,18 11:03
    Title      : Priority Scheduling
*/

#include <stdio.h>

int i, j, n;
float tatAvg, wtAvg;

struct Process {
    int pId;
    int bt;
    int priority;
};

void read(struct Process p[]) {
    printf("\n");
    for (i = 0; i < n; ++i) {
        p[i].pId = i + 1;
        printf("Enter the burst time for process %d: ", p[i].pId);
        scanf("%d", &p[i].bt);
        printf("Enter the priority: ");
        scanf("%d", &p[i].priority);
    }
}

void display(struct Process p[], int wt[], int tat[]) {
    printf("\nProcessID | BurstTime | Priority | Waiting time | Turn Around Time\n");
    for (i = 0; i < n; ++i) {
        printf("%d\t\t%d\t%d\t\t%d\t\t%d\n", p[i].pId, p[i].bt, p[i].priority, wt[i], tat[i]);
    }
    printf("average waiting time: %f", wtAvg);
    printf("\naverage turnaround time: %f", tatAvg);
    printf("\n");
}

void sort(struct Process p[]) {
    struct Process temp;
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - 1 - i; ++j) {
            if (p[j].priority > p[j + 1].priority) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void findWaitingTime(struct Process p[], int wt[]) {
    wt[0] = 0;
    int wtSum = 0;
    for (i = 1; i < n; ++i) {
        wt[i] = wt[i - 1] + p[i - 1].bt;
        wtSum += wt[i];
    }
    wtAvg = (float)wtSum / n;
}

void findTurnAroundtime(struct Process p[], int tat[], int wt[]) {
    int tatSum = 0;
    for (i = 0; i < n; ++i) {
        tat[i] = p[i].bt + wt[i];
        tatSum += tat[i];
    }
    tatAvg = (float)tatSum / n;
}

int main()
{
    struct Process p[20];           /* Array object for the structure */
    int wt[20], tat[20];
    printf("Number of Processes:");
    scanf("%d", &n);
    read(p);
    sort(p);
    findWaitingTime(p, wt);
    findTurnAroundtime(p, tat, wt);
    display(p, wt, tat);

    return 0;
}

/* OUTPUT

    Number of Processes:4

    Enter the burst time for process 1: 22
    Enter the priority: 4
    Enter the burst time for process 2: 3
    Enter the priority: 0
    Enter the burst time for process 3: 22
    Enter the priority: 6
    Enter the burst time for process 4: 7
    Enter the priority: 2

    ProcessID | BurstTime | Priority | Waiting time | Turn Around Time
    2               3       0               0               3
    4               7       2               3               10
    1               22      4               10              32
    3               22      6               32              54
    average waiting time: 11.250000
    average turnaround time: 24.750000
    
*/