#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve(int N, vector<int>& C) {
    stack<int> chocolateStack;
    vector<int> result;

    for (int i = 0; i < N; ++i) {
        if (C[i] > 0) {
            chocolateStack.push(C[i]);
        } else if (C[i] == 0) {
            if (!chocolateStack.empty()) {
                result.push_back(chocolateStack.top());
                chocolateStack.pop();
            }
        }
    }

    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) {
            cout << " ";
        }
        cout << result[i];
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> C(N);

    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    solve(N, C);

    return 0;
}
