#include <stdio.h>

#define SIZE 5 //Defined the size of each array

void printMatrix(int m3[SIZE][SIZE]); //Initialized all functions that became implemented in main
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int m3[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int m3[SIZE][SIZE]);
void transposeMatrix(int og_matrix[SIZE][SIZE], int tpose_matrix[SIZE][SIZE]);


int main() 
{
    int m1[SIZE][SIZE] = { //Created matrix 1
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = { //Created matrix 2
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int choice;
    printf("Choose a matrix to print (1 for m1, 2 for m2): "); //Asking user for choice of printing matrix 1 or 2

    // Program will exit if given the incorrect input
    if (scanf("%d", &choice) != 1) 
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (choice == 1) {
        printf("Matrix m1:\n");
        printMatrix(m1);  //Prints results of matrix 1
        printf("\n");
    } 
    else if (choice == 2) {
        printf("Matrix m2:\n");
        printMatrix(m2);  //Prints results of matrix 2
        printf("\n");
    } 
    else {
        printf("Invalid choice.\n");
        printf("\n");
    }
    

    int m3[SIZE][SIZE]; //Initializes storage for matrix 3
    
    printf("Choose a matrix to transpose (1 for m1, 2 for m2): ");
    
    if (scanf("%d", &choice) != 1) // Program will exit if given the incorrect input
    { 
        printf("Invalid input.\n");
        return 1;
    }

    if (choice == 1) {
        printf("Transposed Matrix m1:\n"); 
        transposeMatrix(m1, m3); //Prints results of transpose of matrix 1
        printf("\n");
    } 
    else if (choice == 2) {
        printf("Transposed Matrix m2:\n"); 
        transposeMatrix(m2, m3); //Prints results of transpose of matrix 2
        printf("\n");
    } 
    else {
        printf("Invalid choice.\n");
        printf("\n");
    }

    printf("Added Matrices Results:\n");
    addMatrices(m1, m2, m3); //Adds the results between matrix 1 and 2 and stores them in 3
    printf("\n\n");

    printf("Multiplied Matrices Results:\n");
    multiplyMatrices(m1, m2, m3);  //Multiplies the results between matrix 1 and 2 and stores them in 3
    
    return 0;
}

void printMatrix(int m3[SIZE][SIZE]) //Creates the printMatrix function
{
    for (int i = 0; i < SIZE; i++) { //Goes through each row of the matrix
        for (int j = 0; j < SIZE; j++) { //Goes through each element
            printf("%d ", m3[i][j]); //Prints out the 2d array
        }
        printf("\n");
    }
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int m3[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) { //Goes through each row of the matrix
        for (int j = 0; j < SIZE; j++) { //Goes through each element
            m3[i][j] = m1[i][j] + m2[i][j]; //Adds the results and stores stores the values of each element into matrix 3
            printf("%d ", m3[i][j]); //Prints out the 2d array
        }
        printf("\n");
    }
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int m3[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) { //Goes through each row of the matrix
        for (int j = 0; j < SIZE; j++) { //Goes through each element
            m3[i][j] = m1[i][j] * m2[i][j]; //Multiplies the results and stores stores the values of each element into matrix 3
            printf("%d ", m3[i][j]); //Prints out the 2d array
        }
        printf("\n");
    }
}

void transposeMatrix(int og_matrix[SIZE][SIZE], int tpose_matrix[SIZE][SIZE]) 
{
    for (int i = 0; i < SIZE; i++) { //Goes through each row of the matrix
        for (int j = 0; j < SIZE; j++) { //Goes through each element
            tpose_matrix[j][i] = og_matrix[i][j]; //Swaps the elements in each row with their respective column
            printf("%d ", tpose_matrix[j][i]); //Prints out the transposed array
        }
        printf("\n");
    }
}