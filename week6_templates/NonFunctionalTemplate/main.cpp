#include <iostream>
// ==================================================
// Non-Template class
// ==================================================
template <int Size>
// a template class that represents a fixed-size array
class FixedArray {
public:
    FixedArray() {
        for (int i = 0; i < Size; ++i) {
            data_[i] = 0;
        }
    }

    void set(int index, int value) {
        if (index >= 0 && index < Size) {
            data_[index] = value;
        }
    }

    int get(int index) const {
        if (index >= 0 && index < Size) {
            return data_[index];
        }
        return -1; // or throw an exception
    }

    int length() const {
        return Size;
    }

private:
    int data_[Size];
};

int main() {
    FixedArray<5> arr;
    arr.set(0, 10);
    arr.set(4, 20);

    for (int i = 0; i < arr.length(); ++i) {
        std::cout << arr.get(i) << " ";
    }
    std::cout << std::endl;

    // Error if you do: FixedArray<5> arr2; arr2.set(5, 100); // Out of bounds

    return 0;
}
