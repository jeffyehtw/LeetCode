class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        ret = []
        words = []

        words += s1.split(' ')
        words += s2.split(' ')

        m = {}
        for word in words:
            if word not in m.keys():
                m[word] = 0
            m[word] = m[word] + 1

        for key in m.keys():
            if m[key] == 1:
                ret.append(key)

        return ret
        
