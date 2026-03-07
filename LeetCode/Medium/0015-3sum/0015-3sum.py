# Motivation: 2 for loops and a binary search on the third value.
# Complexity: 
#       Time - O(n^2*logn): sorting and nested binary search in nested for loops.
#       Space - O(1): Auxiliary.
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        # sort the array
        nums.sort()
        results = []
        
        for i in range(len(nums)):

            # skip duplicates
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            # for each element after i
            for j in range(i + 1, len(nums) - 1):

                # skip duplicates
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                left = j + 1
                right = len(nums) - 1
                
                # binary search on third number
                while (left <= right):

                    mid = left + (right - left) // 2
                    total = nums[i] + nums[j] + nums[mid]

                    # update the search spcae or break if found
                    if total == 0:
                        results.append([nums[i], nums[j], nums[mid]])
                        break
                    elif (total < 0):
                        left = mid + 1
                    else:
                        right = mid - 1
        
        return results


# Two pointers solution
class SolutionPointers:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        # sort the array
        nums.sort()
        results = []
        
        for i in range(len(nums)):
            
            # search space
            j = i + 1
            k = len(nums) - 1

            # skip duplicate consecutive numbers
            if i > 0 and nums[i] == nums[i-1]:
                continue

            # binary search
            while(j < k):

                total = nums[i] + nums[j] + nums[k]

                if total == 0:
                    results.append([nums[i], nums[j], nums[k]])
                    
                    # keep searching with diffrent values 
                    j += 1
                    k -= 1

                    # find the next diffrent values from both ends
                    while nums[j] == nums[j-1] and j < k:
                        j += 1
                    while nums[k] == nums[k+1] and j < k:
                        k -= 1

                # increase from left
                elif total < 0:
                    j += 1
                # decrease from right
                else:
                    k -= 1
            
        return results