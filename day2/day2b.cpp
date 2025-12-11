#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string &s, const char &delim) {
    vector<string> tokens;
    string token;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != delim) {
            token += s[i];
        } else {
            tokens.push_back(token);
            token.clear();
        }
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}

bool repeat_check(const string &s) {
    for (int i = 1; i <= s.size() / 2; i++) {
        if (s.size() % i == 0) {
            string slice = s.substr(0, i);
            int c = s.size() / i;
            string temp = "";
            while (c--) {
                temp += slice;
            }
            if (s == temp)
                return true;
        }
    }
    return false;
}

int main() {
    long long ans = 0;
    std::string input;
    std::fstream in_file("./day2_input.txt");

    std::getline(in_file, input);

    vector<string> id_ranges = split(input, ',');

    for (size_t i = 0; i < id_ranges.size(); i++) {
        vector<string> min_max = split(id_ranges[i], '-');
        long long min_val = stoll(min_max[0]);
        long long max_val = stoll(min_max[1]);

        for (long long j = min_val; j <= max_val; j++) {
            string j_str = to_string(j);
            if (repeat_check(j_str)) {
                ans += j;
            }
        }
    }

    std::cout << ans << std::endl;
}
