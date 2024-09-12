#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    bool flag = 1;
    while (flag)
    {
        srand(time(0));
        int randomNumber = rand() % 100 + 1;
        int guess, attempts = 0;
        cout << "Welcome to the Number Guessing Game \n";
        cout << "I have picked a number between 1 and 100. Can you guess it?\n";

        do
        {
            cout << "Enter your guess: ";
            cin >> guess;
            attempts++;

            if (guess > randomNumber)
            {
                cout << "Too high! Try again\n";
            }
            else if (guess < randomNumber)
            {
                cout << "Too low! Try again\n";
            }
            else
            {
                cout << "******************************\n";
                cout << "Congratulations You've guessed the number in " << attempts << " attempts\n";
            }

        } while (guess != randomNumber);

        cout << " do you want play again ? \n please click 0 or 1 \n 0. Exit   1. play again \n";
        cin >> flag;
    }
    cout << "thank you for playing the Number Guessing Game \n";
    return 0;
}
