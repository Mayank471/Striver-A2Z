class Solution {
    public:
      // Function to perform selection sort on the given array.
      void selectionSort(vector<int> &arr) {
          // code here
          int min = 0 , index = 0;
          int i = 0;
          for(int j = 0 ; j < arr.size()-1 ; j ++)
          {
              min = arr[j];
          for( i = j ; i < arr.size() ; i++)
          {
              if(min>=arr[i]) {
                  min = arr[i];
                  swap(arr[i],arr[j]);
              }
              
          }
          }
      }
  };