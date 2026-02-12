# Motivation: Hashmap and Bucket-Sort approach. 
#     Use hashmap to store each element occurrences count,
#     then loop over the bucket k times from the most to least,
#     add elements up until k and return.
# Complexity: 
#     Time - O(n): loop over the list once and over the bucket.
#     Space - O(n): hashmap and bucket.
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        # hashmap to store elements occurrences
        hist = {}
        # bucket to store the elements by occurrences by index
        bucket = [[] for _ in  range(len(nums) + 1)]
        # list to store the result
        result = []

        # loop over nums and count each element occurrences
        for num in nums:
            if num not in hist:
                # add it for the first time
                hist[num] = 1
            else:
                # increment element occurrences
                hist[num] += 1
        
        # fill the bucket with nums by their count
        for num in hist.keys():
            count = hist[num]
            # add num to the index representing its count
            bucket[count].append(num)

        # loop over the bucket in reverse to find the kth most element
        for i in range(len(bucket) -1, 0, -1):
            # extract elements from the current bucket
            for num in bucket[i]:
                result.append(num)
                # we found k elements
                if len(result) == k:
                    return result
