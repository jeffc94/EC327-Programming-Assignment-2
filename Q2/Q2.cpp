#include <iostream>

using namespace std;

int counter = 1; //Variable to determine number of times recursive function has been run
int breaker = 1; //Variable to print either top or bottom

void printRhombus(int n)
{
    //Prints the top half of the rhombus
    if (breaker == 1)
    {
        if (n==0)
            return;
        for (int i = 0; i < (n*2)-2; i++)
            cout << " ";
        for (int j = 1; j < counter+1; j++)
            cout << j << " ";
        if (counter > 1)
        {
            for (int k = counter-1; k > 0; k--)
                cout << k << " ";
        }
        cout << endl;
        counter++;
        printRhombus(n-1);
        return;
    }
    //Prints the bottom half of the rhombus
    else
        if (n==1)
            return;
        for (int i = 0; i < 2*counter; i++)
            cout << " ";
        for (int j = 1; j < n; j++)
            cout << j << " ";
        if (n > 2)
        {
            for (int k = n-2; k > 0; k--)
                cout << k << " ";
        }
        cout << endl;
        counter++;
        printRhombus(n-1);
}

int main()
{
    int n;

    //Prompt user for input
    cout << "Enter a number [1-9]: ";
    cin >> n;

    //Check if input is invalid
    while (n<1 || n>9)
    {
        cout << "Wrong input, please enter a single digit number between 1 and 9." << endl;
        cout << "\nEnter a number [1-9: ";
        cin >> n;
    }

    //Call printRhombus to print top half
    printRhombus(n);
    breaker++;
    counter = 1;
    //Call printRhombus to print bot half
    printRhombus(n);

    return 0;
}
