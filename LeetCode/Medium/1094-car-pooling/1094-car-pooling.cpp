/*
Motivation: Difference array (Sweep Line).
      Make an array for all the locations in the range.
      First loop over the trips and add passengers to the start location and
      remove them from the end location. Then loop over the locations array
      and keep a running sum to get the passenger count at each point.
      If the count exceeds the capacity at any point, return false.
Complexity: 
    Time - O(n): Looping over the trips once and then over the fixed size array.
    Space - O(1): The array size is fixed to 1001 locations.
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        constexpr int MIN_FROM = 0;
        constexpr int MAX_TO = 1000;
        constexpr int RANGE = MAX_TO - MIN_FROM + 1;

        // tracks how many passengers changes in a location by index
        vector<int> diffrence(RANGE, 0);

        // build the difference array
        for (auto const& trip : trips) {
            
            int passengers = trip[0];
            int from = trip[1] - MIN_FROM;
            int to = trip[2] - MIN_FROM;

            // add or remmove passengers on each point
            diffrence[from] += passengers;
            diffrence[to] -= passengers;
        }

        // count of passengers at the time
        int count = 0;
        int max_count = count;

        // loop over the range and find max count
        for (int i = 0; i < diffrence.size(); ++i) {
            count += diffrence[i];

            // check if current count exceeds capacity
            if (count > capacity) {
                return false;
            }
        }
        
        // no capacity exceed
        return true;
    }
};
