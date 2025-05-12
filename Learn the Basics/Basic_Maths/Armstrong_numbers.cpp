class Solution {
    public:
        bool isArmstrong(int n) {
            int count=0;
            vector<int> arr;
            int m=n;
            while(m>0)
            {
                arr.push_back(m%10);
                count++;
                m/=10;
            }
            m=0;
            for(int i = 0;i<arr.size();i++)
            {
                m+=pow(arr[i],count);
            }
            if(n==m) return true;
            else return false; 
        }
    };