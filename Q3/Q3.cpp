#include <iostream>
#include <iomanip>
#include "q3func.h"
#include "statistics.h"

using namespace std;

int main()
{
    //Initialize variables and set set array to max value
    int sizeArray = 1000;
    int myArray [sizeArray];

    //Call function to read numbers from file
    int y = DataFromFile("numbers.txt",myArray,sizeArray);

    //Display array size
    cout << "Array size is: " << sizeArray << endl;

    //If file is empty, then display None for everything
    if (sizeArray == 0)
    {
        cout << "Mean is: None" << endl;
        cout << "StdDev is: None" << endl;
        cout << "Array values forward are: None" << endl;
        cout << "Array values reverse are: None" << endl;
        cout << "The largest array value is: None" << endl;
        cout << "The smallest array value is: None" << endl;
        return 0;
    }
    //If there are numbers in the file, then proceed with statistics functions
    else
    {
        //Get mean
        float mean = getMean(myArray,sizeArray);
        std::cout << std:: fixed;
        std::cout << "Mean is: " << std::setprecision(2) << mean << endl;;
        //Get standard deviation
        float stdev = getStdDev(myArray,sizeArray);
        std::cout << "StdDev is: " << std::setprecision(2) << stdev << endl;

        //Display array values in forward order
        cout << "Array values forward are: ";
        for (int i = 0; i < sizeArray - 1; i++)
            cout << myArray[i] << ", ";
        cout << myArray [sizeArray - 1] << endl;
        //Display array values in reverse order
        cout << "Array values reverse are: ";
        for (int i = sizeArray - 1; i > 0; i--)
            cout << myArray[i] << ", ";
        cout << myArray[0] << endl;

        //Find max array value
        int maxArray = myArray[0];
        for (int i = 1; i < sizeArray; i++)
        {
            if (myArray[i] >= maxArray)
                maxArray = myArray[i];
        }
        cout << "The largest array value is: " << maxArray << endl;
        //Find min array value
        int minArray = myArray[0];
        for (int i = 1; i < sizeArray; i++)
        {
            if (myArray[i] <= minArray)
                minArray = myArray[i];
        }
        cout << "The smallest array value is: " << minArray << endl;
    }

    return 0;
}
