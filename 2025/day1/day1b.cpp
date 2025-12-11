#include <bits/stdc++.h>

int mod(int a, int b) { return (a % b + b) % b; }

int main() {
    int ans = 0;
    int curr = 50;
    std::string input;
    std::fstream in_file("./day1_input.txt");

    while (std::getline(in_file, input)) {
        int diff = std::stoi(input.substr(1));
        std::cout << input << " " << curr << " ";
        ans += (diff / 100);
        diff %= 100;
        bool zero = curr == 0;
        if (input[0] == 'L') {
            curr = curr - diff;
        } else {
            curr = curr + diff;
        }

        if ((!zero && mod(curr, 100) != curr) || curr == 0) {
            ans++;
        }
        curr = mod(curr, 100);

        std::cout << curr << " " << ans << std::endl;
    }
    std::cout << ans << std::endl;
}
