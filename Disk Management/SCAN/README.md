## Program for SCAN Disk Scheduling

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Disk%20Management/SCAN/9.scan.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge )](https://github.com/KTU-CSE/System-Software-lab/raw/master/Disk%20Management/SCAN/9.scan.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Disk%20Management/SCAN/README.md#output)

The SCAN algorithm is a disk scheduling algorithm that helps in determining the motion of a disk’s arm and head in executing the read and write requests.

In SCAN algorithm the disk arm moves into a particular direction and services the requests coming in its path and after reaching the end of disk, it reverses its direction and again services the request arriving in its path.

So, this algorithm works like an elevator and hence also known as elevator algorithm. As a result, the requests at the midrange are serviced more and those arriving behind the disk arm will have to wait.

Advantages:

- High throughput
- Low variance of response time
- Average response time

Disadvantages:

- Long waiting time for requests for locations just visited by disk arm

### Example

- Example list of pending disk requests (listed by track number): 100, 50, 10, 20, 75.
    
- The starting track number for the examples will be 35.
    
- The list will need to be sorted in ascending order: 10, 20, 50, 75, 100.

- For the sake of this example let us assume that the SCAN algorithm is currently going from a lower track number to a higher track number
    - Seek 1: 50 − 35 = 15
    - Seek 2: 75 − 50 = 25
    - Seek 3: 100 − 75 = 25

- At this point both have reached the highest (end) track request. SCAN will just reverse direction and service the next closest disk request (in this example, 20).
    - Seek 4: 20 − 100 = 80
    - Seek 5): 10 − 20 = 10
    - Total: 155
    - Average: 155 ÷ 5 = 31

## Output

![output_img](/.github/out_img/p_09_out.png)

Reference

- [Wikipedia](https://en.wikipedia.org/wiki/Elevator_algorithm)