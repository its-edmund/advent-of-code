#include <bits/stdc++.h>

using namespace std;

unordered_map<string, unordered_map<int, long long>> c;

long long max_subset(const string &s, int n) {
    if (c.find(s) != c.end() && c[s].find(n) != c[s].end()) {
        return c[s][n];
    }
    if (n == 0) {
        return 0;
    }
    if (s.size() <= n) {
        return stoll(s);
    }

    long long selected = max_subset(s.substr(0, s.size() - 1), n);
    long long not_selected =
        stoll(to_string(max_subset(s.substr(0, s.size() - 1), n - 1)) +
              s[s.size() - 1]);
    long long ans = max(selected, not_selected);
    c[s][n] = ans;
    return max(selected, not_selected);
}

int main() {
    long long ans = 0;

    std::string input;
    std::fstream in_file("./day3_input.txt");

    while (std::getline(in_file, input)) {
        long long max_jolt = max_subset(input, 12);
        ans += max_jolt;
    }

    cout << ans << endl;
}
