class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1000000007;

        long long resource = k;
        long long op = 0;
        long long ans = 0;

        for (int x : nums) {
            if (resource < x) {
                long long need = (x - resource + k - 1) / k;

                __int128 add =
                    (__int128)need * (2LL * op + need + 1) / 2;

                ans = (ans + (long long)(add % MOD)) % MOD;

                op += need;
                resource += need * 1LL * k;
            }

            resource -= x;
        }

        return ans;
    }
};