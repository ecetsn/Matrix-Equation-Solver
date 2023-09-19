# Matrix-Vector Multiplication

This project solves a matrix-vector multiplication problem where you need to find missing values in a matrix LHS (left-hand side) such that the multiplication of LHS with a vector RHS equals a given result vector RES. Your task is to determine the missing values (in the range [1, 9]) in LHS while satisfying specific conditions.

## Problem Description

### Consider three mathematical objects:

LHS (left-hand side matrix): A matrix with missing values marked as 'X'.
RHS (right-hand side vector): A vector of values.
RES (result vector): A vector representing the result of the matrix-vector multiplication LHS × RHS.
Your goal is to find the missing values in the LHS matrix such that the mathematical relation LHS × RHS = RES holds true.

## Minimum Integer Condition
Since there can be multiple valid solutions for each problem instance, your program should return the solution with the smallest concatenated integer when all missing values are filled in, following a specific order. The order for concatenation is left to right, top to bottom. This ensures that your solution is the one with the smallest integer among all possible solutions.

For example, if there are multiple valid solutions for the LHS matrix, your program should return the one that forms the smallest concatenated integer.


## Program Flow

**Reading Input:** The program begins by asking the user for the filenames of RHS, LHS, and RES matrices, as well as the output filename. Any errors encountered during input file reading will result in the program printing "Error" to the output file and terminating.

**Reading Matrix Files:** The program reads the contents of RHS, LHS, and RES files following a specific format. It performs various checks to ensure the input matrices and vectors are valid. If any checks fail, the program prints "Error" and terminates.

**Finding Missing Values:** Your program calculates and fills in the missing values in the LHS matrix to satisfy the equation LHS × RHS = RES while following the minimum integer condition.

**Output:** The program prints the filled LHS matrix to the output file. If no solution is found, it prints "Error."

Matrix File Format
Each matrix file follows this format:

**{num_rows} {num_columns}
{matrix_values}**

**{num_rows}:** Number of rows in the matrix.
<br>
**{num_columns}:** Number of columns in the matrix.
<br>
**{matrix_values}:** Matrix values represented as rows, where missing values are denoted by '-1'.

## Assumptions
The program assumes the following:

The number of columns in LHS is the same as the number of rows in RHS. <br>
Input files contain only integer numbers. <br>
Values inside the LHS matrix are either positive integers in the range [1-9] inclusive or '-1'. <br>
Values inside the RHS matrix are in the range [1-9] inclusive. <br>
Values inside the RES matrix are positive integers greater than or equal to 1.

<br/>

> [!NOTE]
> This project was developed as a programming assignment and serves as an educational resource for working.
