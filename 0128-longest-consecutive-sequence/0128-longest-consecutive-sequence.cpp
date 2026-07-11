class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_map<int, bool> mp;

        // Store every number
        for (int num : nums) {
            mp[num] = false;
        }

        int longest = 0;

        for (int num : nums) {

            // Skip if already processed
            if (mp[num])
                continue;

            mp[num] = true;

            int length = 1;

            // Go left
            int left = num - 1;
            while (mp.find(left) != mp.end()) {
                mp[left] = true;
                length++;
                left--;
            }

            // Go right
            int right = num + 1;
            while (mp.find(right) != mp.end()) {
                mp[right] = true;
                length++;
                right++;
            }

            longest = max(longest, length);
        }

        return longest;
    }
};