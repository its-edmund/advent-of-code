#include <bits/stdc++.h>

int main() {
    int ans = 0;
    int curr = 50;
    std::string input;
    std::fstream in_file("./day1_test_input.txt");

    while (std::getline(in_file, input)) {
        if (input[0] == 'L') {
            curr = (curr - std::stoi(input.substr(1))) % 100;
        } else {
            curr = (curr + std::stoi(input.substr(1))) % 100;
        }
        if (curr == 0) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
}
