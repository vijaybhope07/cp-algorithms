#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        sort(power.begin(), power.end());
        vector<int> uniquePowers;
        vector<long long> totalDamages;
        for (int i = 0; i < n; i++) {
            int currentPower = power[i];
            long long sum = currentPower;
            while (i + 1 < n && power[i + 1] == currentPower) {
                i++;
                sum += currentPower;
            }
            uniquePowers.push_back(currentPower);
            totalDamages.push_back(sum);
        }
        vector<long long> dp(uniquePowers.size() + 1, 0);
        for (int j = uniquePowers.size() - 1; j >= 0; j--) {
            long long skip = dp[j + 1];
            long long take = totalDamages[j];
            int nextIndex = j + 1;
            while (nextIndex < uniquePowers.size() && uniquePowers[nextIndex] - uniquePowers[j] <= 2)
                nextIndex++;
            take += dp[nextIndex];
            dp[j] = max(skip, take);
        }
        return dp[0];
    }
};
