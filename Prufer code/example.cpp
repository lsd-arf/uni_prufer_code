#include <iostream>

using namespace std;

int main()
{
    system("cls");
    const int n = 6;
    int a[n][n] = {
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0}};

    int code[n];
    int sum = 0;
    int ind_i = -1;
    int ind_j = -1;
    for (int k = 0; k < n - 2; k++)
    {
        ind_i = -1;
        ind_j = -1;
        sum = 0;
        for (int i = 0; i < n && sum != 1; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                    sum++;

                if (sum == 1 && ind_i == -1)
                {
                    ind_i = i;
                    ind_j = j;
                }
                else if (sum != 1)
                {
                    ind_i = -1;
                    ind_j = -1;
                }
            }
            if (sum == 1)
            {
                a[ind_i][ind_j] = 0;
                a[ind_j][ind_i] = 0;
            }
        }
        code[k] = ind_j;
    }
    cout << "Code:\t";
    for (int i = 0; i < n - 2; i++)
        cout << code[i] << "\t";
    cout << endl;
}