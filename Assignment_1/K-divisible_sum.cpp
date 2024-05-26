#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        
        // Calculate the minimum possible maximum element
        long long result = (k + n - 1) / n;

        if (k % n == 0) {
            std::cout << result << std::endl; // If result is an integer, print it
        } else {
            std::cout << result + 1 << std::endl; // If result is not an integer, print result + 1
        }
    }
    
    return 0;
}
