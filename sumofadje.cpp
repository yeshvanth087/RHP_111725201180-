#include <iostream>
using namespace std;
int main()
{
    int r, c;
    cin >> r >> c;
    int a[100][100];
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    int row, col;
    cin >> row >> col;
    int dr[] = {-1,-1,-1,0,0,1,1,1};
    int dc[] = {-1,0,1,-1,1,-1,0,1};
    int sum = 0;
    for(int k = 0; k < 8; k++)
    {
        int nr = row + dr[k];
        int nc = col + dc[k];
        if(nr >= 0 && nr < r && nc >= 0 && nc < c)
        {
            sum += a[nr][nc];
        }
    }
    cout << "Adjacent Cells Sum = " << sum;
    return 0;
}