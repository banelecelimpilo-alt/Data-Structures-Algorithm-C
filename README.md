# Introsort Hybrid Sorting Algorithm Project

## Project Overview

This project investigates and implements a hybrid sorting algorithm known as **Introsort (Introspective Sort)** using the C programming language. Introsort is a highly efficient sorting algorithm that combines the strengths of multiple sorting techniques to achieve excellent average-case performance while guaranteeing optimal worst-case performance.

The algorithm begins by using **Median-of-Three Quicksort**, which improves pivot selection by choosing the median value among the first, middle, and last elements of a sub-array. This approach reduces the likelihood of poor partitioning and improves overall performance compared to traditional Quicksort.

To avoid Quicksort's worst-case time complexity of O(n²), Introsort monitors the recursion depth during execution. If the recursion depth exceeds a predefined limit, the algorithm automatically switches to **Heapsort**, ensuring a worst-case time complexity of O(nlogn).

For very small partitions, Introsort switches to **Insertion Sort** because it performs more efficiently on small datasets due to its low overhead and simplicity.

## Objectives

The objectives of this project are:

1. To implement the following sorting algorithms in C:

   * Heapsort
   * Insertion Sort
   * Median-of-Three Quicksort

2. To develop a complete Introsort implementation that combines the above algorithms into a single hybrid sorting solution.

3. To evaluate and compare the performance of the individual sorting algorithms against Introsort using:

   * Execution time measurements.
   * Different input sizes (1,000, 10,000, and 100,000 randomly generated integers).
   * Best-case, average-case, and worst-case scenarios.
   * Memory usage where applicable.
   * Stability analysis to determine whether equal elements maintain their original order after sorting.

## Expected Outcome

The project aims to demonstrate how combining multiple sorting algorithms can overcome the limitations of individual algorithms. Through performance testing and analysis, Introsort is expected to provide faster and more reliable sorting performance across a wide range of input sizes and data distributions, making it suitable for practical real-world applications.
