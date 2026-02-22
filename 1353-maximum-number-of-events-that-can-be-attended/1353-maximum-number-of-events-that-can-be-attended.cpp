/*
Motivation: Greedy select. 
    Sort all events by the starting day, attend them by order on the 
    first ending event today. Hold a min heap of evenets to attend, 
    for every day add all the events that start today, and remove all the 
    events that have finished and attend the first first event to end.
Complexity: 
    Time - O(nlogn): Sorting and Looping over the events.
    Space - O(n): Saving the taken days in a set
*/
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        // Sort the events by the starting day
        std::sort(events.begin(), events.end());

        // min heap for end days
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    
        // last day to check up to
        int last_day = events[0][1];
        for (std::size_t i = 0; i < events.size(); ++i) {
            last_day = std::max(last_day, events[i][1]);
        }

        int i = 0;       // number of checked evenets
        int count = 0;   // number of attended events

        // calculate possible eventes to attende
        for (int day = 1; day < last_day + 1; ++day) {

            // add to the heap all end days of evenets that starts today
            while (i < events.size() and events[i][0] == day) {
                heap.push(events[i][1]);
                i += 1;
            }

            // remove expired events
            while ( !heap.empty() && heap.top() < day) {
                heap.pop();
            }
            
            // attend today the availabe event the ends first
            if ( !heap.empty() ) {
                heap.pop();
                count += 1;
            }

            // no more evenets to check
            if (i == events.size() && heap.empty()) {
                break;
            }
        }

        // final count of attended evenets
        return count;
    }
};
