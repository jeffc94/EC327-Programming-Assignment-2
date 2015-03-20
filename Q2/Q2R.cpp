#include <iostream>

using namespace std;

void PrintTop(int n, int m, int o)
{
    if (m == o+1)
        return;
    for (int i = 0; i < (n*2)-2; i++)
        cout << " ";
    for (int j = 1; j < m+1; j++)
        cout << j << " ";
    if (m>1)
    {
        for (int k = m-1; k > 0; k--)
            cout << k << " ";
    }
    cout << endl;
    PrintTop(n-1,m+1,o);

}

void PrintBot(int n, int m)
{
    if (m == 0)
        return;
    for (int i = 0; i < 2*n; i++)
        cout << " ";
    for (int j = 1; j < m+1; j++)
        cout << j << " ";
    if (m>1)
    {
        for (int k = m-1; k > 0; k--)
            cout << k << " ";
    }
    cout << endl;
    PrintBot(n+1,m-1);
}

void PrintRhombus(int n)
{
    int m = 1;
    PrintTop(n,m,n);
    PrintBot(m,n-m);
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

    PrintRhombus(n);

    return 0;
}
