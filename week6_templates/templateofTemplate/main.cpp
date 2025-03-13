#include <iostream>
#include <array>

// Template Template Parameter: A Container template that takes
//  (1) a type and (2) a compile-time size (non-type parameter).
// C++ container are a type of data structure that can hold multiple elements of the same type.
// C++ provides several container classes, such as std::vector, std::array, std::list, std::map, and std::set, among others.
template <template <typename, std::size_t> class Container>
class MultiParamWrapper {
public:
    // We'll fix the type to int for simplicity here
    using IntContainer = Container<int, 5>;
    // string container
    //using StringContainer = Container<std::string, 5>;

    using ValueType = typename IntContainer::value_type;


    void fill(int startValue) {
        for (std::size_t i = 0; i < data_.size(); ++i) {
            data_[i] = startValue + i;
        }
    }

    void print() const {
        for (auto e : data_) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

private:
    IntContainer data_;
};

int main() {
    MultiParamWrapper<std::array> wrapper;
    wrapper.fill(10);
    wrapper.print();  // Outputs: 10 11 12 13 14



    return 0;
}
