/*
Motivation: Hashmap and Bucket-Sort approach. 
    Use hashmap to store each element occurrences count,
    then loop over the bucket k times from the most to least,
    add elements up until k and return.
Complexity: 
    Time - O(n): loop over the list once and over the bucket.
    Space - O(n): hashmap and bucket.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // hashmap to store elements occurrences
        std::unordered_map<int, int> hist;
        // bucket to store the elements by occurrences by index
        std::vector<vector<int>> bucket(nums.size() + 1);
        // list to store the result
        std::vector<int> result;

        // loop over nums and count each element occurrences
        for (int num : nums) {
            // increment element occurrences
            hist[num] += 1;
        }
        
        // fill the bucket with nums by their count
        for (std::pair<const int, int>& elem : hist) {
            int num = elem.first;
            int count = hist[num];
            // add num to the index representing its count
            bucket[count].push_back(num);
        }

        // loop over the bucket in reverse to find the kth most element
        for (int i = bucket.size() -1; i > 0; --i) {
            // extract elements from the current bucket
            for (int num : bucket[i]) {
                result.push_back(num);
                // we found k elements
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
