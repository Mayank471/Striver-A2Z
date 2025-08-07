#include <iostream>
using namespace std;

class Solution {
  public:
    void bitManipulation(int num, int i) {
        cout << ((num >> (i - 1)) & 1) << " ";          
        cout << (num | (1 << (i - 1))) << " ";          
        cout << (num & ~(1 << (i - 1))) << " ";         
    }
};
