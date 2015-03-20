#include <iostream>
#include <iomanip>
#include <string>
#include "myFunc.h"

using namespace std;

extern const int ENTRIES = 10;

int main()
{
    //Initialize variables for user input
    char comm;
    double first, last, delta;

    //Call initialize function
    initialize();

    //Loop until quit command is given
    do
    {
        //Prompt user for command code
        cout << "\nPlease enter command code: ";
        cin >> comm;

        //Check if command code is legal
        if (checkCode(comm)==false)
        {
            do
            {
                cout << "Invalid command code!" <<endl;
                cout << "Please enter command code: ";
                cin >> comm;
            } while (checkCode(comm)==false);
        }

        //Quit if command is Q or q
        if (comm == 'Q' || comm == 'q')
        {
            cout << "Bye Bye!" << endl;
            return 0;
        }

        //If command is not File I/O, prompt user for command parameters
        if (comm != 'I' && comm != 'i' && comm != 'O' && comm != 'o')
        {
            cout << "Please enter command parameters: ";
            cin >> first >> last >> delta;
        }

        //Check if parameters are incorrect
        if (first > last || delta < 0)
        {
            if (comm != 'I' && comm != 'i' && comm != 'O' && comm != 'o')
            {
                cout << "No computation needed." << endl;
            }
        }

        //Set number of times function is run. If this exceeds 10, set to 10
        int ender = 0;
        double i = first;
        if (i > last || delta > 0)
        {
            while (i <= last)
            {
                i = i + delta;
                ender = ender + 1;
            }
        }
        if (ender > 10)
            ender = 10;

        std::cout << std::fixed;

        //Run proper functions corresponding to command code
        if (comm == 'S' || comm == 's')
        {
            for (int i = 0; i < ender; i++)
            {
                double result = findSquareAreaValue(first + (delta*i));
                std::cout << std::setprecision(2) << "Area of square with side length " << (first + (delta*i)) <<  " = "
                << std::setprecision(5) << result << endl;
            }
        }

        else if (comm == 'C' || comm == 'c')
        {
            for (int i = 0; i < ender; i++)
            {
                double result = findCircumValue(first + (delta*i));
                std::cout << std::setprecision(2) << "Circumference of circle with radius " << (first + (delta*i)) << " = "
                << std::setprecision(5) << result << endl;
            }
        }
        else if (comm == 'R' || comm == 'r')
        {
            for (int i = 0; i < ender; i++)
            {
                double result = findSqrtValue(first + (delta*i));
                std::cout << std::setprecision(2) << "Square root of " << (first + (delta*i)) << " = "
                << std::setprecision(5) << result << endl;
            }
        }
        else if (comm == 'E' || comm == 'e')
        {
            for (int i = 0; i < ender; i++)
            {
                int result = findNextEvenValue(first + (delta*i));
                std::cout << std::setprecision(2) << "Next even number for " << (first + (delta*i)) << " = "
                << std::setprecision(0) << result << endl;
            }
        }
        else if (comm == 'L' || comm == 'l')
        {
            for (int i = 0; i < ender; i++)
            {
                double result = findLuckyNumValue(first + (delta*i));
                std::cout << std::setprecision(2) << "Lucky number of " << (first + (delta*i)) << " = "
                << std::setprecision(5) << result << endl;
            }
        }
        else if (comm == 'N' || comm == 'n')
        {
            for (int i = 0; i < ender; i++)
            {
                double result = findNyanCatValue(first + (delta*i));
                std::cout << std::setprecision(2) << "nyanCat (" << (first + (delta*i)) << ") = "
                << std::setprecision(5) << result << endl;
            }
        }
        else if (comm == 'I' || comm == 'i')
        {
            string filename;
            cout << "Please enter input filename: ";
            cin >> filename;
            const char *c = filename.c_str();
            readDataFromFile(c);
        }
        else if (comm == 'O' || comm == 'o')
        {
            string filename;
            cout << "Please enter output filename: ";
            cin >> filename;
            const char *c = filename.c_str();
            writeDataToFile(c);
        }

    }while (comm != 'Q' || comm != 'q');

    return 0;
}
