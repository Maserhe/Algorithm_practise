class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int ans = 0;
        int start = -1;
        int n = s.size();
        int bucket[256];
        memset(bucket, -1, sizeof(bucket));

        for (int i = 0; i < n; i ++ ) {
            // 注意 这里 是 大于。
            if (bucket[s[i]] > start) start = bucket[s[i]];
            bucket[s[i]] = i;
            ans = max(ans, i - start);            
        }
        return ans;
    }
};