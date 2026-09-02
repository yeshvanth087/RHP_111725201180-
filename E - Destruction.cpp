#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

int find(vector<int>& ldr, int node) {
    if (ldr[node] != node) {
        ldr[node] = find(ldr, ldr[node]);
    }
    return ldr[node];
}

void join(vector<int>& ldr, int lt, int rt) {
    ldr[find(ldr, rt)] = find(ldr, lt);
}

void solve() {
    int N, E;
    cin >> N >> E;

    vector<int> ldr(N + 1);

    vector<pair<int, pair<int, int>>> edges;

    for (int node = 1; node <= N; node++)
        ldr[node] = node;

    while (E--) {
        int a, b, cost;
        cin >> a >> b >> cost;

        if (cost <= 0) {
            join(ldr, a, b);
        }
        else {
            edges.push_back(make_pair(cost, make_pair(a, b)));
        }
    }


    sort(edges.begin(), edges.end());

    ll reward = 0;

    for (auto vec : edges) {
        int cost = vec.first;
        auto edge = vec.second;

        int a = edge.first;
        int b = edge.second;

        if (find(ldr, a) != find(ldr, b)) {
            join(ldr, a, b);
        }
        else {
            reward += cost;
        }
    }

    cout << reward << endl;
}

int main() {
    solve();
}