#include <iostream>
#include <string>
using namespace std;
class Student {
private:
    string name;
    int age;

public:
    // Constructor
    Student(string n, int a) : name(n), age(a) {
        // : name(n), age(a) is an initialization list
        //:: is used to specify the ownership of the member variable
        //name(n) initializes the member variable name with the value of the parameter n

    }

    // Getter
    string getName() const { // const here means that the method will not change the object on which it is called
        return name;
    }

    int getAge() const {
        return age;
    }

    // Setter
    void setAge(int a) { age = a; }

    // Member function
    void display() {
       cout << "Name: " << name << ", Age: " << age << "\n";
    }

  // Destructor
    ~Student() {
        cout << "Destructor called" << std::endl;
    }

};

int main() {
    Student s("Alice", 20);
    s.display();
    s.setAge(21);
    cout << "Updated age: " << s.getName() << " is now " << s.getAge() << "\n";
    return 0;
}