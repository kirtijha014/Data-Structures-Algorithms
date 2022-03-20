#include<iostream>
using namespace std;
int main()
{
    int rows, cols;
    cout << "Enter rows and columns : " ; 
    cin >> rows >> cols;
    // Allocation using Array of pointers
    int **array = new int *[rows]; //dynamically creating an array of pointers of size rows
    //dynamically allocating memory to size columns for each row
    for(int i = 0; i < rows; i++)
    {
        array[i] = new int[cols];
    }
    /* Alternate way to Allocate 2-D arrays dynamically :
    // dynamically allocate memory of size `M × N`
    int* A = new int[rows* cols];
 
    // assign values to the allocated memory
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            *(A + i*cols + j) = rand() % 100;
        }
    }
    */

   // Assigning values to the matrix;
   cout << "Input matrix : \n";
   for(int i = 0; i < rows; i++)
   {
       for(int j = 0; j < cols; j++)
       {
           cin >> array[i][j];
       }
   }

   int minRow = 0, minColumn = 0, maxRow = rows - 1, maxColumn = cols - 1;
   int count = 0 , totalElement = rows  * cols;
   while(count < totalElement) // until any box is present
   {
       //for left wall

       for(int i = minRow, j = minColumn; i <= maxRow; i++)
       {
           cout << array[i][j] << "\n";
           count++;
       }
       cout << endl;
       minColumn = minColumn + 1;
       //for bottom wall
        for(int i = maxRow, j = minColumn; j <= maxColumn; j++)
       {
           cout << array[i][j] << " ";
           count++;
       }
       maxRow = maxRow - 1;
       cout << endl;

       //for right wall
        for(int i = maxRow, j = maxColumn; i >= minRow; i--)
       {
           cout << array[i][j] << "\n";
           count++;
       }
       maxColumn = maxColumn - 1;
       cout << endl;

       // for top wall
       for(int i = minRow, j = maxColumn; j >= minColumn; j--)
       {
           cout << array[i][j] << " ";
           count++;
       }
       minRow = minRow  + 1;
       cout << endl;
   }




    return 0;
}