#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v(n);
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        int len, p;
        cin >> len >> p;
        v[i] = {i + 1, i + len, p};
    }
    for (int i = 0; i < n; i++) {
        int temp = 0;
        if (get<1>(v[i]) > n) continue;
        for (int j = 0; j < get<0>(v[i]); j++) {
            temp = max(dp[j], temp);
        }
        dp[get<1>(v[i])] = max(dp[get<1>(v[i])], temp + get<2>(v[i]));
    }
    int result = 0;
    for (int i : dp) result = max(result, i);
    cout << result;
    return 0;
}
