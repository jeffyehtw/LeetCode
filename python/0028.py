class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(haystack) < len(needle):
            return -1
        elif len(haystack) == len(needle):
            return 0 if (haystack == needle) else -1 
        else:
            for i in range(0, len(haystack) - len(needle) + 1):
                if haystack[i:i + len(needle)] == needle:
                    return i
        return -1
