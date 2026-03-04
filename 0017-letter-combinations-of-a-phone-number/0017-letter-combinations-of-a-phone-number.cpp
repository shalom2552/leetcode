/*
Motivation: Backtracking.
    Using a mapping function to map a digit to all letter options.
    foe every digit options backtrack with all the next digit options recursively.
Complexity: 
    Time - O(3^n): Backtrack 3 times for every digit.
    Space - O(3^n): Save all possible solutions.
*/
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        // vector to hold all valid messages
        std::vector<std::string> res;
        // path of any message
        std::string path;

        // Backtrack over the digits to find all solutions 
        backtrack(digits, res, path, 0);
        return res;
    }

    /* Backtrack over the digits and find all solutions
     *
     * @param digits to loop over
     * @param res to hold all valid solutions
     * @param path to hold current soltuion
     * @param i index of current digit in digits
     */
    void backtrack(std::string& digits, std::vector<std::string>& res, std::string& path, int i)
    {
        // reached to a valid solution
        if (i == digits.length()) {
            // appeend result
            res.push_back(path);
            return;
        }

        for (char letter : map(digits[i])) {
            
            // add current letter
            path += letter;

            // recurse to next digit
            backtrack(digits, res, path, i + 1);

            // remove current letter
            path.pop_back();
        }
    }

    /* Map digit to letters in the dialler */
    std::string map(char number) {
        switch (number) {
            case '2':
                return "abc";
                break;
            case '3':
                return "def";
                break;
            case '4':
                return "ghi";
                break;
            case '5':
                return "jkl";
                break;
            case '6':
                return "mno";
            break;
            case '7':
                return "pqrs";
                break;
            case '8':
                return "tuv";
                break;
            case '9':
                return "wxyz";
                break;
        }

        // fallback return (for invalid input)
        return "";
    }

};