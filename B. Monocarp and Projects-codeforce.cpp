#include <iostream>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        long long x, y, k;
        cin >> x >> y >> k;

        long long d = y - x;
        long long ans = 0;

        for (long long i = 0; i < k; i++) {

            long long emp = x + i;

            if (emp > d) {
                ans += d * (k - i);
                break;
            }

            ans += d % emp;
        }

        cout << ans << endl;
    }

    return 0;
}