#include <iostream>

using namespace std;

void someFunction() {
    try {
        // Code that might throw an exception
        throw runtime_error("Something went wrong in someFunction!");
    } catch (const exception& e) {
        cout << "Exception caught in someFunction: " << e.what() << endl;
        // Rethrow the exception
        throw; // This will rethrow the same exception to be caught by the caller of someFunction()
    }
}

int main() {
    try {
        someFunction();
    } catch (const exception& e) {
        cout << "Exception caught in main: " << e.what() << endl;
    }

    return 0;
}
