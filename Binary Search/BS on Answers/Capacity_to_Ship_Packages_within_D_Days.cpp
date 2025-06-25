class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end()) , r = 0;
        for(int i : weights) r+=i;
        while(l<=r){
            int mid = (l+r)/2;
            int day=0 ,sum = 0;
            for(int i = 0 ; i < weights.size() ; i++) {
                if(sum+weights[i]>mid) {
                    day++;
                    sum=0;
                }
                sum+=weights[i];
            }
            if(sum>0)day++;
            if(day<=days)r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};