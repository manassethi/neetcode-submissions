class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        map<int, int> mpp;
        int n = hand.size();
        for (int i = 0; i < n; i++) {
            mpp[hand[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (mpp[hand[i]] > 0) {
                for(int j=0;j<groupSize;j++){
                    if(mpp[hand[i]+j]>0){
                        mpp[hand[i]+j]--;
                    }
                    else{
                        return false;
                    }
                }

            }
        }
             
        return true;
    }
};
