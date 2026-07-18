#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    
    int row, col;
    cout<<"Enter no. of rows and cols: ";
    cin>>row>>col;
    int matrix[row][col];
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> dpmatrix(row, vector<int>(col, 0));
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            if(i == 0){
                dpmatrix[i][j] = matrix[i][j];
            }
            else{
                if(*max_element(dpmatrix[i-1].begin(), dpmatrix[i-1].end()) != dpmatrix[i-1][j])
                dpmatrix[i][j] = matrix[i][j] + *max_element(dpmatrix[i-1].begin(), dpmatrix[i-1].end());
                
                else{
                    int first = 0, second = 0;
                    for(int x : dpmatrix[i-1]){
                        if(x > first){
                            second = first;
                            first = x;
                        }
                        else if(x > second && x != first){
                            second = x;
                        }
                    }
                    dpmatrix[i][j] = matrix[i][j] + second;
                }
            }
        }
    }
    cout<<endl;
    cout<<"Answer is: "<<*max_element(dpmatrix[row-1].begin(), dpmatrix[row-1].end());

}