#include <bits/stdc++.h>
#include <cassert>

using namespace std;

namespace utils {
static vector<string> split(const string& s, const char& delim) {
    vector<string> tokens;
    string token;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] != delim) {
            token += s[i];
        } else {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        }
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}
} // namespace utils
