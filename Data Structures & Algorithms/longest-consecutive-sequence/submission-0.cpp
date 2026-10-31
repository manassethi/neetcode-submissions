class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0) return 0;

        sort(nums.begin(),nums.end());
        int i=0;
        int curr=1;
        int streak=1;

        while(i<nums.size()-1){


            if(nums[i]==nums[i+1]){
                i++;
                continue;
            }
            if((nums[i]+1)==nums[i+1]){
                curr+=1;
                streak=max(streak,curr);
            }
            else{
                curr=1;

            }
            i++;

        }

        return streak;

        
    }
};
