/*
Motivation: Binary Search on the solution space.
    The median is the max value in n / 2 smallest elementens.
    In each iteration split A and B suche that,
    the numbers of elements in the left side of A plus the right side of
    B are equal to the numbers of elements in the right side of A
    plus the left side of B:
      1. len(A_left) + len(B_right) = len(A_right) + len(B_left)
      2. max(A_left, B_left) < min(B_right, B_right)
    then recursively run this until conditions are satisfied
    The median is min(A_right, B_right)
Complexity:
    Time - O(logn): Binary Search.
    Space - O(1): Auxiliary.
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // solve assuming nums1 is the smaller array
        const vector<int>* a = &nums1;
        const vector<int>* b = &nums2;
        if (nums1.size() > nums2.size()) {
            std::swap(a, b);
        }
        
        // Define lengths for easy access and reduce calulations
        std::size_t len_a = a->size();
        std::size_t len_b = b->size();
        std::size_t N = len_a + len_b;

        // initial search space
        std::size_t low = 0;
        std::size_t high = len_a;

        // binary search for median
        while (low <= high) {

            // mid values such that lengths are equal
            std::size_t mid_a = low + (high - low) / 2;
            std::size_t mid_b = ((N + 1) / 2) - mid_a;

            // fix out of bounds using inf values
            double left_a = (mid_a > 0) ? (*a)[mid_a - 1] : INT_MIN;
            double right_a = (mid_a < len_a) ? (*a)[mid_a] : INT_MAX;
            double left_b = (mid_b > 0) ? (*b)[mid_b - 1] : INT_MIN;
            double right_b = (mid_b < len_b) ? (*b)[mid_b] : INT_MAX;

            // if both halfs are sorted found the median
            if (left_a <= right_b && left_b <= right_a) {
                // calculate the median based on if its odd or even
                if (N % 2) {
                    return std::max(left_a, left_b);
                }
                else {
                    return (std::max(left_a, left_b) + std::min(right_a, right_b)) / 2;
                }
            }
            // median is too big
            else if (right_a < left_b) {
                low = mid_a + 1;
            }
            // median is too small
            else {
                high = mid_a - 1;
            }
        }
            
        // default return value (never reaches)
        return 0.0;
    }
};
