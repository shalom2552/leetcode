/*
Motivation: Difference array (Sweep Line).
      Make an array for all the years in the range.
      Loop over the logs and add 1 to the birth year and subtract 1 from the death year.
      Loop over the years array and keep a running sum to get the population for each year.
      Save the year that gave us the maximum population.
Complexity: 
    Time - O(n): Looping over the logs once and then over the fixed size array.
    Space - O(1): The array size is fixed to 101 years.
*/

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        constexpr int MIN_YEAR = 1950;
        constexpr int MAX_YEAR = 2050;
        constexpr int RANGE = MAX_YEAR - MIN_YEAR + 1;

        // tracks how many alive in a year by index
        vector<int> alive(RANGE, 0);

        // build the difference array
        for (auto const& log : logs) {
            int born = log[0] - MIN_YEAR;
            int die = log[1] - MIN_YEAR;

            alive[born] += 1;
            alive[die] -= 1;
        }

        int count = 0;
        int most_count = count;
        int most_year = 0;

        // loop over the range and find max count
        for (int i = 0; i < alive.size(); ++i) {
            count += alive[i];
            
            // update most populated year
            if (count > most_count) {
                most_count = max(most_count, count);
                most_year = i;
            }
        }
        
        return most_year + MIN_YEAR;
    }
};
