#include <iostream>
#include <string>

class Person {
    std::string name;  // Private by default (hidden)
    int age;           // Private by default (hidden)

public:
    Person(std::string n, int a) : name(n), age(a) {}  // Constructor to set values

    void showInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Person p("Alice", 14);
    // p.age = 15;  // Error! Age is private, can't change it directly
    p.showInfo();  // Output: Name: Alice, Age: 14
    return 0;
}
