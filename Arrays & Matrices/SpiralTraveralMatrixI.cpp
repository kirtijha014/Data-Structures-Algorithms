#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int row = matrix.size(), col = matrix[0].size();
        int count = 0, totalElements = row * col;
        int minRow = 0, minCol = 0, maxRow = row - 1, maxCol = col - 1;
        vector<int> answer;
        while(count < totalElements)
        {
            //top wall
            for(int i = minRow, j = minCol; j <= maxCol && count < totalElements; j++)
            {
                count++;
                cout << " i - top wall : " << i << " j - top wall : " << j << endl; 
                answer.push_back(matrix[i][j]);
            }
            minRow++;
            
            // right wall
            for(int i = minRow, j = maxCol; i <= maxRow && count < totalElements; i++)
            {
                count++;
                 cout << " i - right wall : " << i << " j - right wall : " << j << endl; 
                answer.push_back(matrix[i][i]);
            }
            maxCol--;
            // bottom wall
            for(int i = maxRow, j = maxCol; j >= minCol && count < totalElements; j--)
            {
                count++;
                 cout << " i - bottom wall : " << i << " j - bottom wall : " << j << endl; 
                answer.push_back(matrix[i][j]);
            }
            maxRow--;
            
            //left wall 
            for(int i = maxRow, j = minCol; i >= minRow && count < totalElements; i--)
            {
                count++;
                 cout << " i - left wall : " << i << " j - left wall : " << j << endl; 
                answer.push_back(matrix[i][j]);
            }
            minCol++;
        }
        return answer;
        /*
       int row = matrix.size(), col = matrix[0].size();
       int count = 0, totalElements = row * col;
        int minRow = 0, minCol = 0, maxRow = row - 1 , maxCol = col - 1;
        vector<int>answer;
        while(count < totalElements)
        {
            //top wall
            for(int i = minRow, j = minCol; j <=  maxCol && count < totalElements; j++)
            {
                count ++;
                 cout << " i - top wall : " << i << " j - top wall : " << j << endl; 
                answer.push_back(matrix[i][j]);
            }
            minRow++;
             //right wall
            for(int i = minRow , j = maxCol ; i <= maxRow && count < totalElements ;i++)
            {
                count++;
                cout << " i - right wall : " << i << " j - right wall : " << j << endl; 
                answer.push_back(matrix[i][j]);
                
            }
            maxCol--;
            //bottom wall
            for(int i = maxRow , j = maxCol; j >= minCol && count < totalElements ; j--)
            {
                count++;
                 cout << " i - bottom wall : " << i << " j - bottom wall : " << j << endl;
                answer.push_back(matrix[i][j]);
                
            }
            maxRow--;
            //left Wall
            for(int i = maxRow, j = minCol; i >= minRow && count < totalElements; i--)
            {
                count++;
                cout << " i - left wall : " << i << " j - left wall : " << j << endl; 
                answer.push_back(matrix[i][j]);
            }
            minCol++;
            
           
            
        }
        return answer;*/
}
int main()
{
     int rows, cols;
    cout << "Enter rows and columns : " ; 
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows);
    for(int i = 0; i < rows; i++)
    {
        matrix[i].assign(cols,0);
        for(int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<int>answer = spiralOrder(matrix);
    cout << "\n\nThe final Answer : " ;
    for(int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }

}