class Solution:
    def areIsomorphic(self, s1, s2):
        # code here 
        len_s1, len_s2 = len(s1), len(s2)
        if len_s1 != len_s2:
            return False
       
        char_mapping = {}
        mapped_chars_s2 = set()
       
        for i in range(len_s1):
            char_s1, char_s2 = s1[i], s2[i]
           
            if char_s1 in char_mapping:
                if char_mapping[char_s1] != char_s2:
                    return False
            else:
                if char_s2 in mapped_chars_s2:
                    return False
               
                char_mapping[char_s1] = char_s2
                mapped_chars_s2.add(char_s2)
       
        return True