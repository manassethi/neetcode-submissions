class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(auto& p:nums){
          mpp[p]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto& x:mpp){
            pq.push({x.second,x.first});
        }
         vector<int> ans;
        for(int i=0;i<k;i++){   
            ans.push_back(pq.top().second);
            pq.pop();

        }

        return ans;

 
    }
};
