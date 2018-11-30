## Program for Banker’s Algorithm

[![solution](https://img.shields.io/badge/View-Solution-blue.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Deadlocks/BankersAlgorithm/7.bankers.c)
[![raw](https://img.shields.io/badge/-raw-green.svg?logo=appveyor&longCache=true&style=for-the-badge )](https://github.com/KTU-CSE/System-Software-lab/raw/master/Deadlocks/BankersAlgorithm/7.bankers.c)
[![output](https://img.shields.io/badge/-output-ff69b4.svg?logo=appveyor&longCache=true&style=for-the-badge)](https://github.com/KTU-CSE/System-Software-lab/blob/master/Deadlocks/BankersAlgorithm/README.md#output)

The Banker algorithm, sometimes referred to as the detection algorithm, is a resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation of predetermined maximum possible amounts of all resources, and then makes an "s-state" check to test for possible deadlock conditions for all other pending activities, before deciding whether allocation should be allowed to continue. 

Resources

For the Banker's algorithm to work, it needs to know three things:

  - How much of each resource the system currently has available[AVAILABLE]
  - How much of each resource each process is currently holding[ALLOCATED]
  - How much of each resource each process could possibly request[MAX]  

Let ‘n’ be the number of processes in the system and ‘m’ be the number of resources types.

Available :

   - It is a 1-d array of size ‘m’ indicating the number of available resources of each type.
   - Available[ j ] = k means there are ‘k’ instances of resource type R<sub>j</sub>

Max :

   - It is a 2-d array of size ‘n*m’ that defines the maximum demand of each process in a system.
   - Max[ i, j ] = k means process P<sub>i</sub> may request at most ‘k’ instances of resource type R<sub>j</sub>.

Allocation :

   - It is a 2-d array of size ‘n*m’ that defines the number of resources of each type currently allocated to each process.
   - Allocation[ i, j ] = k means process P<sub>i</sub> is currently allocated ‘k’ instances of resource type R<sub>j</sub>

Need :

   - It is a 2-d array of size ‘n*m’ that indicates the remaining resource need of each process.
   - Need [ i, j ] = k means process P<sub>i</sub> currently allocated ‘k’ instances of resource type Rj
   - Need [ i, j ] = Max [ i, j ] – Allocation [ i, j ]

Allocation<sub>i</sub> specifies the resources currently allocated to process P<sub>i</sub> and Needi specifies the additional resources that process P<sub>i</sub> may still request to complete its task.

Banker’s algorithm consist of Safety algorithm and Resource request algorithm

Safety Algorithm

The algorithm for finding out whether or not a system is in a safe state can be described as follows:

  1. Let Work and Finish be vectors of length ‘m’ and ‘n’ respectively.
        
       - Initialize: Work= Available
       - Finish [i]=false; for i=1,2,……,n

  2. Find an i such that both
       - a) Finish [i]=false
       - b) Need_i<=work

        - if no such i exists goto step (4)

  3. Work=Work + Allocation_i
       - Finish[i]= true
       - goto step(2)

  4. If Finish[i]=true for all i,
     - then the system is in safe state. 

Safe sequence is the sequence in which the processes can be safely executed. 

## Output

![output_img](/.github/out_img/p_07_out.png)

References:
 
- [Wikipedia](https://en.wikipedia.org/wiki/Banker%27s_algorithm)
- [YouTube](https://www.youtube.com/watch?v=2V2FfP_olaA)
- [stackoverflow](https://stackoverflow.com/questions/15501861/bankers-algorithm-for-deadlock-avoidance-in-c)
- [GeeksForGeeks](https://www.geeksforgeeks.org/program-bankers-algorithm-set-1-safety-algorithm/)
- [Gist](https://gist.github.com/pallabpain/68909d4ac6ff77c9aa40)
