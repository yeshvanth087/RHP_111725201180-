#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> shari(n), neta(m);
    for(int i = 0; i < n; i++) cin >> shari[i];
    for(int i = 0; i < m; i++) cin >> neta[i];

    sort(shari.begin(), shari.end());
    sort(neta.begin(), neta.end());

    int count = 0;
    for (int a1 = n - 1, b1 = m - 1; a1 >= 0 && b1 >= 0; ) {
        if (neta[b1] <= shari[a1]*2) {
            count++; b1--; a1--;
        }
        else
            b1--;
    }
    cout << count << endl;
    return 0;
}