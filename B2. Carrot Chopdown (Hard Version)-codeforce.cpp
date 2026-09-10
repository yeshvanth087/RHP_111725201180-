#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> freq(m + 1, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<int> suf(m + 2, 0);

    for (int i = m; i >= 1; i--) {
        suf[i] = suf[i + 1] + freq[i];
    }

    long long total = 0;
    for (int i = 1; i <= m; i++) {
        total += 1LL * i * freq[i];
    }

    vector<long long> ans(m + 1, 0);

    long long C = 2;

    for (int k = 1; C <= m; k++, C *= 2) {
        long long best = 0;

        // x * C <= m
        int maxX = m / C;

        for (int x = 1; x <= maxX; x++) {
            long long cur = 0;

            for (long long j = 1; j < C; j++) {
                cur += suf[j * x];
            }
            cur += freq[x * C];

            best = max(best, cur);
        }

        ans[k] = best;
    }

 
    int firstFull = 0;
    long long p = 1;

    while (p <= m) {
        p *= 2;
        firstFull++;
    }

    for (int k = firstFull; k <= m; k++) {
        ans[k] = total;
    }

    for (int k = 1; k <= m; k++) {
        cout << ans[k] << (k == m ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}