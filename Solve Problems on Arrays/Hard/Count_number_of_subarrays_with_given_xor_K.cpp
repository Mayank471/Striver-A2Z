#include<bits/stdc++.h>
using namespace std;
int solve(int* A, int n1, int B) {
    unordered_map<int, int> res;
    int count = 0, pxor = 0;
    
    for(int i = 0; i < n1; i++) {
        pxor ^= A[i];
        
        if(pxor == B)
            count++;

        if(res.find(pxor ^ B) != res.end())
            count += res[pxor ^ B];

        res[pxor]++;
    }
    
    return count;
}
 int main() {
     int A[] = {1, 2, 3, 4, 5};           
     int n1 = sizeof(A) / sizeof(A[0]);
     int B = 5;
     cout << solve(A, n1, B) << endl; // Output: 2
     return 0;
 }


