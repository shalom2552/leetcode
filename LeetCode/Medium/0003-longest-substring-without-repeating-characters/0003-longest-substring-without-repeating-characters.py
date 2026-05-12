class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest = 0
        counter: dict[str, int] = defaultdict(int)
        
        left = 0
        for right in range(len(s)):
            counter[s[right]] += 1
            while counter[s[right]] > 1:
                counter[s[left]] -= 1
                left += 1
            longest = max(longest, right - left + 1)
        return longest 