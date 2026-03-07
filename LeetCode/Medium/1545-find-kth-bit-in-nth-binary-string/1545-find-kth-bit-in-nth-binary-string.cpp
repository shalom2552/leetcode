/*
Motivation: Recursive construction of the binary string.
Complexity:
    Time - O(2^n): Each step doubles the size of the string, ence the processing time.
    Space - O(2^n): Storing the string.
*/

class Solution {
public:
    char findKthBit(int n, int k)
    {
        // S_1
        std::string S_n = "0";
        
        // recursively form the binary string
        recurse(S_n, n - 1);
        
        // k-1 is the k'th position
        return S_n[k - 1];
    }

    // recursively form the binary string
    void recurse(std::string& S_n, int n)
    {
        // stop after n calls
        if (n == 0) {
            return;
        }
        
        // form the n'th binary string
        S_n = S_n + "1" + reverse_invert(S_n);
        
        // recursively build the next layer
        recurse(S_n, n-1);
    }

    // Invert a string: all 1's become 0 and viseversa
    std::string reverse_invert(std::string const& str)
    {
        
        // string to hold the inverse of str
        std::string result;
        result.reserve(str.size());

        // invert and reverse the string
        for (char c : str) {
            // invert
            char inverse = (c == '1') ? '0' : '1';
            result.push_back(inverse);
        }

        // reverse the string in place
        std::reverse(result.begin(), result.end());

        return result;
    }
};