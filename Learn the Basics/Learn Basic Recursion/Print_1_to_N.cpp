class Solution {
    public:
      // Complete this function
      void printNos(int n) {
          // Your code here
          if(n==1) 
          {
              cout<<1<<" ";
              return;
          }
          else {
          printNos(n-1);
          cout<<n<<" ";
          }
      }
  };
  