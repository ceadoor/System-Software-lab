/* 
    Author     : abhijithvijayan
    Created on : 20 Oct,18 23:38
    Title      : Single Level Directory Organisation
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct directory {
    char dirName[10];
    char fileName[10][10]; /* fileName[10][i] -> i Array of 10 char */
    int fileCount;
} dir;

void main()
{
    int i, ch;
    char tmp[10];
    dir.fileCount = 0;
    printf("Enter a directory name:");
    scanf("%s", dir.dirName);

    while (1)
    {
        printf("\nOperations\n\n1.Create File\n2.Delete File\n3.Search in Directory\n4.View Files\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch) {

            case 1:
                printf("Enter the name of the file:");
                scanf("%s", dir.fileName[dir.fileCount++]);
                break;

            case 2:
                printf("Enter the name of the file:");
                scanf("%s", tmp);
                for (i = 0; i < dir.fileCount; ++i) {
                    if (strcmp(tmp, dir.fileName[i]) == 0) {                        /* The strcmp() function takes two strings and return an integer. 0->identical */
                        printf("The File %s is deleted!\n", tmp);                     /* Copy the last element to the place of deleted one */
                        strcpy(dir.fileName[i], dir.fileName[dir.fileCount - 1]);   /* The strcpy() function copies the string to the another character array. strcpy(destination, source) */
                        dir.fileCount--;
                        break;
                    }
                }
                if (i == dir.fileCount) {
                    printf("404 | File Not Found\n");
                }
                break;

            case 3:
                printf("Enter the name of the file to be searched for:");
                scanf("%s", tmp);
                for (i = 0; i < dir.fileCount; ++i) {
                    if (strcmp(tmp, dir.fileName[i]) == 0) {
                        printf("File Found!!");
                        break;
                    }
                }
                if (i == dir.fileCount) {
                    printf("404 | File Not Found");
                }
                break;

            case 4:
                if (dir.fileCount == 0) {
                    printf("Empty Directory!!");
                }
                else {
                    printf("Files:\n");
                    for (i = 0; i < dir.fileCount; ++i)
                    {
                        printf("%s\n", dir.fileName[i]);
                    }
                    printf("Total %d files in 1 directory", dir.fileCount);
                }
                break;

            default:
                exit(0);
        }
    }
}