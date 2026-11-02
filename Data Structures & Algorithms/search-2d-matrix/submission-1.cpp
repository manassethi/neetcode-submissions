class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int r=m*n-1;
        while(l<=r){
            int mid=(l+r)/2;
            int row=mid/n;
            int col=mid%n;
            int curr=matrix[row][col];
            if(curr==target) return true;
            if(curr<target) l=mid+1;
            if(curr>target) r=mid-1;

        }

        return false;




    }
};
