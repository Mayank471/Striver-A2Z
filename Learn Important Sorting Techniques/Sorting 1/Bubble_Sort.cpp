class Solution {
    public:
      // Function to sort the array using bubble sort algorithm.
      void bubbleSort(vector<int>& arr) {
          // Your code here
          for( int i = 0 ; i < arr.size() ; i++ )
          {
              for(int j = i+1 ; j<arr.size() ; j++)
              {
                  if(arr[j] < arr[i]) swap(arr[j],arr[i]);
              }
          }
      }
  };