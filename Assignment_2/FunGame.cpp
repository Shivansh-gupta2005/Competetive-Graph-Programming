#include <iostream>
#include <vector>

using namespace std;

void solve(int N, vector<int>& nums) {
    vector<int> result;
    int start = 0;
    int end = N - 1;

    while (start <= end) {
        int a_pick = nums[start];
        int b_pick = nums[end];

        if (a_pick < b_pick) {
            result.push_back(2);
            start++;
        } else if (a_pick > b_pick) {
            result.push_back(1);
            end--;
        } else {
            result.push_back(0);
            start++;
            end--;
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
    vector<int> nums(N);

    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    solve(N, nums);

    return 0;
}
