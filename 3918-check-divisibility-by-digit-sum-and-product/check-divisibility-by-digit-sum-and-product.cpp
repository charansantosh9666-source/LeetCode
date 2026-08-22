class Solution {
public:
    bool checkDivisibility(int n) {
        int a=0,b=1;
        int temp=n;
        while(temp>0){
            a+=temp%10;
            b*=temp%10;
            temp=temp/10;
        }
        int sum=a+b;
        if(n%sum==0){
            return 1;
        }
        else{
            return 0;
        }
        return -1;
    }
};