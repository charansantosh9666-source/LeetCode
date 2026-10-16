class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,n=nums.size(),ans;
        for(int i=0;i<n;i++){
            if (count==0){
                ans=nums[i];
            }
            if(ans==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }
        count=0;
        for(int i=0;i<n;i++){
            if (ans==nums[i]){
                count++;
            }
        }
        if (count>=(n/2)){
            return ans;
        }else {
            return -1;
        }
    }
};