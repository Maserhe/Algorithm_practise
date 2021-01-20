class Solution {
public:
    
    int getStr(int l, int r, string& s) {
        
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l -- ;
            r ++ ;
        }
        return  r - l  - 1;
    }
    string longestPalindrome(string s) {
        
        int max = 0, start = 0;

        for (int i = 0; i < s.size(); i ++ ) {
            int curMax = std::max(getStr(i, i, s), getStr(i, i + 1, s));
            if (curMax > max) {
                max = curMax;
                start = i - ((curMax - 1) / 2);
            }
        }
        string ans;
        for (int i = 0; i < max; i ++ ) ans += s[start + i];
        return ans;
    }
    
};