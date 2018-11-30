## Program for Two Level Directory Organisation Technique

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Memory%20Management/TwoLevelDir/6.twoLevelDir.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge )](https://github.com/KTU-CSE/System-Software-lab/raw/master/Memory%20Management/TwoLevelDir/6.twoLevelDir.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Memory%20Management/TwoLevelDir/README.md#output)

In the two-level directory system, each user has own user file directory (UFD). 
The system maintains a master block that has one entry for each user. 
This master block contains the addresses of the directory of the users. 
When a user job starts or a user logs in, the system's master file directory (MFD) is searched. 
When a user refers to a particular file, only his own UFD is searched. 
This effectively solves the name collision problem and isolates users from one another.

## Output

![output_img](/.github/out_img/p_06_out-1.png)
![output_img](/.github/out_img/p_06_out-2.png)
![output_img](/.github/out_img/p_06_out-3.png)
