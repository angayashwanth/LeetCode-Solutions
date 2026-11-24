class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        st=[]
        for ch in s:
            if(st and st[-1][0]==ch):
                st[-1][1]=st[-1][1]+1
            else:
                st.append([ch,1])
            if(st[-1][1]==k):
                st.pop()
        r=''
        for ch,c in st:
            r=r+ch*c
        return r