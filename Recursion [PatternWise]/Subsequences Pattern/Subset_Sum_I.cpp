class Solution {
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> res;
        int sum = 0;
        subsetSum(arr,0,sum,res);
        return res;
    }
private:
    void subsetSum(vector<int>& arr , int index ,int sum , vector<int>& res) {
        if(index==arr.size()) {
            res.push_back(sum);
            return;
        }
        subsetSum(arr,index+1,sum+arr[index],res);
        subsetSum(arr,index+1,sum,res);
    }
};