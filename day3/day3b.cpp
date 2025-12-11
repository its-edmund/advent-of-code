#include <bits/stdc++.h>

using namespace std;

int main() {
    long long ans = 0;

    std::string input;
    std::fstream in_file("./day3_input.txt");

    while (std::getline(in_file, input)) {
        int max_jolt = -1;
        for (int i = 0; i < input.size(); i++) {
            for (int j = i + 1; j < input.size(); j++) {
                string cand = string(1, input[i]) + string(1, input[j]);
                max_jolt = max(max_jolt, stoi(cand));
            }
        }
        ans += max_jolt;
    }

    cout << ans << endl;
}
