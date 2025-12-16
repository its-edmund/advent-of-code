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

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << '\n'
#else
#define DBG(x) ((void)0)
#endif

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
        if (intervals[i][0] > curr_interval[0] &&
            intervals[i][0] < curr_interval[1]) {
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
        if (intervals[i][0] < new_interval[0] &&
            intervals[i + 1][0] > new_interval[0]) {
            intervals.insert(intervals.begin() + i + 1, new_interval);
            return;
        }
    }

    intervals.push_back(new_interval);
}

void solve() {
    string input;
    fstream in_file("./day5_test.txt");

    unordered_set<ll> fresh;
    int ans = 0;

    vector<vector<ll>> intervals;

    while (getline(in_file, input)) {
        if (input == "")
            break;
        ll min_num = stoll(input.substr(0, input.find("-")));
        ll max_num = stoll(input.substr(input.find("-") + 1));

        insert_interval(intervals, {min_num, max_num});
        merge_intervals(intervals);
    }

    /* print_vector(intervals); */

    while (getline(in_file, input)) {
        if (in_intervals(intervals, stoll(input))) {
            ans++;
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