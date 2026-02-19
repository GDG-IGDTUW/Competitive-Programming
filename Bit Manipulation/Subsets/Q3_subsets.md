# 3. Subsets

class Solution {
    public List<List<Integer>> subsets(int[] nums) 
    {
        List<List<Integer>> result=new ArrayList<>();
        int n=nums.length;
        for(int i=0;i<(1<<n);i++) 
        {
            List<Integer> subset=new ArrayList<>();
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j))!=0) subset.add(nums[j]);
            }
            result.add(subset);
        }  
        return result;
    }
}
