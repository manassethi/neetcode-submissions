class Solution {
public:
    int f(int i, bool flag, vector<int>& nums, vector<int>& dp){
        if(i>=nums.size() || (flag && i>=nums.size()-1)){
            return 0;
        }

        if(dp[i]!=-1) return dp[i];

        int f1=nums[i]+f(i+2,flag,nums,dp);
        int f2=f(i+1,flag,nums,dp);

        return dp[i]=max(f1,f2);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];   
        }
        int n=nums.size();
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);



        return max(f(0,true,nums,dp1),f(1,false,nums,dp2));

        

    }
};
