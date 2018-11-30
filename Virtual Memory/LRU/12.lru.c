/* 
    Author     : abhijithvijayan
    Created on : 20 Nov 18, 14:42
    Title      : LRU page-replacement algorithm
*/

#include <stdio.h>

void LRU(int[], int[], int[], int, int);
int findLRU(int[], int);

int main() {
    int i, pCount, fCount, pages[30], frames[20], time[20];
    printf("Number of Frames : ");
    scanf("%d", &fCount);
    // create frames array will null values
    for (i = 0; i < fCount; ++i) {
        frames[i] = -1;
    }
    printf("Number of Pages : ");
    scanf("%d", &pCount);
    printf("Enter the reference string\n");
    for (i = 0; i < pCount; ++i) {
        scanf("%d", &pages[i]);
    }
    LRU(pages, frames, time, fCount, pCount);

    return 0;
}

void LRU(int pages[], int frames[], int time[], int fCount, int pCount) {
    printf("\nRef.String   |\tFrames\n");
    printf("-------------------------------\n");

    int i, j, k, pos, flag, faultCount, counter, queue;
    counter = 0, queue = 0, faultCount = 0;

    for (i = 0; i < pCount; ++i) {
        flag = 0;
        printf("  %d\t|\t", pages[i]);
        // check if already present
        for (j = 0; j < fCount; ++j) {
            if (frames[j] == pages[i]) {
                flag = 1;                                   // this means that the character is already there in one of the frames.
                counter++;
                time[j] = counter;                          // update occurance
                printf("   Hit\n\n");
                break;
            }
        }
        // push if there is free space
        if ((flag == 0) && (queue < fCount)) {              // empty frames[] spaces
            faultCount++;
            counter++;
            frames[queue] = pages[i];
            time[queue] = counter;
            queue++;                                        // queue is to keep the count of number of frames which have been filled.
        }
        // replacement as frames[] is full
        else if ((flag == 0) && (queue == fCount)) {        // the frames are full now
            faultCount++;
            counter++;
            pos = findLRU(time, fCount);
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        // printing
        if (flag == 0) {
            for (k = 0; k < fCount; ++k) {
                printf("%d  ", frames[k]);
            }
            printf("\n\n");
        }
    }
    printf("Total Page Faults = %d\n\n", faultCount);
}

int findLRU(int time[], int fCount) {
    int k, min, pos;
    pos = 0;
    min = time[0];
    for (k = 1; k < fCount; ++k) {
        if (time[k] < min) {
            min = time[k];
            pos = k;
        }
    }
    return pos;
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

    3     |       2  0  3

    0     |          Hit

    4     |       4  0  3

    2     |       4  0  2

    3     |       4  3  2

    0     |       0  3  2

    3     |          Hit

    2     |          Hit

    1     |       1  3  2

    2     |          Hit

    0     |       1  0  2

    1     |          Hit

    7     |       1  0  7

    0     |          Hit

    1     |          Hit

    Total Page Faults = 12
    
*/