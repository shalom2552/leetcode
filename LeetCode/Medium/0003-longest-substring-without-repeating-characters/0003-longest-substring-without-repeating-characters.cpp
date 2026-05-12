/*
Motivation: Sliding Window.
      Use two pointers, head and tail, to make a window in the string.
      Move the head pointer to add letters and count them in an array.
      If a letter appears more than once, shrink the window from the tail
      until all letters are unique again. Keep track of the max window size.
Complexity: 
    Time - O(n): Visiting each elementat twice.
    Space - O(1): The array is limited to sizeof(char).
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t max_len = 0;
        std::array<int, 256> counts{0};

        size_t head = 0;
        size_t tail = 0;
        while (head < s.length()) {
            char curr = s[head++];
            ++counts[curr];
            
            while (counts[curr] > 1) {
                --counts[s[tail++]];
            }
            max_len = std::max(max_len, head - tail);
        }
        
        return (int)max_len;
    }
};
