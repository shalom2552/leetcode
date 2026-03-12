/*
Motivation: Difference array.
      Make an array for all the flights. Then loop over the bookings and add
      seats to the start flight and remove them from the flight right after
      the end. Then loop over the flights array again and accumulate the sum
      to get the total seats for each flight. Return the updated array.
Complexity: 
    Time - O(n + m): Looping over the m bookings once and then over the n flights.
    Space - O(n): The array size is n to save the results.
*/

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        
        // tracks how many reserved seats changes in a flight by index
        vector<int> reserved(n, 0);

        // build the difference array
        for (auto const& book : bookings) {
            
            // -1 since we index from 0
            size_t start = book[0] - 1;
            size_t end = book[1];
            int seats = book[2];

            // add or remove seats on each fligt
            reserved[start] += seats;
            // we index from 0 and end is i+1
            if (end < n) {
                reserved[end] -= seats;
            }
        }

        // accumulate the differences
        for (size_t i = 1; i < reserved.size(); ++i) {
            reserved[i] += reserved[i - 1];
        }
        
        // count of reserved seats for each flight
        return reserved;
    }
};
