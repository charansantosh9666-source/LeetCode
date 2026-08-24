class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i,st=0,end=nums.size()-1,mid;
        while(st<=end){
            mid=st+(end-st)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return st;
    }
};