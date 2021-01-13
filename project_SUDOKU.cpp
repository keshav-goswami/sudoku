#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define N 9
void print(int A[N][N])
{
    cout<<"\nSOLUTION: \n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

bool check(int A[N][N], int r,
                       int c, int n)
{
    //CHECKING ROWS
    for (int i = 0; i < 9; i++)
    {
        if (A[r][i] == n)
            return false;
    }
    //CHECKING COLUMNS
    for (int i = 0; i < 9; i++)
    {
        if (A[i][c] == n)
            return false;
    }

    //CHECKING SUB MATRIX
    int R = r - r % 3;
    int C = c - c % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (A[i + R][j + C] == n)
                return false;
        }
    }

    return true;
}

bool SOLUTION(int A[N][N], int r, int c)
{

    if (r == N - 1 && c == N)
        return true;

    if (c == N)
    {
        r++;
        c = 0;
    }

    //CALLING FUNCTION USING RECURSION
    if (A[r][c] > 0)
        return SOLUTION(A, r, c + 1);

    for (int i = 1; i <= N; i++)
    {
        if (check(A, r, c, i))
        {
            A[r][c] = i;

            if (SOLUTION(A, r, c + 1))
                return true;
        }
        A[r][c] = 0;
    }
    return false;
}

int main()
{
    cout<<"ENTER 9X9 SUDOKU: \n\n";
    int A[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin>>A[i][j];
    }

    if (SOLUTION(A, 0, 0))
        print(A);
    else
        cout << "no solution  exists " << endl;

    return 0;
}
