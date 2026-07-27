class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;               // Handle k > n

        int p = n - k;

        vector<int> temp(p);

        // Store first n-k elements
        for (int i = 0; i < p; i++) {
            temp[i] = nums[i];
        }

        // Move last k elements to front
        for (int i = p; i < n; i++) {
            nums[i - p] = nums[i];
        }

        // Put stored elements at the end
        for (int i = n - p; i < n; i++) {
            nums[i] = temp[i - (n - p)];
        }
    }
};