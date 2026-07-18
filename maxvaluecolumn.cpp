#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
vector<int> fsmax(vector<vector<int>> dpmatrix, int R, int col){
    int first = INT_MIN;
    int second = INT_MIN;
    for(int i = 0;i < R;i++){
        if(dpmatrix[i][col] > first){
            second = first;
            first = dpmatrix[i][col];
        }
        else if(dpmatrix[i][col] > second){
            second = dpmatrix[i][col];
        }
    }
    vector<int> v1;
    v1.push_back(first);
    v1.push_back(second);
    return v1;
}
int main()
{
    
    int R, C;
    cout<<"Enter no. of rows and cols: ";
    cin>>R>>C;
    int matrix[R][C];
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> dpmatrix(R, vector<int>(C, 0));
    for(int col = 0;col < C;col++){
        for(int row = 0;row < R;row++){
            if(col == 0){
                dpmatrix[row][col] = matrix[row][0];
            }
            else{
                if(fsmax(dpmatrix, R, col-1)[0] == dpmatrix[row][col-1]){
                    dpmatrix[row][col] = matrix[row][col] + fsmax(dpmatrix, R, col-1)[1];
                }
                else{
                    dpmatrix[row][col] = matrix[row][col] + fsmax(dpmatrix, R, col-1)[0];
                }
            }
        }
    }
    cout<<endl;
    cout<<"Answer is: "<<fsmax(dpmatrix, R, C-1)[0];

    return 0;
}