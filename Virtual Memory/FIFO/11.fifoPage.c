/* 
    Author     : abhijithvijayan
    Created on : 18 Nov 18, 14:32
    Title      : FIFO page-replacement algorithm
*/

#include <stdio.h>

void fifo(int[], int[], int, int);

int main()
{
    int i, pCount, fCount, pages[30], frames[20];
    printf("Number of Frames : ");
    scanf("%d", &fCount);
    // create frames array will null value
    for (i = 0; i < fCount; ++i) {
        frames[i] = -1;
    }
    printf("Number of Pages : ");
    scanf("%d", &pCount);
    printf("Enter the reference string\n");
    for (i = 0; i < pCount; ++i) {
        scanf("%d", &pages[i]);
    }
    // call the function
    fifo(pages, frames, pCount, fCount);

    return 0;
}

void fifo(int pages[], int frames[], int pCount, int fCount) {
    printf("\nRef.String   |\tFrames\n");
    printf("-------------------------------\n");
    int i, j, k, flag, faultCount = 0, queue = 0;
    for (i = 0; i < pCount; ++i) {
        printf("  %d\t|\t", pages[i]);
        flag = 0;
        for (j = 0; j < fCount; ++j) {
            if (frames[j] == pages[i]) {                // compare with string in str[]
                flag = 1;
                printf("   Hit");
                break;
            }
        }
        if (flag == 0) {                                // not present in frames
            frames[queue] = pages[i];
            faultCount++;
            queue = (queue + 1) % fCount;               // Queue position in circular way
            // display
            for (k = 0; k < fCount; ++k) {
                printf("%d  ", frames[k]);
            }
        }
        printf("\n\n");
    }
    printf("Total Page Faults = %d\n", faultCount);
}

/* OUTPUT

    Number of Frames : 3
    Number of Pages : 20
    Enter the reference string
    7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

    Ref.String   |  Frames
    -------------------------------
    7     |       7  -1  -1

    0     |       7  0  -1

    1     |       7  0  1

    2     |       2  0  1

    0     |          Hit

    3     |       2  3  1

    0     |       2  3  0

    4     |       4  3  0

    2     |       4  2  0

    3     |       4  2  3

    0     |       0  2  3

    3     |          Hit

    2     |          Hit

    1     |       0  1  3

    2     |       0  1  2

    0     |          Hit

    1     |          Hit

    7     |       7  1  2

    0     |       7  0  2

    1     |       7  0  1

    Total Page Faults = 15
    
*/