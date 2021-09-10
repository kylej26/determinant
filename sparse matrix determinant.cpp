#include<iostream>
#include<math.h>
using namespace std;
#define MAX 100
int determinant(int matrix[10][10], int n) {
    int det = 0;
    int submatrix[10][10];
    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
        }
    }
    return det;
}





int main()
{
    int n = 0, i, j;
    int r=n, c=n;
    int matrix[10][10];
    cout << "Enter the size of the matrix:" << endl;
    cin >> n;
    cout << "Enter the elements of the matrix:" << endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> matrix[i][j];
    cout << "The entered matrix is:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << "The new sparse matrix is \nRow  Column  value " << endl;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
        {
            if (matrix[i][j] != 0)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
  
   

    cout << "Determinant of the matrix is " << determinant(matrix, n) << endl;
    return 0;
}