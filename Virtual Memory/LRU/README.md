## Program for LRU page-replacement algorithm

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Virtual%20Memory/LRU/12.lru.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/raw/master/Virtual%20Memory/LRU/12.lru.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Virtual%20Memory/LRU/README.md#output)

In Least Recently Used (LRU) algorithm is a Greedy algorithm where the page to be replaced is least recently used.

Least Recently Used (LRU) page replacement algorithm works on the concept that the pages that are heavily used in previous instructions are likely to be used heavily in next instructions. And the page that are used very less are likely to be used less in future. Whenever a page fault occurs, the page that is least recently used is removed from the memory frames. Page fault occurs when a referenced page in not found in the memory frames.

In simple words, on a page fault, the frame that has been in memory the longest is replaced.

<hr />

**Implementation :** 

Let capacity be the number of pages that
memory can hold.  Let set be the current
set of pages in memory.

- Start traversing the pages.
  - If set holds less pages than capacity.
    - Insert page into the set one by one until 
      the size  of set reaches capacity or all
      page requests are processed.
    - Simultaneously maintain the recent occurred
      index of each page in a map called indexes.
    - Increment page fault
  -  Else 
      - If current page is present in set, do nothing.
      - Else 
        - Find the page in the set that was least 
     recently used. We find it using index array.
     We basically need to replace the page with
     minimum index.
        - Replace the found page with current page.
        - Increment page faults.
        - Update index of current page.

- Return page faults.

<hr />

LRU is a marking algorithm, so it is <img src="https://wikimedia.org/api/rest_v1/media/math/render/svg/13927983edad1979dd266a93f0034ad46d419636" width="70">-competitive.

## Output

![output_img](/.github/out_img/p_12_out.png)

Reference

- [Wikipedia](https://en.wikipedia.org/wiki/Page_replacement_algorithm)
- [TheCrazyProgrammer](https://www.thecrazyprogrammer.com/2016/11/lru-page-replacement-algorithm-c.html)