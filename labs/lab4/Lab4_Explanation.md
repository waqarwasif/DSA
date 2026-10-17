# Lab 4 - Sparse Matrices Explanation Document

This document provides a detailed explanation of the algorithms and C++ code for storing and retrieving sparse matrices (Lower Triangular and Tridiagonal) as per the lab exercise sheet.

## Question 1: Lower Triangular Sparse Matrix

**Objective:** Implement algorithms for storing and retrieving a lower triangular sparse matrix.

### Algorithm Explanation
A lower triangular matrix has non-zero elements only on or below the main diagonal. Instead of storing all the zeros, we can map the non-zero elements into a 1-dimensional array `U` to save space.

**1. Storing Algorithm:**
We iterate row by row. For each row `j` (from `0` to `n-1`), we only loop the columns `k` up to `j` (since `k <= j` is the condition for lower triangular elements).
*   Initialize index `i = 0`.
*   Loop `j` from `0` to `n-1`.
*   Loop `k` from `0` to `j`.
*   Set `U[i] = A[j][k]` and increment `i`.

**2. Retrieving Algorithm:**
To get the 2D matrix back, we do the reverse. If we are at a position where `k > j`, we know it's above the diagonal, so the value is `0`. Otherwise, the value was stored in `U`. The formula to find the 1D index from 2D coordinates `(j, k)` is `(j * (j + 1)) / 2 + k`.
*   Loop `j` from `0` to `n-1`.
*   Loop `k` from `0` to `n-1`.
*   If `k > j`, set `A[j][k] = 0`.
*   Else, set `A[j][k] = U[(j * (j + 1)) / 2 + k]`.

### Code Explanation
In `Q1.cpp`, we dynamically allocate a 2D array (`int** original`) and a 1D array (`int* U`). 
*   `storeLowerTriangular()` function executes the storing algorithm directly using pointers.
*   `retrieveLowerTriangular()` function applies the formula `(j * (j + 1)) / 2 + k` to correctly map the 1D data back into the newly allocated `retrieved` 2D array.
*   Finally, memory is properly deallocated using `delete[]` to prevent memory leaks.

---

## Question 2: Size and Formula for Tridiagonal Matrix

**Objective:** Find the size of `U` for a tridiagonal matrix `B` and find the formula for index `L`.

### 1. Size of U
In a tridiagonal matrix, non-zero elements only exist on:
*   The main diagonal: `n` elements.
*   The upper diagonal: `n - 1` elements.
*   The lower diagonal: `n - 1` elements.
*   **Total size:** `n + (n - 1) + (n - 1) = 3n - 2`.

### 2. Formula for L
We need to map `B[j][k]` to `U[L]`. 
*   Row `0` has exactly `2` non-zero elements.
*   All rows strictly between `0` and `j` (which is `j - 1` rows) have exactly `3` non-zero elements.
*   Therefore, the total number of elements present *before* row `j` is `2 + 3 * (j - 1) = 3j - 1`.
*   Inside row `j`, the first non-zero element starts at column `k = j - 1`. Thus, the offset of `B[j][k]` inside its own row is `k - (j - 1) = k - j + 1`.
*   Adding the offset to the elements before row `j` gives: `(3j - 1) + (k - j + 1) = 2j + k`.
*   **Formula:** `L = 2*j + k`.

---

## Question 3: Storing Tridiagonal Matrix

**Objective:** Develop and implement an algorithm to store non-zero entries of tridiagonal matrix `B` into array `U`.

### Algorithm Explanation
An element `B[j][k]` belongs to the tridiagonal band if the absolute difference between its row and column indices is less than or equal to 1 (`abs(j - k) <= 1`).
*   Initialize index `i = 0`.
*   Loop `j` from `0` to `n-1`.
*   Loop `k` from `0` to `n-1`.
*   Check if `abs(j - k) <= 1`.
*   If true, store `B[j][k]` into `U[i]` and increment `i`.

### Code Explanation
In `Q3.cpp`, we allocate a 2D array representing a tridiagonal structure. The `storeTridiagonal()` function loops through the entire `n x n` structure but uses an `if (abs(j - k) <= 1)` condition to filter out zeros. Only the valid tridiagonal elements are pushed into the dynamically allocated 1D array `U` of size `3n - 2`.

---

## Question 4: Retrieving Tridiagonal Matrix

**Objective:** Develop and implement an algorithm to retrieve matrix `B` from `U`.

### Algorithm Explanation
We need to reconstruct the `n x n` matrix from the 1D array `U`. 
*   Loop `j` from `0` to `n-1`.
*   Loop `k` from `0` to `n-1`.
*   Check if the position `(j, k)` is part of the tridiagonal band (`abs(j - k) <= 1`).
*   If true, we retrieve the value from `U` using our derived formula `L = 2*j + k` and set `B[j][k] = U[2*j + k]`.
*   If false, we know it's a zero element outside the band, so we set `B[j][k] = 0`.

### Code Explanation
In `Q4.cpp`, we start with a predefined 1D array `U` representing the compressed matrix data. The `retrieveTridiagonal()` function populates the 2D array `B`. It strictly follows the `abs(j - k) <= 1` condition, utilizing the `2*j + k` index mapping to fetch the correct values for the diagonals, while heavily populating the rest of the matrix with zeros.
