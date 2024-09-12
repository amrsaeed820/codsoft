#include <IOSTREAM>
using namespace std;

int main()
{
    double num1, num2, result;
    bool flag = 1;
    char opr;
    cout << "Welcome to the simple calculator \n";
    while (flag)
    {
        cout << "Please Enter the two number : \n";
        cin >> num1 >> num2;
        cout << "Enter the operation (+, -, *, /): \n";
        cin >> opr;
        cout << "***************************\n";
        switch (opr)
        {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n";
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n";
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n";
            break;
        case '/':
            if (num2 != 0)
            {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
            }
            else
            {
                cout << "Error: Division by zero is not allowed.\n";
            }
            break;

        default:
            cout << "Invalid operator. Please use one of (+, -, *, /).\n";
            break;
        }
        cout << "***************************\n";
        cout << "the program finshed! \n Click 0 or 1 \n 0. Exit   1. New opreation \n";
        cin >> flag;
    }
    cout << "thank you for using the simple calculator \n";
}
