class Solution {
public:



    int f(int i, int n,vector<int>& nums, vector<int>& dp){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1) return dp[i];
        int f1=f(i+1,n,nums,dp);
        int f2=nums[i]+f(i+2,n,nums,dp);

        return dp[i]=max(f1,f2);
    }



    int rob(vector<int>& nums) {

        int n;
        n=nums.size();
        vector<int> dp(n+1,-1);

        return f(0,n,nums,dp);


        
    }
};
