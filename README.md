# Project: Coding and Evaluating Search Tree Operations

## Introduction
This project encompasses coding search tree operations and evaluating the performance of search tree implementations. It's divided into two parts: coding exercises involving Binary Search Trees (BSTs) and AVL Trees, and experimental evaluations of these tree structures' performance.

## Part 1: BST Operations and Performance Evaluation

### Coding Tasks:
1. **Display Links Function**:
   - Implement a `void displayLinks() const` function in `BinarySearchTree.h`.
   - Write a test program to demonstrate the correctness of this function.
   - Additional details can be found in the provided `BSTtest2.cpp`.

2. **Height Function**:
   - Implement a `int height() const` function in `BinarySearchTree.h` to compute the height of the tree recursively.
   - Write a test program to demonstrate the correctness of this function.
   - Additional details can be found in the provided `Htest.cpp`.

3. **Depth Function**:
   - Implement a `int depth(const Comparable & x) const` function in `BinarySearchTree.h` to compute the depth of a given element in the tree recursively.
   - Write a test program to demonstrate the correctness of this function.
   - Additional details can be found in the provided `Dtest.cpp`.

### Experiment:
- Construct two BSTs, `T1` and `T2`, and perform a sequence of membership checks on both trees.
- Compare the average times for membership tests in `T1` and `T2`, and also the average depth of search for these membership tests.
- Write a short report on your experiment and findings.
- The program for this experiment can be found in `Exp1.cpp`.

## Part 2: AVL Tree Operations and Performance Evaluation

### Coding Tasks:
- Repeat the coding tasks from Part 1 for the AVL-tree implementation in `AvlTree.h`.

### Experiment:
- Construct two large trees using `BinarySearchTree.h`, and `AvlTree.h`, and compare their performance on a sequence of membership tests.
- Write a short report on your experiment and findings.
- The program for this experiment can be found in `Exp2.cpp`.

## Files:
- `BinarySearchTree.h`: BST implementation with added functions.
- `AvlTree.h`: AVL Tree implementation with added functions.
- `dsexceptions.h`: Exception handling code.
- `DLtest.cpp`, `Htest.cpp`, `Dtest.cpp`, `Exp1.cpp`, `Exp2.cpp`: Various test and experiment programs.
- `Makefile`: Instructions for compiling the project.
- `report.pdf`: Report on findings from the experiments.

## Compilation:
Make sure to have a working `Makefile` to ease the compilation process. It should support the commands `make all` for compiling all executable programs, and `make clean` for cleaning up the compiled files.

```bash
# To compile all executable programs
make all

# To clean up
make clean

# Demonstrates the correctness of your displayLinks() function
./DLtest

# Demonstrates the correctness of your height() function
./Htest

# Demonstrates the correctness of your depth() function
./Dtest

# Comparison of average times for membership tests in two different BST structures (T1 and T2).
./Exp1

# Comparison of height, average key depth, and membership checks between a BST and an AVL-tree.
./Exp2

