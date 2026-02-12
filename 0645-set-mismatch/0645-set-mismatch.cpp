/*
Motivation: We have to unknown so we need to equations.
    We can get the diffrence between the unknown and the duplicate
    by subtracting the sum(1,...,n) from sum(nums).
    But now we have one equation with two unknown, to get another 
    equation we can do the same for the squer element.
Complexity: 
    Time - O(n): looping over nums and elements once.
    Space - O(1): auxiliary space.
*/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        // intialize sum of original elements {1, ..., n} and squer
        long long n = nums.size();
        // using Arithmetic progression sum formula
        long long sum_org = n * (n + 1) / 2;
        // using Square pyramidal number formula
        // https://en.wikipedia.org/wiki/Square_pyramidal_number
        long long sum_org_sq = n * (n + 1) * (2 * n + 1) / 6;
        
        // intialize sum of actual elements and squer
        long long sum_elem = 0;
        long long sum_elem_sq = 0;

        // calculate the sum of actual elements and thier squer
        for (int i = 0; i < nums.size(); ++i) {
            int cur = nums[i];
            sum_elem += cur;
            sum_elem_sq += cur * cur;
        }

        // in diff we have the missing - duplicate
        long long diff = sum_org - sum_elem;
        // in diff_sq we have the missing**2 - duplicate**2
        long long diff_sq = sum_org_sq - sum_elem_sq;

        // we use math to solve the two equations with two unknown
        // using (m**2 - d**2) = (m - d) * (m + d) 
        // than deviding (SS = diff_sq) / (S = diff)
        // we get SS/S = m + d, S = m - d, now we can subtract them
        long long duplicate = (diff_sq - diff * diff) / (2 * diff);
        long long missing = duplicate + diff;

        vector<int> result = {(int)duplicate, (int)missing};
        return result;
    }
};