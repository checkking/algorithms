# coding=utf-8

### 动态规划方法解决最大回文子串

class Solution(object):

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if (not s or len(s) == 1):
            return s
        n = len(s)
        i, j = 0, 0
        ans = 0
        dp=[[False]*n for _ in range(n)]
        start = 0
        # init
        for i in range(n):
            dp[i][i] = True
            tmpAns = 1
            if tmpAns > ans:
                ans = tmpAns
                start = i
            if i < n - 1 and s[i] == s[i + 1]:
                dp[i][i + 1] = True
                tmpAns = 2
                if tmpAns > ans:
                    ans = tmpAns
                    start = i
        for l in range(3, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    start = i
                    ans = l
        return s[start:start+ans]

if __name__ == '__main__':
    s = Solution()
    print(s.longestPalindrome("abbd"))
