#include "../utils.h"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vi = vector<int>;
using vll = vector<long long>;
using vpii = vector<pii>;

const ll INF64 = (ll)4e18;
const int INF = (int)1e9;

static bool g_debug = false;
static string g_input_path = "test.txt";

#define DBG(x)                                                                 \
    do {                                                                       \
        if (g_debug)                                                           \
            cerr << #x << " = " << (x) << '\n';                                \
    } while (0)

void solve() {
    std::string input;
    ifstream in_file(g_input_path);

    ll ans = 0;

    vector<vector<string>> lines;

    while (getline(in_file, input)) {
        DBG(input);
        vector<string> split_in = utils::split(input, ' ');
        lines.push_back(split_in);
    }

    for (int i = 0; i < lines[0].size(); i++) {
        ll sub_ans = 0;
        for (int j = 0; j < lines.size() - 1; j++) {
            if (j == 0 && lines.back()[i][0] == '*') {
                sub_ans = 1;
            }
            switch (lines.back()[i][0]) {
            case '*':
                sub_ans *= stoll(lines[j][i]);
                break;
            case '+':
                sub_ans += stoll(lines[j][i]);
                break;
            }
            DBG(sub_ans);
        }
        ans += sub_ans;
    }

    cout << ans << endl;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    g_input_path = "test.txt";

    for (int i = 1; i < argc; i++) {
        string a = argv[i];
        if (a == "--debug") {
            g_debug = true;
            g_input_path = "example.txt";
        } else {
            g_input_path = a;
        }
    }

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}