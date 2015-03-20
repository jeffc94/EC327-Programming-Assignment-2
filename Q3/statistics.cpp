#include "statistics.h"
#include <cmath>

float getMean(int myArray[], int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + myArray[i];
    }
    return sum/size;
}

float getStdDev(int myArray[], int size)
{
    //First find the mean
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + myArray[i];
    }
    float mean = (sum/size);
    //Initialize array of same size
    float diffs [size];
    float result = 0;
    //Take sum of all difference between numbers and mean squared
    for (int i = 0; i < size; i++)
    {
        diffs[i] = myArray[i] - mean;
        diffs[i] = diffs[i]*diffs[i];
        result = result + diffs[i];
    }
    float answer = sqrt(result/size);

    return answer;
}
