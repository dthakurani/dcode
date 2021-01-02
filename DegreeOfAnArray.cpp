class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int arr1[50000]={0};
        for(int i=0;i<nums.size();i++)
            arr1[nums[i]]+=1;
        int degree=INT_MIN;
        for(int i=0;i<50000;i++)
            if(arr1[i]>degree)
                degree=arr1[i];

        if(degree < 2) return degree;
        int arr[50000]={0};
        int i,j;
        i=j=0;
        bool digAchived = false;
        int res=INT_MAX;
        arr[nums[0]]+=1;
        while(j < nums.size()) {
           
            if(digAchived == false) {
                j++;
                if(j < nums.size()) {
                    arr[nums[j]]++;
                    if(arr[nums[j]] == degree) {
                        digAchived = true;
                      
                        res = min(res, j-i+1);
                    }
                }
            } else {
               
                if(arr[nums[i]] != degree) {
                 
                    res = min(res, j-i);
                } else {
                    digAchived = false;
                }
                arr[nums[i]]--;
                i++;
            }
        }
            
        return res;
      
    }
};