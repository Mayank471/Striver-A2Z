class Solution {
    public:
      // Please change the array in-place
      void insertionSort(vector<int>& arr) {
          // code here
          for(int i = 0 ; i <= arr.size()-1 ; i++)
          {
              int j = i;
              while( j > 0 && arr[j-1] > arr[ j ])
              {
                  swap ( arr[j-1] , arr[j]);
                  j--;
              }
          }
      }
  };