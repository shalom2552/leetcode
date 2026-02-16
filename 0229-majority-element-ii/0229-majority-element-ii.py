# Motivation: We'll use the Boyer-Moore Voting Algorithm, with modified counts.
#     The only three options we can have is 0, 1, 2 numbers as such (3 or more can't be).
#     Using two candidates and two counters for the case where we have 2 numbers as such.
# Complexity: 
#     Time - O(n): Looping over the array twice.
#     Space - O(1): Auxiliary
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:

        # set default candidates to be diffrent but valid
        candidate_a = 0
        candidate_b = 1
        result = []

        # counts to hold each candidate appearances
        count_a = 0
        count_b = 0

        # loop over the array to find candidates
        for num in nums:
            
            # update count for candidate_a 
            if num == candidate_a:
                count_a += 1

            # update count for candidate_b
            elif num == candidate_b:
                count_b += 1

            # check for a new candidate
            else:
                
                # find new candidate_a if its not valid
                if count_a == 0:
                    candidate_a = num
                    count_a = 1
                
                # find new candidate_b if its not valid
                elif count_b == 0:
                    candidate_b = num
                    count_b = 1

                # no match for both candidates
                else:
                    count_a -= 1
                    count_b -= 1

        
        # candidates must be > n/3
        treshold = len(nums) // 3
        if nums.count(candidate_a) > treshold:
            result.append(candidate_a)
        if nums.count(candidate_b) > treshold:
            result.append(candidate_b)

        return result


# Motivation: Naive approach, using hash map to store all elements count.
#       Return all elements that appears mor than n/3 times. 
# Complexity: 
#     Time - O(n): Loop over the array once.
#     Space - O(n): Hash map for all elementcs, n in the worst case.
class SolutionHash:
    def majorityElement(self, nums: List[int]) -> List[int]:

        # hash map to store counts
        counts = {}

        # list to store the results
        result = []
        
        # count how many times each number appears
        for num in nums:
            if num not in counts:
                counts[num] = 1
            else:
                counts[num] += 1
        
        # add all elements that apears more than n/3 to the result
        for num, count in counts.items():
            if count > len(nums) // 3:
                result.append(num)

        # may be empty
        return result