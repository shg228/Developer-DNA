#include <iostream>
#include <string.h>

using namespace std;
int main(int argc, char **argv)
{
    float sine[] = {-0.93, -0.60, -0.33, -0.13, 0.00, 0.00, -0.13, -0.33, -0.60, -0.93};
    int cols = 31;
    char parts[]={'+', '-'};

    //solution
    int sizeOfSine = sizeof(sine)/sizeof(float);
    int rows = sizeOfSine * 2;
    int middleOfLine = cols/2 ;
    int leftPeak = middleOfLine / 2;
    char result[rows][cols];
    memset(result, ' ', sizeof(char) * rows * cols);

    int col;
    for(int row = 0; row < rows; row++)
    {
        col = middleOfLine + (leftPeak - middleOfLine) * (sine[row % sizeOfSine] + 1);
        result[row][col] = parts[row < sizeOfSine ? 0 : 1];
        result[row][cols - col] = parts[row < sizeOfSine ? 1 : 0];
        result[row][cols - 1] = 0; //set end of line
        cout << result[row] << endl;
    }

    return 0;
}
