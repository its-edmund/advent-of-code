#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<long long>;
using vpii = vector<pii>;
using st = size_t;

const ll INF64 = (ll)4e18;
const int INF = (int)1e9;

const int DX8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int DY8[8] = {1, 0, -1, 1, -1, 1, 0, -1};

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << '\n'
#else
#define DBG(x) ((void)0)
#endif

void solve() {
    string input;
    fstream in_file("./day4_input.txt");
    vector<string> grid;

    ll ans = 0;

    while (getline(in_file, input)) {
        grid.push_back(input);
    }

    for (st i = 0; i < grid.size(); i++) {
        for (st j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '@') {
                int adj = 0;
                for (int c = 0; c < 8; c++) {
                    int new_x = i + DX8[c];
                    int new_y = j + DY8[c];
                    if (new_x >= 0 && new_x < grid.size() && new_y >= 0 &&
                        new_y < grid[i].size() && grid[new_x][new_y] == '@') {
                        adj++;
                    }
                }
                if (adj < 4) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}