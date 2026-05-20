#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

struct Customer {
    string name;
    string order;
};

int main() {
    srand(time(0));
 
    string names[] = {"Jake", "Mia", "Tyler", "Sara", "Nate", "Chloe", "Marcus", "Lily", "Derek", "Amy"};
    string coffees[] = {"Iced Latte", "Black Coffee", "Flat White", "Vanilla Latte", "Cold Brew"};
    string muffins[] = {"Blueberry Muffin", "Double Choc", "Poppyseed", "Bran Muffin", "Carrot Muffin"};
    string bracelets[] = {"Blue Beaded", "Knotted Hemp", "Gold Charm", "Friendship Knot", "Shell Bracelet"};
    string snacks[] = {"Soft Pretzel", "Trail Mix", "Kettle Chips", "Oatmeal Cookie", "Apple Slices"};
 
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

    // M3
    deque<Customer> muffinQueue;
    for (int i = 0; i < 3; i++) {
        Customer c;
        c.name = names[rand() % 10];
        c.order = muffins[rand() % 5];
        muffinQueue.push_back(c);
    }

    // M4
    vector<Customer> braceletQueue;
    for (int i = 0; i < 3; i++) {
        Customer c;
        c.name = names[rand() % 10];
        c.order = bracelets[rand() % 5];
        braceletQueue.push_back(c);
    }

    // M5: I chose to use two stacks to implement a queue FIFO
    stack<Customer> snackIn, snackOut;
    Customer init1, init2, init3;
    init1.name = names[rand() % 10]; init1.order = snacks[rand() % 5];
    init2.name = names[rand() % 10]; init2.order = snacks[rand() % 5];
    init3.name = names[rand() % 10]; init3.order = snacks[rand() % 5];
    snackIn.push(init1);
    snackIn.push(init2);
    snackIn.push(init3);
 

    //M2
    for (int round = 1; round <= 10; round++) {
        cout << "--- Round " << round << " ---" << endl;
 
        if (!coffeeQueue.empty()) {
            cout << "[Coffee] Served: " << coffeeQueue.front().name << " (" << coffeeQueue.front().order << ")" << endl;
            coffeeQueue.pop_front();
        } else {
            cout << "[Coffee] Queue empty, no one served." << endl;
        }
        if (rand() % 2 == 0) {
            Customer c;
            c.name = names[rand() % 10];
            c.order = coffees[rand() % 5];
            coffeeQueue.push_back(c);
            cout << "[Coffee] " << c.name << " joined the queue." << endl;
        }
 
        // M3
        if (!muffinQueue.empty()) {
            cout << "[Muffin] Served: " << muffinQueue.front().name << " (" << muffinQueue.front().order << ")" << endl;
            muffinQueue.pop_front();
        } else {
            cout << "[Muffin] Queue empty, no one served." << endl;
        }
        if (rand() % 2 == 0) {
            Customer c;
            c.name = names[rand() % 10];
            c.order = muffins[rand() % 5];
            muffinQueue.push_back(c);
            cout << "[Muffin] " << c.name << " joined the queue." << endl;
        }

        // M4
        if (!braceletQueue.empty()) {
            cout << "[Bracelet] Served: " << braceletQueue.front().name << " (" << braceletQueue.front().order << ")" << endl;
            braceletQueue.erase(braceletQueue.begin());
        } else {
            cout << "[Bracelet] Queue empty, no one served." << endl;
        }
        if (rand() % 2 == 0) {
            Customer c;
            c.name = names[rand() % 10];
            c.order = bracelets[rand() % 5];
            braceletQueue.push_back(c);
            cout << "[Bracelet] " << c.name << " joined the queue." << endl;
        }

        // M5
        if (snackOut.empty()) {
            while (!snackIn.empty()) {
                snackOut.push(snackIn.top());
                snackIn.pop();
            }
        }
        if (!snackOut.empty()) {
            cout << "[Snack] Served: " << snackOut.top().name << " (" << snackOut.top().order << ")" << endl;
            snackOut.pop();
        } else {
            cout << "[Snack] Queue empty, no one served." << endl;
        }
        if (rand() % 2 == 0) {
            Customer c;
            c.name = names[rand() % 10];
            c.order = snacks[rand() % 5];
            snackIn.push(c);
            cout << "[Snack] " << c.name << " joined the queue." << endl;
        }
 
        cout << endl;
    }

    return 0;
}