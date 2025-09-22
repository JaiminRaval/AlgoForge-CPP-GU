#include <iostream>
#include <string>

struct Person {
    std::string name;  // Public by default (open)
    int age;           // Public by default (open)

    Person(std::string n, int a) : name(n), age(a) {}  // Constructor to set values

    void showInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Person p("Bob", 14);
    p.age = 15;  // Works! Age is public, can change it directly
    p.showInfo();  // Output: Name: Bob, Age: 15
    return 0;
}
