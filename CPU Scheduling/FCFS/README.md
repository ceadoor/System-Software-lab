## Program for FCFS Scheduling

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/CPU%20Scheduling/FCFS/1.fcfs.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge )](https://github.com/KTU-CSE/System-Software-lab/raw/master/CPU%20Scheduling/FCFS/1.fcfs.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/CPU%20Scheduling/FCFS/README.md#output)

Given n processes with their burst times, the task is to find average waiting time and average turn around time using FCFS scheduling algorithm.

First in, first out (FIFO), also known as first come, first served (FCFS), is the simplest scheduling algorithm. FIFO simply queues processes in the order that they arrive in the ready queue.
In this, the process that comes first will be executed first and next process starts only after the previous gets fully executed.

Here we are considering that arrival time for all processes is 0.

- Completion Time: Time at which process completes its execution.

- Turn Around Time: Time Difference between completion time and arrival time. Turn Around Time = Completion Time – Arrival Time

- Waiting Time(W.T): Time Difference between turn around time and burst time.

- Waiting Time = Turn Around Time – Burst Time

Implementation:

1-  Input the processes along with their burst time (bt).

2-  Find waiting time (wt) for all processes.

3-  As first process that comes need not to wait so 
    waiting time for process 1 will be 0 i.e. wt[0] = 0.

4-  Find waiting time for all other processes i.e. for
     process i -> 
       wt[i] = bt[i-1] + wt[i-1] .

5-  Find turnaround time = waiting_time + burst_time 
    for all processes.

6-  Find average waiting time = 
                 total_waiting_time / no_of_processes.
                 
7-  Similarly, find average turnaround time = 
                 total_turn_around_time / no_of_processes.

## Output

![output_image](/.github/out_img/p_01_out.jpg)

[Reference](http://web.cse.ohio-state.edu/~agrawal/660/Slides/jan18.pdf)
