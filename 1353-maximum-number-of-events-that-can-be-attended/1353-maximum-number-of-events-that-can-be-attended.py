# Motivation: Greedy select. 
#     Sort all events by the starting day, attend them by order on the 
#     first ending event today. Hold a min heap of evenets to attend, 
#     for every day add all the events that start today, and remove all the 
#     events that have finished and attend the first first event to end.
# Complexity: 
#     Time - O(nlogn): Sorting and Looping over the events.
#     Space - O(n): Saving the taken days in a set
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        
        # Sort the events by the starting day
        events.sort()

        # min heap for end days
        heap = []


        # last day to check up to
        n = len(events)
        last_day = max(events[i][1] for i in range(n))

        i = 0       # number of checked evenets
        count = 0   # number of attended events

        # calculate possible eventes to attende
        for day in range(1, last_day + 1):

            # add to the heap all end days of evenets that starts today
            while i < n and events[i][0] == day:
                heapq.heappush(heap, events[i][1])
                i += 1

            # remove expired events
            while heap and heap[0] < day:
                heapq.heappop(heap)
            
            # attend today the availabe event the ends first
            if heap:
                heapq.heappop(heap)
                count += 1

            # no more evenets to check
            if i == n and not heap:
                break

        # final count of attended evenets
        return count
