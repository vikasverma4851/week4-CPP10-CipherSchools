#include <iostream>

using namespace std;

void divideNumbers(int dividend, int divisor) {
    if (divisor == 0) {
        throw runtime_error("Division by zero is not allowed!");
    }
    cout << "Result of division: " << dividend / divisor << endl;
}

int main() {
    try {
        int num1, num2;
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
        divideNumbers(num1, num2);
    } catch (const exception& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
