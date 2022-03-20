#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>>matrix(n);
    for(int i = 0; i < n; i++)
    {
        matrix[i].assign(n,0);
    }
    int totalElements = n * n;
    int value = 1;
    int minRow = 0, minCol = 0, maxRow = n - 1, maxCol = n - 1;
    while(value <= totalElements)
    {
         for(int i = minRow, j = minCol; j <= maxCol && value < totalElements; j++)
            {
                
               // cout << " i - top wall : " << i << " j - top wall : " << j << endl; 
                matrix[i][j] = value ;
                value++;
            }
            minRow++;
            
            // right wall
            for(int i = minRow, j = maxCol; i <= maxRow && value < totalElements; i++)
            {
               
                // cout << " i - right wall : " << i << " j - right wall : " << j << endl; 
                matrix[i][j] = value ;
                 value++;
            }
            maxCol--;
            // bottom wall
            for(int i = maxRow, j = maxCol; j >= minCol && value < totalElements; j--)
            {
                
                 //cout << " i - bottom wall : " << i << " j - bottom wall : " << j << endl; 
                 matrix[i][j] = value ;
                value++;
            }
            maxRow--;
            
            //left wall 
            for(int i = maxRow, j = minCol; i >= minRow && value < totalElements; i--)
            {
                
               //  cout << " i - left wall : " << i << " j - left wall : " << j << endl; 
                matrix[i][j] = value ;
                value++;
            }
            minCol++;
    }
    return matrix;


}
int main()
{
    int n;
    cin >>n;
    vector<vector<int>>matrix = generateMatrix(n);
    for(int i = 0; i < n; i++)
    {
         for(int j = 0; j < n; j++)
         {
             cout << matrix[i][j] << " ";
         }
    }
}