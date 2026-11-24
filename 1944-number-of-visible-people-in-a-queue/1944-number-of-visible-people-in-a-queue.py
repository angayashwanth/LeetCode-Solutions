class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        n = len(heights)
        r = [0] * n
        st = []
        for p in range(n-1, -1, -1):
            while st and heights[st[-1]] < heights[p]:
                st.pop()
                r[p] += 1
            if st:
                r[p] += 1
            st.append(p)
        return r