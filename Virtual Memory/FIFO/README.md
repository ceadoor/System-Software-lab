## Program for FIFO page-replacement algorithm

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Virtual%20Memory/FIFO/11.fifoPage.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/raw/master/Virtual%20Memory/FIFO/11.fifoPage.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Virtual%20Memory/FIFO/README.md#output)

The first-in, first-out (FIFO) page replacement algorithm is a low-overhead algorithm that requires little book keeping on the part of the operating system.

The idea is obvious from the name – the operating system keeps track of all the pages in memory in a queue, with the most recent arrival at the back, and the oldest arrival in front.

When a page needs to be replaced, the page at the front of the queue (the oldest page) is selected.

<hr />

**Implementation** – Let capacity be the number of pages that memory can hold. Let set be the current set of pages in memory.

- Start traversing the pages :

  - If set holds less pages than capacity.
    - Check if current page is present in set
      - If not :
        - Remove the first page from the queue
          as it was the first to be entered in
          the memory
        - Replace the first page in the queue with
          the current page in the string.
        - Simultaneously maintain the pages in the
          queue to perform FIFO.

- Return page faults.

![](/.github/out_img/img_11.png)

<hr />

While FIFO is cheap and intuitive, it performs poorly in practical application. Thus, it is rarely used in its unmodified form.
This algorithm experiences Bélády's anomaly.

In simple words, on a page fault, the frame that has been in memory the longest is replaced.

FIFO is a conservative algorithm, so it is <img src="https://wikimedia.org/api/rest_v1/media/math/render/svg/13927983edad1979dd266a93f0034ad46d419636" width="70"> -competitive.

## Output

![output_img](/.github/out_img/p_11_out.png)

Reference

- [Wikipedia](https://en.wikipedia.org/wiki/Page_replacement_algorithm)
- [GeeksforGeeks](https://www.geeksforgeeks.org/program-page-replacement-algorithms-set-2-fifo/)
- [CampusCoke](https://campuscoke.blogspot.com/2015/01/fifo-page-replacement-algorithm-in-c.html)
