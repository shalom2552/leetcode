/**
 * Motivation: Max Heap.
 *     Push all stones into a priority queue to find the biggest two in O(logn).
 *     While there are at least two stones, extract the two largest.
 *     If they are not equal, push the difference back into the heap.
 *     Repeat until one or zero stones remain and return the result.
 * Complexity: 
 *     Time - O(n*logn): Build the heap O(n), each of the n extractions takes O(log n).
 *     Space - O(n): The priority queue.
 */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue pq(stones.begin(), stones.end());
        
        // while we have at least two stones
        while( pq.size() > 1) {
            // extract the bigest two
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();

            // otherwise they are equal so we not save them (both become 0)
            if (first > second) {
                // insert the diffrence
                pq.push(first - second);
            }
        }

        // return the last stone or 0 if no stones left
        return pq.empty() ? 0 : pq.top();
    }
};

/**
 * Motivation: Brute Force selection of maximums.
 *     Loop the stones until the game rules are satisfied.
 *     In each iteration, linear scan the array and find the two largest stones.
 *     If second largest is zero, it means only one stone (or none) remains, return the largest.
 *     If they are equal, set both to zero. otherwise, set the largest to zero and the other to their difference.
 *     Continue for at most n iterations to ensure all potential pairs are handled.
 * Complexity: 
 *     Time - O(n^2): Linear scan n times.
 *     Space - O(1): Auxiliary.
 */
class SolutionBF {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::size_t n = stones.size();

        if (n == 1) {
            return stones[0];
        }
        
        // O(n^2)
        for (std::size_t i = 0; i < n; ++i) {
            
            int frst_idx = 0;
            int scnd_idx = 1;
            
            // find the two max values O(n)
            for (std::size_t j = 0; j < n; ++j) {
                // update max and set second to old max
                if (stones[frst_idx] < stones[j]) {
                    scnd_idx = frst_idx;
                    frst_idx = j;
                }
                // update second max if its not the max
                if (stones[scnd_idx] < stones[j] && frst_idx != j) {
                    scnd_idx = j;
                }
            }

            // 1. if second is 0, we done. return first (could be 0 as well)
            if (stones[scnd_idx] == 0) {
                return stones[frst_idx];
            }
            // 2. if equal, set both to 0 (cant be both 0 since second != 0)
            if (stones[frst_idx] == stones[scnd_idx]) {
                stones[frst_idx] = 0;
                stones[scnd_idx] = 0;
            }
            // 3. otherwise: set first to 0 and second to the diff
            else {
                int diff = stones[frst_idx] - stones[scnd_idx];
                stones[scnd_idx] = diff;
                stones[frst_idx] = 0;
            }
        }
        
        return -1;
    }
};