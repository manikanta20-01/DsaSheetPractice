class Solution:
    def generateIp(self, s):
        # Code here
        sn = len(s)
        if sn < 3:
            return []
        if sn > 3 * 4:
            return []

        # :: 4<=sn<=12
        ans = []
        def rec(s, left, right, path):
            if right - left + 1 < 1:
                if len(path) == 4:
                    ans.append(".".join(path))
                return

            if len(path) >= 4:
                return

            # sub s len >=1
            # assert right-left+1>=1
            # 1, 2, 3 number
            for i in range(min(3,right-left+1)):
                cur = s[left:left+i+1] # cur len i+1

                if cur[0] == '0':
                    if len(cur) != 1:
                        continue
                if int(cur) > 255:
                    continue

                path.append(cur)
                rec(s, left+i+1, right, path)
                path.pop()

        path = []
        rec(s, 0, sn-1, path)
        return ans