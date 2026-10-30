class Solution {
public:



    int f(int i,int n,vector<int>& dp, vector<int>& cost){

        if(i>n){
            return 1e9;
        }
        if(i==n){
            return 0;           
        }

        if(dp[i]!=-1) return dp[i];

        int f1=cost[i]+f(i+1,n,dp,cost);
        int f2=cost[i]+f(i+2,n,dp,cost);
        return dp[i]=min(f1,f2);
    }
    int minCostClimbingStairs(vector<int>& cost) {

       
        int n;
        n=cost.size();
        int ans=1e9;

        vector<int> dp(n+1,-1);
        ans=min(ans,f(0,n,dp,cost));
        ans=min(ans,f(1,n,dp,cost));

        return ans;


    
        
    }
};
