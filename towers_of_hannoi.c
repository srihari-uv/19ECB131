#include <stdio.h>

// Function to move n disks from source to destination using auxiliary peg
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    // Base case: If there is only one disk, move it from source to destination
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    // Move n-1 disks from source to auxiliary, so they are out of the way
    towerOfHanoi(n - 1, source, auxiliary, destination);
    
    // Move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    // Move the n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    
    // Input the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // Call the function to solve the problem
    printf("The sequence of moves to solve the Tower of Hanoi are:\n");
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B, C are the rods
    
    return 0;
}


OUTPUT:

Enter the number of disks: 4
The sequence of moves to solve the Tower of Hanoi are:
Move disk 1 from A to B
Move disk 2 from A to C
Move disk 1 from B to C
Move disk 3 from A to B
Move disk 1 from C to A
Move disk 2 from C to B
Move disk 1 from A to B
Move disk 4 from A to C
Move disk 1 from B to C
Move disk 2 from B to A
Move disk 1 from C to A
Move disk 3 from B to C
Move disk 1 from A to B
Move disk 2 from A to C
Move disk 1 from B to C
