#include "../utils.hpp"
#include <bits/stdc++.h>

using namespace std;

template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream& operator<<(ostream& os, const T_container& v) {
    os << '{';
    string sep;
    for (const T& x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

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

#define dbg_out(x)                                                             \
    do {                                                                       \
        if (g_debug)                                                           \
            cerr << #x << " = " << (x) << '\n';                                \
    } while (0)

void solve() {
    std::string input;
    ifstream in_file(g_input_path);

    ll ans = 0;

    vector<string> lines;
    vector<int> widths;
    vector<char> operations;
    vector<vector<string>> processed;

    while (getline(in_file, input)) {
        dbg_out(input);
        lines.push_back(input);
    }

    string operation_str = lines.back();
    int counter = 0;
    for (int i = 0; i < operation_str.size(); i++) {
        if (operation_str[i] != ' ') {
            operations.push_back(operation_str[i]);
            if (counter > 0) {
                widths.push_back(counter);
            }
            counter = 0;
        } else {
            counter++;
        }
    }

    if (counter > 0) {
        widths.push_back(counter + 1);
    }

    for (size_t i = 0; i < processed)

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