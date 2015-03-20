#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

int DataToFile(const char* filename, int N, int M)
{
    srand (time(NULL));

    std::ofstream output;
    output.open(filename);

    if (output.fail())
        return 1;

    //Generate N random numbers from 0 to M and write them to file
    for (int i = 0; i < N; i++)
    {
        int result = rand() % M;
        output << result << std::endl;
    }
    output.close();

    return 0;
}

int DataFromFile(const char* filename, int myArray[], int &size)
{
    std::ifstream input;
    input.open(filename);

    if (input.fail())
        return 1;

    size = 0;

    //If file is empty, set array size to 0
    if (input.peek() == -1)
        size = 0;
    else
    {
        while (!input.eof())
        {
            input >> myArray[size];
            size++;
        }
    }

    return 0;
}

