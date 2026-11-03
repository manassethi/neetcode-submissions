class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {

        int l=0;
        int n=arr.size();
        int r=n-1;
        while(l<r){
            int t=arr[l]+arr[r];
            if(t==target){
                return {l+1,r+1};
            }
            else if(t<target) l++;
            else r--;

        }
        
    }
};
