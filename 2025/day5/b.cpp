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

void print_vector(const vector<vector<ll>>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << "{" << v[i][0] << ", " << v[i][1] << "}";
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << "\n";
}

bool in_intervals(const vector<vector<ll>>& intervals, ll val) {
    for (size_t i = 0; i < intervals.size(); i++) {
        if (intervals[i][0] <= val && intervals[i][1] >= val) {
            return true;
        }
    }
    return false;
}

void merge_intervals(vector<vector<ll>>& intervals) {
    if (intervals.size() < 2)
        return;
    vector<vector<ll>> new_intervals;
    vector<ll> curr_interval = intervals[0];
    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= curr_interval[0] &&
            intervals[i][0] <= curr_interval[1]) {
            curr_interval[1] = max(curr_interval[1], intervals[i][1]);
        } else {
            new_intervals.push_back(curr_interval);
            curr_interval = intervals[i];
        }
    }
    new_intervals.push_back(curr_interval);
    intervals = new_intervals;
}

void insert_interval(vector<vector<ll>>& intervals,
                     const vector<ll>& new_interval) {
    if (intervals.empty()) {
        intervals.push_back(new_interval);
        return;
    }

    if (intervals[0][0] > new_interval[0]) {
        intervals.insert(intervals.begin(), new_interval);
        return;
    }

    for (size_t i = 0; i < intervals.size() - 1; i++) {
        if (intervals[i][0] <= new_interval[0] &&
            intervals[i + 1][0] >= new_interval[0]) {
            intervals.insert(intervals.begin() + i + 1, new_interval);
            return;
        }
    }

    intervals.push_back(new_interval);
}

void solve() {
    cout << g_input_path << endl;
    string input;
    ifstream in_file(g_input_path);

    unordered_set<ll> fresh;
    ll ans = 0;

    vector<vector<ll>> intervals;

    while (getline(in_file, input)) {
        if (input == "")
            break;

        DBG(input);
        ll min_num = stoll(input.substr(0, input.find("-")));
        ll max_num = stoll(input.substr(input.find("-") + 1));

        insert_interval(intervals, {min_num, max_num});
        print_vector(intervals);
        merge_intervals(intervals);
        print_vector(intervals);
    }

    /* print_vector(intervals); */

    for (size_t i = 0; i < intervals.size(); i++) {
        ans += intervals[i][1] - intervals[i][0] + 1;
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