/*
Motivation: We'll use the Boyer-Moore Voting Algorithm, to find candidates.
    The only three options we can have is 0, 1, 2 numbers, 
    as such (3 or more cannot be).
    Using two candidates and two counters for the case, 
    where we have 2 numbers as such.
Complexity: 
    Time - O(n): Looping over the array twice.
    Space - O(1): Auxiliary
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // Set diffrent default candidates
        int candidate_a = 0;
        int candidate_b = 1;
        vector<int> result = {};

        // Counts to hold each candidate appearances
        int count_a = 0;
        int count_b = 0;

        // Loop over the array and find candidates
        for (int num : nums) {
            
            // if cuurent number is candidate_a update the count 
            if (num == candidate_a) {
                ++count_a;
            }

            // if cuurent number is candidate_b update the count 
            else if (num == candidate_b) {
                ++count_b;
            }

            // check for a new candidate
            else {
                
                // find new candidate_a if current one is not valid
                if (count_a == 0) {
                    candidate_a = num;
                    count_a = 1;
                }
                
                // find new candidate_b if current one is not valid
                else if (count_b == 0) {
                    candidate_b = num;
                    count_b = 1;
                }

                // the number is neither candidates
                else {
                    --count_a;
                    --count_b;
                }
            }
        }

        // Count candidates appearences
        count_a = 0;
        count_b = 0;
        size_t n = nums.size();

        for (int num : nums) {
            if (num == candidate_a) {
                ++count_a;
            }
            if (num == candidate_b) {
                ++count_b;
            }
        }
        
        // candidates must be > n/3
        int threshold = n / 3;
        if (count_a > threshold) {
            result.push_back(candidate_a);
        }
        if (count_b > threshold) {
            result.push_back(candidate_b);
        }

        //might be empty if no candidate is valid
        return result;

    }
};

