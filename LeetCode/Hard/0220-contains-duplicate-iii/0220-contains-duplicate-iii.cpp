/*
Motivation: Sliding window with a sorted multiset.
    We slide a window of size indexDiff over the array. For each new
    element, we find the closest values in the set. 
    If either neighbor is within valueDiff, we return true. 
    Then we insert the element and remove the oldest one if the
    window is too big.
Complexity:
    Time - O(n * log k): loop over nums once and do a tree operations.
    Space - O(k): the multiset holds at most indexDiff elements.
Could also be solved with bucket sort in O(n) time, but the multiset
approach is simpler.
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {

        // multiset to hold indexDiff last elements (allow duplicates)
        multiset<int> set;

        for (size_t i = 0; i < nums.size(); ++i) {
            int curr = nums[i];

            // get the closest grater value
            auto upper = set.lower_bound(curr);

            // check distance from lower and upper values if the set is not empty
            if (upper != set.end() && abs(*upper - curr) <= valueDiff) {
                return true;
            }
            // check on the previous of upper value if upper is not the smallest
            if (upper != set.begin() && abs(*prev(upper) - curr) <= valueDiff) {
                return true;
            }

            set.insert(curr);  // insert current value
            if (set.size() > indexDiff) {
                // remove oldest value
                set.erase(set.find(nums[i - indexDiff]));
            }
        }

        // no match found
        return false;
    }
};