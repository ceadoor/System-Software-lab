### Page Replacement Algorithms

- [FIFO Algorithm](https://github.com/KTU-CSE/System-Software-lab/tree/master/Virtual%20Memory/FIFO/README.md)
- [LRU Algorithm](https://github.com/KTU-CSE/System-Software-lab/tree/master/Virtual%20Memory/LRU/README.md)
- [LFU Algorithm](#)

<hr />

### Page Replacement

In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needed to be replaced when new page comes in. Whenever a new page is referred and not present in memory, page fault occurs and Operating System replaces one of the existing pages with newly needed page.

When the page that was selected for replacement and paged out is referenced again it has to be paged in (read in from disk), and this involves waiting for I/O completion. 

This determines the quality of the page replacement algorithm: **the less time waiting for page-ins, the better the algorithm.** 

A page replacement algorithm looks at the limited information about accesses to the pages provided by hardware, and tries to guess which pages should be replaced to minimize the total number of page misses, while balancing this with the costs (primary storage and processor time) of the algorithm itself. 