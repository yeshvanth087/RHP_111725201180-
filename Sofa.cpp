#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

struct Sofa {
    int fsr, fsc, ssr, ssc;
    int moves;
    char dir;

    Sofa(int fr, int fc, int sr, int sc, char d, int m)
        : fsr(fr), fsc(fc), ssr(sr), ssc(sc),
          moves(m), dir(d) {}
};

int R, C;
vector<vector<char>> grid;
queue<Sofa> q;
unordered_set<string> vis;

bool freeCell(int r, int c) {
    return r >= 0 && r < R &&
           c >= 0 && c < C &&
           grid[r][c] != 'H';
}

bool canPlace(int fr, int fc, int sr, int sc) {
    return freeCell(fr, fc) && freeCell(sr, sc);
}

bool canRotate(int r1, int c1, int r2, int c2,
               int r3, int c3, int r4, int c4) {
    return freeCell(r1, c1) && freeCell(r2, c2) &&
           freeCell(r3, c3) && freeCell(r4, c4);
}

bool isAdd(int fr, int fc, int sr, int sc, char dir) {
    string key = to_string(fr) + "-" + to_string(fc) + "-" +
                 to_string(sr) + "-" + to_string(sc) + "-" + dir;

    if (vis.count(key))
        return false;

    vis.insert(key);
    return true;
}

void addState(int fr, int fc, int sr, int sc,
              char dir, int moves) {
    if (!canPlace(fr, fc, sr, sc))
        return;

    if (isAdd(fr, fc, sr, sc, dir))
        q.emplace(fr, fc, sr, sc, dir, moves);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    grid.assign(R, vector<char>(C));

    int fsr = -1, fsc = -1, ssr = -1, ssc = -1;
    int sofaCount = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 's') {
                if (sofaCount == 0) {
                    fsr = i;
                    fsc = j;
                } else if (sofaCount == 1) {
                    ssr = i;
                    ssc = j;
                }
                sofaCount++;
            }
        }
    }

    if (sofaCount != 2) {
        cout << "Impossible\n";
        return 0;
    }

    char startDir = (fsr == ssr) ? 'H' : 'V';

    if (!canPlace(fsr, fsc, ssr, ssc)) {
        cout << "Impossible\n";
        return 0;
    }

    addState(fsr, fsc, ssr, ssc, startDir, 0);

    while (!q.empty()) {
        Sofa s = q.front();
        q.pop();

        if (grid[s.fsr][s.fsc] == 'S' &&
            grid[s.ssr][s.ssc] == 'S') {
            cout << s.moves << '\n';
            return 0;
        }

        int nr = s.moves + 1;

        if (s.dir == 'H') {
            addState(s.fsr, s.fsc + 1,
                     s.ssr, s.ssc + 1, 'H', nr);

            addState(s.fsr, s.fsc - 1,
                     s.ssr, s.ssc - 1, 'H', nr);

            addState(s.fsr - 1, s.fsc,
                     s.ssr - 1, s.ssc, 'H', nr);

            addState(s.fsr + 1, s.fsc,
                     s.ssr + 1, s.ssc, 'H', nr);

            if (canRotate(
                    s.fsr, s.fsc,
                    s.fsr, s.fsc + 1,
                    s.fsr + 1, s.fsc,
                    s.fsr + 1, s.fsc + 1)) {

                addState(s.fsr, s.fsc,
                         s.fsr + 1, s.fsc, 'V', nr);

                addState(s.fsr, s.fsc + 1,
                         s.fsr + 1, s.fsc + 1, 'V', nr);
            }

            if (canRotate(
                    s.fsr - 1, s.fsc,
                    s.fsr - 1, s.fsc + 1,
                    s.fsr, s.fsc,
                    s.fsr, s.fsc + 1)) {

                addState(s.fsr - 1, s.fsc,
                         s.fsr, s.fsc, 'V', nr);

                addState(s.fsr - 1, s.fsc + 1,
                         s.fsr, s.fsc + 1, 'V', nr);
            }
        } else {
            addState(s.fsr + 1, s.fsc,
                     s.ssr + 1, s.ssc, 'V', nr);

            addState(s.fsr - 1, s.fsc,
                     s.ssr - 1, s.ssc, 'V', nr);

            addState(s.fsr, s.fsc - 1,
                     s.ssr, s.ssc - 1, 'V', nr);

            addState(s.fsr, s.fsc + 1,
                     s.ssr, s.ssc + 1, 'V', nr);

            if (canRotate(
                    s.fsr, s.fsc,
                    s.fsr + 1, s.fsc,
                    s.fsr, s.fsc + 1,
                    s.fsr + 1, s.fsc + 1)) {

                addState(s.fsr, s.fsc,
                         s.fsr, s.fsc + 1, 'H', nr);

                addState(s.fsr + 1, s.fsc,
                         s.fsr + 1, s.fsc + 1, 'H', nr);
            }

            if (canRotate(
                    s.fsr, s.fsc - 1,
                    s.fsr + 1, s.fsc - 1,
                    s.fsr, s.fsc,
                    s.fsr + 1, s.fsc)) {

                addState(s.fsr, s.fsc - 1,
                         s.fsr, s.fsc, 'H', nr);

                addState(s.fsr + 1, s.fsc - 1,
                         s.fsr + 1, s.fsc, 'H', nr);
            }
        }
    }

    cout << "Impossible\n";
    return 0;
}