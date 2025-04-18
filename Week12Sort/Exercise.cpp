//
// Created by bhattacharya on 4/15/2025.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

#define N 1000 // Size of the array
#define RUNS 1024 // Number of runs for averaging

// Generate a random permutation of integers [0, N-1]
// mt19937 is a Mersenne Twister random number generator
vector<int> generatePermutation(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = i;
    shuffle(arr.begin(), arr.end(), mt19937(random_device()()));
    return arr;
}

// Selection sort algorithm with optional swap counting
void selectionSort(vector<int>& arr, int& swapCount) {
    int n = arr.size();
    swapCount = 0;
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        if (i != minIndex) {
            swap(arr[i], arr[minIndex]);
            ++swapCount;
        }
    }
}

template<typename  Container>
void insertionSort(Container& container) {
    // iterating from the second element
    for(auto it = next(container.begin()); it!=container.end(); ++it) {
        // the iterator 'it' points to the current element being inserted
        auto key =*it; // the element to be inserted
        auto jt = it; // the new iterator to find the correct position of the 'key'

        // shift the elements of the sorted part of the container that are greater than key to one ahead
        while (jt!= container.begin() && key<*std::prev(jt)) {
            *jt = *std::prev(jt);
            --jt;
        }
        *jt =key;
    }
}


int main() {
    double totalTime = 0.0;
    int totalSwaps = 0;

    for (int i = 0; i < RUNS; ++i) {
        vector<int> data = generatePermutation(N);
        int swapCount = 0;
        // high_resolution_clock is used to measure the time taken by the sort
        auto start = high_resolution_clock::now();
        selectionSort(data, swapCount);
        auto end = high_resolution_clock::now();

        duration<double> elapsed = end - start;
        totalTime += elapsed.count();
        totalSwaps += swapCount;
    }


    double totalTimeIS = 0.0;

    for (int i = 0; i < RUNS; ++i) {
        vector<int> data = generatePermutation(N);

        // high_resolution_clock is used to measure the time taken by the sort
        auto start = high_resolution_clock::now();
        insertionSort(data);
        auto end = high_resolution_clock::now();

        duration<double> elapsedIS = end - start;
        totalTimeIS += elapsedIS.count();
    }

    cout <<"******Selection Sort ********** \n";

    double avgTime = totalTime / RUNS;
    cout << "Selection Sort (N = " << N << ", RUNS = " << RUNS << ")\n";
    cout << "Total Time: " << totalTime << " seconds\n";
    cout << "Average Time: " << avgTime << " seconds\n";
    cout << "t_avg / N^2 = " << avgTime / (N * N) << "\n";
    cout << "Average Swaps: " << totalSwaps / double(RUNS) << "\n";

    ///////////Insertion Sort////////
    cout <<"******Insertion Sort ********** \n";

    double avgTimeIS = totalTimeIS / RUNS;
    cout << "Insertion Sort (N = " << N << ", RUNS = " << RUNS << ")\n";
    cout << "Insertion Sort Total Time: " << totalTimeIS << " seconds\n";
    cout << "Insertion Sort Average Time: " << avgTimeIS << " seconds\n";
    cout << "Insertion Sort t_avg / N^2 = " << avgTimeIS / (N * N) << "\n";

    return 0;
}
// This code implements the Selection Sort algorithm and measures its performance