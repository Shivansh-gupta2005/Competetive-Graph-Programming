#include <iostream>
#include <vector>
#include <string>

int countCuts(const std::string& s) {
    int transitions = 0;
    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] != s[i-1]) {
            transitions++;
        }
    }
    if (transitions == 1) {
        return transitions + 1;
    } else {
        return transitions;
    }
}

int main() {
    int t;
    std::cin >> t;
    std::vector<int> results(t);

    for (int i = 0; i<t; ++i){
        std::string s;
        std::cin >> s;
        results[i] = countCuts(s);
    }

    for (int result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}