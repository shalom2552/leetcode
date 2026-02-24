class Solution:
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