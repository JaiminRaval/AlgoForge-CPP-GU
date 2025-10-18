#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a) {}

    void showInfo() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Person p("Bob", 14);
    p.age = 15;
    p.showInfo();
    return 0;
}
