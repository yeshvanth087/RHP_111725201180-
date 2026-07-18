#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cout << "Enter a binary string: ";
    cin >> s;

    unordered_map<int, int> firstIndex;
    int prefixSum = 0;
    int maxLen = 0;

    firstIndex[0] = -1;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '0')
            prefixSum += -1;
        else
            prefixSum += 1;

        if(firstIndex.find(prefixSum) != firstIndex.end())
            maxLen = max(maxLen, i - firstIndex[prefixSum]);
        else
            firstIndex[prefixSum] = i;
    }

    cout << "Longest balanced substring length = "<< maxLen << endl;

    return 0;
}