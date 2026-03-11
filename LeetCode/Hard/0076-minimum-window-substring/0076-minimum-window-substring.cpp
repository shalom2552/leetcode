/*
Motivation: Sliding window.
      Use two pointers, left and right, to make a window in the string s.
      Move the right pointer to add letters until our window has all the letters we need from t.
      Then move the left pointer to shrink the window and make it as small as possible.
      Keep tracking the minimum window length and its start position.
Complexity: 
    Time - O(n + m): Moving the left and right pointers over s and looping over t once.
    Space - O(1): Hash maps to store the character counts (limited to the character set size).
*/

class Solution {
public:
    string minWindow(string s, string t) {

        // count of actual and required letters in window
        int required = t.size();
        int actual = 0;

        // build the map of letter counts in t
        unordered_map<char, int> t_count;
        for (char c : t) {
            ++t_count[c];
        }

        // count of letters in the current window from t
        unordered_map<char, int> count;

        // indecis of window
        size_t left = 0;
        size_t min_left = left;
        size_t min_len = INT_MAX;

        // search the rest of the string for min valid substring
        for (size_t right = 0; right < s.length(); ++right) {
            
            // add curr letter
            char curr = s[right];

            // increase count of actual if curr is in t and we need more of it
            if (t_count.count(curr) && count[curr] < t_count[curr]) {
                ++actual;
            }
            ++count[curr];

            // remove letters from left until the string is invalid
            while (left <= right && actual == required) {

                // update min indecis
                if (min_len > right - left + 1) {
                    min_left = left;
                    min_len = right - left + 1;
                }
                
                // remove last letter
                char last = s[left];

                // reduce count if last in t
                if (t_count.count(last) && count[last] == t_count[last]) {
                    --actual;
                }

                --count[last];
                ++left;
            }
        }

        // the min window in s
        string min_substring = s.substr(min_left, min_len);
        return min_len == INT_MAX ? "" : min_substring;
    }
};
