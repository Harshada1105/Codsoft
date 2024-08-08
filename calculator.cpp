#include <iostream>
using namespace std;

int main() {
    
    cout << "\t\t\tSimple Calculator\n";
    char op;
    float num1, num2;

    while (true) {
        cout << "Enter operator (+, -, *, /) or 'q' to stop: ";
        cin >> op;

        if (op == 'q') {
            break; 
        }

        cout << "Enter two operands: ";
        cin >> num1 >> num2;

        switch (op) {
            case '+':
                cout << "Result: " << num1 + num2 << "\n";
                break;
            case '-':
                cout << "Result: " << num1 - num2 << "\n";
                break;
            case '*':
                cout << "Result: " << num1 * num2 << "\n";
                break;
            case '/':
                if (num2 != 0) {
                    cout << "Result: " << num1 / num2 << "\n";
                } else {
                    cout << "Error: Division by zero is not allowed.\n";
                }
                break;
            default:
                cout << "Error: Invalid operator.\n";
                continue; 
        }
    }

    cout << "Calculator program ended.\n";
    return 0;
}