#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    getline(cin, str1);
    cout << "Enter the second string: ";
    getline(cin, str2);

    const int l1 = str1.length();
    const int l2 = str2.length();

    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    int max = 0;
    int endPos = 0;
    for (int i = 1; i <= l1; i++)
        for (int j = 1; j <= l2; j++)
            if (str1[i - 1] == str2[j -1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1 ;
                if (dp[i][j] > max) {
                    max = dp[i][j];
                    endPos = i;
                }
            }

    string result = str1.substr(endPos - max, max);
    cout << "The longest common substring is: " << result << endl;
    cout << "The length of the string is: " << max << endl;

    return 0;
}