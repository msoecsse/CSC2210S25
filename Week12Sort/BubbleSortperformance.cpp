//
// Created by bhattacharya on 4/17/2025.
//
#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include <algorithm> // for std::shuffle
#include <random>    // for random engine
#include "stopwatch.h" // make sure this provides startTimer() and stopTimer()

using namespace std;

#define N 1000
#define RUNS 1024

// Function to generate a random permutation of integers from 0 to N-1
vector<int> generatePermutation(int n) {
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 0); // Fill with 0, 1, ..., n-1
    shuffle(arr.begin(), arr.end(), std::mt19937(std::random_device()()));
    return arr;
}

// Function to perform bubble sort with exchange counting
void bubbleSort(vector<int>& arr, int& swapCount) {
    int n = arr.size();
    swapCount = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ++swapCount;
            }
        }
    }
}


// main function to run the bubble sort and measure performance
int main() {
    double totalTime = 0.0;
    int totalSwaps = 0;

    for (int i = 0; i < RUNS; ++i) {
        vector<int> data = generatePermutation(N);
        int swapCount = 0;

        startTimer(); // Start the timer
        bubbleSort(data, swapCount);
        double elapsedTime = stopTimer(); // Stop the timer

        totalTime += elapsedTime;
        totalSwaps += swapCount;
    }

    double avgTime = totalTime / RUNS;
    cout << "Bubble Sort (N = " << N << ", RUNS = " << RUNS << ")\n";
    cout << "Total Time: " << totalTime << " seconds\n";
    cout << "Average Time: " << avgTime << " seconds\n";
    cout << "Total Swaps: " << totalSwaps << "\n";

    return 0;
}

