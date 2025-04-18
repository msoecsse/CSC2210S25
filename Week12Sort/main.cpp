#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>
#include <iomanip>

using namespace std;
using namespace chrono_literals;

void printArray(const vector<int>& arr, int h1 = -1, int h2 = -1) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << setw(2) << arr[i] << " | ";
        for (int j = 0; j < arr[i]; ++j) {
            cout << ((i == h1 || i == h2) ? '*' : '#');
        }
        cout << "\n";
    }
    cout << "----------------------------------\n";
    this_thread::sleep_for(300ms);
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i)
        for (size_t j = 0; j < arr.size() - i - 1; ++j)
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                printArray(arr, j, j + 1);
            }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < arr.size(); ++j)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
        printArray(arr, i, minIdx);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            printArray(arr, j, j + 1);
            --j;
        }
        arr[j + 1] = key;
        printArray(arr, j + 1);
    }
}

// Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
        printArray(arr, k - 1);
    }
    while (i < left.size()) arr[k++] = left[i++], printArray(arr, k - 1);
    while (j < right.size()) arr[k++] = right[j++], printArray(arr, k - 1);
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quicksort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; ++j)
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]);
            printArray(arr, i, j);
        }
    swap(arr[i + 1], arr[high]);
    printArray(arr, i + 1, high);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Radix Sort (non-negative integers)
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void countingSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    int count[10] = {0};

    for (int num : arr) count[(num / exp) % 10]++;
    for (int i = 1; i < 10; ++i) count[i] += count[i - 1];
    for (int i = arr.size() - 1; i >= 0; --i) {
        int idx = (arr[i] / exp) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }
    for (size_t i = 0; i < arr.size(); ++i)
        arr[i] = output[i], printArray(arr, i);
}

void radixSort(vector<int>& arr) {
    for (int exp = 1, maxVal = getMax(arr); maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

// Heap Sort
void heapify(vector<int>& arr, int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        printArray(arr, i, largest);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        printArray(arr, 0, i);
        heapify(arr, i, 0);
    }
}

// Shell Sort
void shellSort(vector<int>& arr) {
    for (int gap = arr.size() / 2; gap > 0; gap /= 2)
        for (size_t i = gap; i < arr.size(); ++i) {
            int temp = arr[i];
            size_t j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                printArray(arr, j, j - gap);
                j -= gap;
            }
            arr[j] = temp;
            printArray(arr, j);
        }
}
void insertionSortRange(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            printArray(arr, j + 1, j);
            --j;
        }
        arr[j + 1] = key;
        printArray(arr, j + 1);
    }
}
// Simulated Timsort = Insertion + Merge
void timSort(vector<int>& arr) {
    const int RUN = 32;
    int n = arr.size();

    // Sort individual subarrays of size RUN using insertion sort
    for (int i = 0; i < n; i += RUN)
        insertionSortRange(arr, i, min(i + RUN - 1, n - 1));

    // Start merging runs from size RUN
    for (int size = RUN; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);
            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

// ------------------- Main -------------------
void runSort(int choice, vector<int>& data) {
    switch (choice) {
        case 1: bubbleSort(data); break;
        case 2: selectionSort(data); break;
        case 3: insertionSort(data); break;
        case 4: mergeSort(data, 0, data.size() - 1); break;
        case 5: quickSort(data, 0, data.size() - 1); break;
        case 6: radixSort(data); break;
        case 7: heapSort(data); break;
        case 8: shellSort(data); break;
        case 9: timSort(data); break;
        default: cout << "Invalid option!\n"; break;
    }
}

int main() {
    vector<int> data = {15, 3, 9, 1, 12, 7, 8, 2};

    cout << "Initial Array:\n";
    printArray(data);

    cout << "Choose Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n";
    cout << "5. Quicksort\n6. Radix Sort\n7. Heap Sort\n8. Shell Sort\n9. Timsort\n> ";

    int choice;
    cin >> choice;

    runSort(choice, data);

    cout << "\nSorted Array:\n";
    printArray(data);
    return 0;
}
