/* 
    Author     : abhijithvijayan
    Created on : 21 Oct,18 18:57
    Title      : Two Level Directory Organisation (check line#95)
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i,j, dirCount=0;                /* initialize directory count here */
char dName[10],fName[10];           /* temporary variables */

struct directory {
    char dirName[10];
    char fileName[10][10];          /* fileName[10][i] -> i Array of 10 char */
    int fileCount;
} dir[10];                          /* structure of Array */

void createDir(struct directory dir[]);
void createFile(struct directory dir[]);
void deleteFile(struct directory dir[]);
void listDir(struct directory dir[]);
int listFiles(struct directory dir[], char dName[10]);
void search(struct directory dir[]);
void display(struct directory dir[]);

void main() {
    int ch;
    while(1) {
        printf("1.Create Directory\n2.Create File\n3.Delete File\n4.Search in Directory\n5.View Files\n6.Exit\n");        
        printf("Enter your choice:");
        scanf("%d",&ch);
        printf("\n");
        switch(ch) {
            case 1: createDir(dir);
                    break;
            case 2: createFile(dir);
                    break;
            case 3: deleteFile(dir);
                    break;
            case 4: search(dir);
                    break;
            case 5: display(dir);
                    break;
            default: exit(0);
        }
    }
}

void createDir(struct directory dir[]) {
    printf("Enter directory name:");
    scanf("%s", dir[dirCount++].dirName);
    dir[dirCount].fileCount=0;                                                  /* initialize count of files in the directory created */
    printf("Directory '%s' created\n\n", dir[dirCount-1].dirName);
}

void createFile(struct directory dir[]) {
    listDir(dir);
    printf("\nChoose the directory:");
    scanf("%s",dName);
    for(i=0;i<dirCount;i++) {
        if(strcmp(dName,dir[i].dirName)==0) {                                   /* True -> Found */
            printf("Enter a file name:");
            scanf("%s", dir[i].fileName[dir[i].fileCount++]);
            printf("File '%s' is created\n\n", dir[i].fileName[dir[i].fileCount-1]);      
            break;                   
        }
    }
    if(i==dirCount) {
        printf("404 | Directory Not Found!!\n\n");                              /* 404 */
    }
}

void deleteFile(struct directory dir[]) {    
    if(dirCount!=0) {
        listDir(dir);
        printf("\nEnter directory name to select:");
        scanf("%s",dName);
        i=listFiles(dir, dName);
        if(dir[i].fileCount==0) {
            printf("\nNo Files Found!!");
        }
        else {
            printf("\nChoose file to be deleted:");
            scanf("%s",fName);
            for(j=0;j<dir[i].fileCount;j++) {
                if(strcmp(fName, dir[i].fileName[j])==0) {                  /* i is static, represents directory */
                    printf("\nFile Deleted!!\n");
                    strcpy(dir[i].fileName[j], dir[i].fileName[dir[i].fileCount-1]);
                    dir[i].fileCount--;                                     /* reduce file count */
                    break;
                }
            }
            if(j==dir[i].fileCount-1) {                                   /* count reduced by 1 */
                printf("\n404 | File Not Found\n");
            }
        }    
    } 
    else {
        printf("\n404 | No directory found!!\n\n");
    }
}

void listDir(struct directory dir[]) {
    for(i=0;i<dirCount;i++) {
        printf("%s\n",dir[i].dirName);
    }
    if(i==dirCount) {
        printf("\n%d directory(s) found!!\n",dirCount);
    }
}

int listFiles(struct directory dir[], char dName[10]) {
    for(i=0;i<dirCount;i++) {
        if(strcmp(dName, dir[i].dirName)==0) {
            printf("Showing all files.\n\n");
            for(j=0;j<dir[i].fileCount;j++) {
                printf("%s\n",dir[i].fileName[j]);
            }
            return i;
        }
    }
    if(i==dirCount) {
        printf("\n404 | No such directory found!!\n\n");
        return -1;
    }
}

void search(struct directory dir[]) {
    if(dirCount!=0) {
        listDir(dir);
        printf("\nEnter directory name to select:");
        scanf("%s",dName);
        for(i=0;i<dirCount;i++) {
            if(strcmp(dName, dir[i].dirName)==0) {                             /* Search for the directory */
                printf("Enter the file to be searched for:");
                scanf("%s", fName);
                for(j=0;j<dir[i].fileCount;j++) {
                    if(strcmp(fName, dir[i].fileName[j])==0) {                  /* i is static, represents directory */
                        printf("\nFile Found!!\n\n");
                        break;
                    }
                }
                if(j==dir[i].fileCount) {
                    printf("\n404 | File Not Found\n\n");
                    break;
                }
                break;                                                          /* End Searching */
            }
        }
        if(i==dirCount) {
            printf("\n404 | No such directory found!!\n\n");
        }
    } 
    else {
        printf("\n404 | No directory found!!\n\n");
    }
}

void display(struct directory dir[]) {
    if(dirCount==0) {
        printf("\n404 | No directory found!!\n\n");
    }
    else {
        for(i=0;i<dirCount;i++) {
            printf("Dir Name: %s",dir[i].dirName);
            printf("\nShowing all files.\n");
            for(j=0;j<dir[i].fileCount;j++) {
                if(dir[i].fileCount==0) {
                    printf("Empty Directory\n");
                }
                printf("%s\n",dir[i].fileName[j]);
            }
            printf("%d File(s) Found!!\n\n",dir[i].fileCount);
        }
        printf("\n\n");
    }
}