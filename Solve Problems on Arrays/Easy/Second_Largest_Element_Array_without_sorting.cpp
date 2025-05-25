class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        
        int max = -1;
        int secondMax = -1;
        if(max<secondMax)swap(max,secondMax);
        for(int i = 0; i < arr.size(); i ++)
        {
            if(arr[i]>secondMax && arr[i]!=max) {
                if(arr[i]>max) {
                    secondMax = max;
                    max = arr[i];
                }
                else {
                    secondMax = arr[i];
                }
            }
        }
        return secondMax;
    }
};