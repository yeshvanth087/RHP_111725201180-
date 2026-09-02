#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr;

    while(n--) {
        long long i;
        cin >> i;
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end());

    long long ans = 0;

    for(long long x : arr) {

        auto itu = upper_bound(arr.begin(), arr.end(), x);
        auto itl = lower_bound(arr.begin(), arr.end(), x);

        long long idu = arr.end() - itu;  
        long long idl = itl - arr.begin(); 

        ans += idu * idl;
        
    }

    cout << ans << endl;
}