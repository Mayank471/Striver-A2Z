class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        // Your code goes here
        int sum = arr[0]+arr[1];
        for(int i = 1 ; i <arr.size()-1;i++) {
            if(arr[i]+arr[i+1]>sum) sum = arr[i]+arr[i+1];
        }
        return sum;
    }
};
