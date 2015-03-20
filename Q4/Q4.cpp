#include <iostream>

using namespace std;

int * DoubleandReverse (int *list, int size)
{
    //Create new array
    int* result = new int[size];

    //Match original and new arrays
    for (int i = 0; i < size; i++)
        result[i] = list[i];
    //New array gets reversed
    for (int i = 0, j = (size*2)-1; j > (size - 1) ; j--, i++)
        result[j] = list[i];

    return result;
}

int main()
{
    //Initialize variable for size of array
    int ogSize;

    //Ask user to input size of array
    cout << "Enter the number of entries: ";
    cin >> ogSize;

    //Create array with input size
    int ogArray [ogSize];

    //Allow user to input elements
    for (int i = 0; i < ogSize; i++)
    {
        cout << "Entry " << i << " is: ";
        cin >> ogArray[i];
    }

    //Declare pointer to original array
    int* ogPtr = ogArray;

    //Run function returning pointer to new array
    int* newPtr = DoubleandReverse(ogPtr, ogSize);

    //Display output
    cout << "Original array is: ";
    for (int i = 0; i < ogSize; i++)
        cout << ogPtr[i] << " ";
    cout << "and the address of the zero element is " << ogPtr << endl;

    cout << "Final array is: ";
    for (int i = 0; i < (ogSize*2); i++)
        cout << newPtr[i] << " ";
    cout << "and the address of the zero element is " << newPtr << endl;

    return 0;
}
