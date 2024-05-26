#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<int> a(k + 1);
        vector<int> b(k + 1);

        for (int i = 1; i <= k; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= k; ++i) {
            cin >> b[i];
        }

        // Include starting point
        a[0] = 0;
        b[0] = 0;

        vector<double> speeds(k);
        for (int i = 0; i < k; ++i) {
            speeds[i] = double(a[i + 1] - a[i]) / double(b[i + 1] - b[i]);
        }

        while (q--) {
            int d;
            cin >> d;

            if (d == 0) {
                cout << 0 << " ";
                continue;
            }

            // Find the segment where d lies
            int pos = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;

            if (d == a[pos]) {
                cout << b[pos] << " ";
            } else {
                int base_time = b[pos];
                int base_pos = a[pos];
                double travel_time = (d - base_pos) / speeds[pos];
                int result_time = base_time + int(travel_time);
                cout << result_time << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
