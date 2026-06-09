/*
Motivation: Take the whole array k times.
    Then find the min and max and multiply by k.
Complexity:
    Time - O(n): Scan the array once.
    Space - O(1): Auxiliary.
*/
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int min = nums[0];
        int max = nums[0];
        for (int n : nums) {
            max = std::max(max, n);
            min = std::min(min, n);
        }

        return k * static_cast<long long>(max - min);
    }
};
