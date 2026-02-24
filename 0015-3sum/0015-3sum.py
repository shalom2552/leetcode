class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # Solution with 2 pointers, list to store results.
        # and updating indexes to  avoid duplicates.
        nums.sort()
        results = []
        
        for i in range(len(nums)):
            j, k = i + 1, len(nums) - 1
            if i > 0 and nums[i] == nums[i-1]:
                continue

            while(j < k):
                total = nums[i] + nums[j] + nums[k]
                if total == 0:
                    results.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while nums[j] == nums[j-1] and j < k:
                        j += 1
                    while nums[k] == nums[k+1] and j < k:
                        k -= 1
                elif total < 0:
                    j += 1
                    # while nums[j] == nums[j-1] and j < k:
                    #     j += 1
                else:
                    k -= 1
                    # while nums[k] == nums[k+1] and j < k:
                    #     k -= 1
            
        return results


# class Solution:
#     def threeSum(self, nums: List[int]) -> List[List[int]]:
#         # Solution with 2 pointers, and set to store results.
#         # store results after sorting to avoid duplicates.
#         # this solution go over all posibilities in the scope and does not skip.
#         nums.sort()
#         results = set()
        
#         for i in range(len(nums)):

#             j, k = i + 1, len(nums) - 1

#             while(j < k):
#                 if nums[i] + nums[j] + nums[k] == 0:
#                     results.add(tuple(sorted([nums[i], nums[j], nums[k]])))
#                     j += 1
#                     k -= 1
#                 elif nums[i] + nums[j] + nums[k] < 0:
#                     j += 1
#                 else:
#                     k -= 1

#         return results