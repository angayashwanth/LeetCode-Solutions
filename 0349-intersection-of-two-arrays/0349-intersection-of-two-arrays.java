class Solution {
    public int[] intersection(int[] nums1, int[] nums2) 
    {
        HashSet<Integer>l=new HashSet<>();
        for(int p:nums1)
        l.add(p);
        ArrayList<Integer>r=new ArrayList<>();
        for(int p:nums2)
        {
            if(l.contains(p))
            r.add(p);
            l.remove(p);
        }
        int res[]=new int[r.size()];
        for(int i=0;i<r.size();i=i+1)
        res[i]=r.get(i);
        return res;    
    }
}