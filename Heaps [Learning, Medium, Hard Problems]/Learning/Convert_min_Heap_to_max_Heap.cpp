// User function Template for C++

class Solution {
  public:
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        for(int i = N/2-1; i>=0; i--) {
            maxHeapify(arr, i, N);
        }
    }
    void maxHeapify( vector<int>& arr, int i, int N) {
        int largest = i;
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;
        if(leftChild<N && arr[i]<arr[leftChild]) {
            largest = leftChild;
        }
        if(rightChild<N && arr[largest] < arr[rightChild]) largest = rightChild;
        
        if(i!=largest) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, largest, N);
        }
    }
};
