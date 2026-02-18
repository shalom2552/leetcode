/*
Motivation: Bucket Sort. We find the range of the values and puting each value into
    a bucket at index relative to it in the range (num/range), for each bucket, save
    the min and max values of the bucket. Finally we can compute the maximum gap
    using the max and min values respectively, of each non empty consecutive bucket.
Complexity: 
    Time - O(n): Looping over the array three times.
    Space - O(n): Storing bucket for each value at worst case
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {

        // no gap for less than two elements
        if (nums.size() < 2) {
            return 0;
        }

        // find the range of the values
	    int min_val = nums[0];
	    int max_val = nums[0];
	    for (std::size_t i = 0; i < nums.size(); ++i) {
		    min_val = std::min(min_val, nums[i]);
	    	max_val = std::max(max_val, nums[i]);
    	}
        
	    // represents the number of values in the range
        // max prevent devide by zero
	    const std::size_t range = std::max(max_val - min_val, 1);

	    // a map represents n buckets as k/n where k is a value in nums
	    std::vector<std::pair<int, int>> buckets(nums.size(), {INT_MAX, INT_MIN});

        // insert all the elements into buckets
        for (int num : nums) {

            // rough relative position in the sorted array
            int pos = (nums.size() - 1) * (num - min_val) / range;

            // update the min and max of the current buccket
            int new_min = std::min(buckets[pos].first, num);
            int new_max = std::max(buckets[pos].second, num);

            buckets[pos] = {new_min, new_max};
        }
        
        // find the max gap between each bucket
        int max_gap = 0;
        int prev = min_val;
        for (int i = 0; i < nums.size(); i++) {

            // skip empty buckets
            if (buckets[i].first == INT_MAX) {
                continue;
            }

            // update the maximum gap
            int gap = buckets[i].first - prev;
            max_gap = std::max(max_gap, gap);

            // save max value of current bucket
            prev = buckets[i].second;
        }

        return max_gap;
    }
};