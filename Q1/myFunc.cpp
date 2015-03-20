#include "myFunc.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

void initialize()
{
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2014" << endl;
    cout << "Programming Assignment 2" << endl;
    cout << "Maximum computation is: 10\n" << endl;
}

bool checkCode(char c)
{
    if (c == 'S' || c == 's' || c == 'C' || c == 'c' || c == 'R' || c == 'r' ||
        c == 'E' || c == 'e' || c == 'L' || c == 'l' || c == 'N' || c == 'n' ||
        c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'Q' || c == 'q')
        return true;
    else
        return false;
}

void writeDataToFile(const char *c)
{
    srand(time(NULL));
    int first = rand() % 11;
    int last = rand() % 10 + 20;
    int delta = rand() % 5 + 5;
    int ender = 0;
    int i = first;

    while (i<last)
    {
        i = i + delta;
        ender = ender + 1;
    }
    std::ofstream output;
    output.open(c);

    for (int i = 0; i < ender; i++)
    {
        double result = first + (i*delta);
        double nyanresult = pow(2*result,result);
        output <<  "nyanCat(" << std::fixed << std::setprecision(2) << result << ") = " <<
        std::setprecision(5) << nyanresult << endl;
    }
    output.close();
    cout << "File has been written." << endl;
}

void readDataFromFile(const char *c)
{
    ifstream input(c);
    double numbers [3];
    for (int i = 0; i < 3; i++)
    {
        input >> numbers[i];
    }
    input.close();
    std::cout << std::fixed;
    if (input.fail())
    {
        cout << "File does not exist." << endl;
    }
    else
        std::cout << std::setprecision(5) << "Successfully read data from file: Start " << numbers[0] << " Finish "
        << numbers[1] << " Step " << numbers[2] <<  "." << endl;
}

double findNyanCatValue(double d)
{
    return pow((2*d),d);
}

double findSquareAreaValue(double d)
{
    return pow(d,2);
}

double findCircumValue(double d)
{
    double pi = 3.14;
    return (2*d*pi);
}

double findSqrtValue(double d)
{
    return sqrt(d);
}

double findLuckyNumValue(double d)
{
    srand (d);
    return rand();
}

int findNextEvenValue(double d)
{
    int i = d;
    if ((i+1)%2 == 0)
        return i+1;
    else
        return i+2;
}
