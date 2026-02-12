# Motivation: BF approach. 
#     Use hashmap to store each element occurrences count,
#     then loop over the map k times to find the the most element for each k.
#     When finding an element set its count to -1 so we dont add it again.
# Complexity: 
#     Time - O(n*k): loop over the list once and then k more times.
#     Space - O(n): hashmap of elements.
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        # hashmap to store elements occurrences
        hist = {}
        result = []

        # loop over nums and count each element occurrences
        for num in nums:
            if num not in hist:
                hist[num] = 0
            else:
                hist[num] += 1
        
        # loop over k times to find each kth most element
        for i in range(k):
            # find the next ith most element
            most_num = nums[0]
            most_val = hist[most_num]

            # find current most elem in the hist
            for num in nums:
                if hist[num] > most_val:
                    most_val = hist[num]
                    most_num = num
            
            # save current max to result and reset its count
            result.append(most_num)
            # set count to -1 so we dont count it again
            hist[most_num] = -1

        return result
