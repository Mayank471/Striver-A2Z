class Solution {
  public:
    // Function to count inversions in the array.
    long long merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int p = 0; p < temp.size(); p++) {
        arr[left + p] = temp[p];
    }

    return count;
}

    
    long long mergeSort( vector<int>& arr , int left , int right) {
        long long count = 0;
        if( left < right) {
        int mid = left + (right-left)/2;
        count+=mergeSort(arr, left , mid);
        count+=mergeSort(arr , mid +1 , right);
        count+=merge(arr , left , mid ,right);
        }
        return count;
    }
    
    int inversionCount(vector<int> &arr) {
        // Your Code Here
       return mergeSort( arr, 0 , arr.size()-1);
    }
};