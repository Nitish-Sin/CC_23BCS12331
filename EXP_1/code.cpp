class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int res=0,n=nums.size(),i=0,j=n-1 ,ctr=0;
        if(n==1) return nums[0];
        while(i<j){
            if(i>0)res+= nums[i]*(n-1)*ctr;
            else res+=nums[i];
            if(j<n-1) res+= nums[j]*(n-1)*ctr;
            else res+= nums[j];
            res%=10;
            ctr++;
            i++;
            j--;
        }
        if(n&1  && n>1){
            res+= nums[i]*(n-2)*((int)(n/2));
            res%=10;
        }
        return res;
    }
};
