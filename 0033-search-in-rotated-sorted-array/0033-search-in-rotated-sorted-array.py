class Solution:
    def search(self, l: List[int], target: int) -> int:
        low = 0
        high = len(l)-1

        while(low <= high):
            mid = (low+high)//2

            if(l[mid] == target):
                return mid

            if(l[low] <= l[mid]):
                if(l[low] <= target < l[mid]):
                    high = mid-1
                else:
                    low = mid+1

            else:
                if(l[mid] < target <= l[high]):
                    low = mid+1
                else:
                    high = mid-1

        return -1