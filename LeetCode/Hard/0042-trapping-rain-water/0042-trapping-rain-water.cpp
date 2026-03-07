/*
Motivation: For each height We'll calculate the minimum hight of the maximum height 
    from the left and the right. This will give us the maximum water can be traped in 
    the current position, then we'll substract the current height to get the actual value.
    The sum of all diffrences is the traped rain.
Complexity: 
    Time - O(n): Looping over the array three times.
    Space - O(n): Storing bounds for each hieght
*/
class Solution {
public:
    int trap(vector<int>& height) {
        std::size_t n = height.size();

        // the minimum value between the max of left and right bounds
        std::vector<int> min_bound(n, 0);

        // Calculate maximum left bound for each height
        int max_left = 0;
        for (int i = 0; i < n; ++i) {
            min_bound[i] = max_left;
            max_left = std::max(max_left, height[i]);
        }

        // Calculate maximum right bound for each height 
        // and sum the results on the fly
        int result = 0;
        int max_right = 0;
        for (int i = n - 1; i >= 0; --i) {
            min_bound[i] = std::min(max_right, min_bound[i]);
            max_right = std::max(max_right, height[i]);
            
            // sum the result on the fly
            int curr_water = min_bound[i] - height[i];
            result += std::max(0, curr_water);
        }
        
        return result;
    }
};
        