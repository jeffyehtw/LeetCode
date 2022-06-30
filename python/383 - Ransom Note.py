class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        ransomNote = [str(i) for i in ransomNote]
        magazine = [str(i) for i in magazine]
        
        set_ransomNote = list(set(ransomNote))
        
        for i in set_ransomNote:
            a = ransomNote.count(i)
            b = magazine.count(i)
            
            if a > b:
                return False
                
        return True