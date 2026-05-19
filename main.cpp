#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Customer {
    string name;
    string order;
};

int main() {
    srand(time(0));
 
    string names[] = {"Jake", "Mia", "Tyler", "Sara", "Nate", "Chloe", "Marcus", "Lily", "Derek", "Amy"};
    string coffees[] = {"Iced Latte", "Black Coffee", "Flat White", "Vanilla Latte", "Cold Brew"};
 
    //M1
    list<Customer> coffeeQueue;
    for (int i = 0; i < 3; i++) {
        Customer c;
        c.name = names[rand() % 10];
        c.order = coffees[rand() % 5];
        coffeeQueue.push_back(c);
    }
 
    for (auto entry : coffeeQueue) {
        cout << entry.name << " - " << entry.order << endl;
    }

    return 0;
}