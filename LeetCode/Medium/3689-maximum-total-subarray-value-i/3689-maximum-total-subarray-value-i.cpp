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
        int max = *std::max_element(nums.begin(), nums.end());
        int min = *std::min_element(nums.begin(), nums.end());
        return k * static_cast<long long>(max - min);
    }
};
