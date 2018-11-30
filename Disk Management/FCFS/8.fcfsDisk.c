/* 
    Author     : abhijithvijayan
    Created on : 28 Oct 18, 22:14
    Title      : FCFS Disk Scheduling
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int diskQueue[20], n, i, seekTime=0, diff;
    printf("Enter the size of Queue: ");
    scanf("%d", &n);
    printf("Enter the Queue: ");
    for(i=1;i<=n;i++) {                                     /* head element to be read */                       
        scanf("%d",&diskQueue[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &diskQueue[0]);                             /* head element */
    printf("\nMovement of Cylinders\n");
    for(i=0;i<n;i++) {
        diff= abs(diskQueue[i+1] - diskQueue[i]);           /* abs( ) function in C returns the absolute value of an integer, which is always positive. */
        seekTime+= diff;                    
        printf("Move from %d to %d with seek time %d\n", diskQueue[i], diskQueue[i+1], diff);
    }
    printf("\nTotal Seek Time: %d", seekTime);
    printf("\nAverage Seek Time = %f",(float) seekTime/n);
    printf("\n");
    return 0;
}

/* OUTPUT

    Enter the size of Queue: 8
    Enter the Queue: 99 184 38 123 15 125 66 68
    Enter the initial head position: 54

    Movement of Cylinders
    Move from 54 to 99 with seek time 45
    Move from 99 to 184 with seek time 85
    Move from 184 to 38 with seek time 146
    Move from 38 to 123 with seek time 85
    Move from 123 to 15 with seek time 108
    Move from 15 to 125 with seek time 110
    Move from 125 to 66 with seek time 59
    Move from 66 to 68 with seek time 2

    Total Seek Time: 640
    Average Seek Time = 80.000000
    
*/