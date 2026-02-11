from heapq import heappush, heappop

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        heap = []
        # build min heap
        for num in nums:
            heappush(heap, -num)

        res = 0
        # get the kth element
        for _ in range(k):
            res = heappop(heap)

        return - res