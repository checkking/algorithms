# coding=utf-8


class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or s is None or len(s) == 1:
            return s
        numRows = min(len(s), numRows)
        currentRow = 0
        rows = ["" for _ in range(numRows)]
        godown = True
        print rows
        for c in s:
            rows[currentRow] += str(c)
            if godown:
                currentRow += 1
                if currentRow == numRows - 1:
                    godown = False
            else:
                currentRow -= 1
                if currentRow == 0:
                    godown = True
        return "".join(rows)

if __name__ == '__main__':
    s = Solution()
    print s.convert("abcde", 3)
