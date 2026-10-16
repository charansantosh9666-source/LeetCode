class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        
        int last[100001] = {0};
        int bit_cnt[100001] = {0};
        long long bit_sum[100001] = {0};
        
        long long ans = 0;
        long long cur_sq = 0;
        long long cur_sum = 0;
        long long c1 = 0;
        
        for (int j = 1; j <= n; ++j) {
            int x = nums[j - 1];
            int p = last[x];
            last[x] = j;
            
            if (p == 0) {
                cur_sq = (cur_sq + 2 * cur_sum + j) % MOD;
                cur_sum += j;
                c1++;
            } else {
                long long cnt = 0, sum_m = 0;
                for (int idx = p - 1; idx > 0; idx -= idx & -idx) {
                    cnt += bit_cnt[idx];
                    sum_m += bit_sum[idx];
                }
                
                long long prefix_D = p * c1 - 1LL * p * (p - 1) / 2 + p * cnt - sum_m;
                long long sub_sum = cur_sum - prefix_D;
                
                int len = j - p;
                cur_sq = (cur_sq + 2 * sub_sum + len) % MOD;
                cur_sum += len;
                
                for (int idx = p; idx <= n; idx += idx & -idx) {
                    bit_cnt[idx] += 1;
                    bit_sum[idx] += p;
                }
            }
            
            ans = (ans + cur_sq) % MOD;
        }
        
        return ans;
    }
};