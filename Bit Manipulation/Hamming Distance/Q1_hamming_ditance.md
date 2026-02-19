# 1. Hamming Distance 
class Solution {
    public int hammingDistance(int x, int y) 
    {
        int count=0;
        int temp=x^y;
        while(temp>0)
        {
            temp=temp&(temp-1);
            count++;
        }
        return count;
    }
}
