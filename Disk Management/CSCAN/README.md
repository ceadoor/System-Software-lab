## Program for C-SCAN Disk Scheduling

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Disk%20Management/CSCAN/10.csan.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge )](https://github.com/KTU-CSE/System-Software-lab/raw/master/Disk%20Management/CSCAN/10.csan.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Disk%20Management/CSCAN/README.md#output)

Definition of C-SCAN: C-SCAN moves the head from one end of the Disk to the other end, servicing requests along the way. The head on reaching the other end, however immediately returns to the beginning of the Disk without servicing any requests on the return.

- The huge jump from one end to the other is not considered as a head movement as cylinders are treated as a circular list.

### Example

- Example list of pending disk requests (listed by track number): 100, 50, 10, 20, 75.
    
- The starting track number for the examples will be 35.
    
- The list will need to be sorted in ascending order: 10, 20, 50, 75, 100.

- CSCAN algorithm is currently going from a lower track number to a higher track number
    - Seek 1: 50 − 35 = 15
    - Seek 2: 75 − 50 = 25
    - Seek 3: 100 − 75 = 25

- At this point both have reached the highest (end) track request. C-SCAN will go back to track 0 and start going to higher track requests. 
    - **Seek 4 (C-SCAN): 0 − 100 = 0 head movement as cylinders are treated as a circular list (C-SCAN always goes back to the first track)
    - Seek 5 (C-SCAN): 10 − 0 = 10
    - Seek 6 (C-SCAN): 20 − 10 = 10
    - Total (C-SCAN): 85
    - Average (C-SCAN): 85 ÷ 5 = 17

Note: Even though six seeks were performed using the C-SCAN algorithm, only five I/Os were actually done. 

## Output

![output_img](/.github/out_img/p_10_out.jpg)

Reference

- [Wikipedia](https://en.wikipedia.org/wiki/Elevator_algorithm)
- [GeeksforGeeks](https://www.geeksforgeeks.org/operating-system-page-replacement-algorithm/)
