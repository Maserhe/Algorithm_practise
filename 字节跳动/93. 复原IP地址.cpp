class Solution {
public:

    vector<string> ans;
    string temp;

    void search(string& s, int index, int count) {
        if (count == 4) {
            if (index == s.size()) ans.push_back(temp);
            return;
        }
        // 每个 段 可能是 1,2,3
        if (index < s.size()) {
            string t = temp;

            // 1, 
            temp += s[index];
            if (count < 3) temp += '.';
            search(s, index + 1, count + 1);
            temp = t;
            // 2. 
            if (index + 1 < s.size() && judge(index, index + 1, s)) {
                temp += s[index];
                temp += s[index + 1];
                if (count < 3) temp += '.';
                search (s, index + 2, count + 1);
                temp = t;
            }
            // 3.
            if (index + 2 < s.size() && judge(index, index + 2, s)) {
                temp += s[index];
                temp += s[index + 1];
                temp += s[index + 2];
                if (count < 3) temp += '.';
                search(s, index + 3, count + 1);
            }

        }

    }
    
    vector<string> restoreIpAddresses(string s) {

        if (s.size() > 12) return {};
        search(s, 0, 0);
        return ans;
    }

    // 判断是否可以 为 ip中的一个数。
    bool judge(int l, int r, string& s) {
        if (s[l] == '0') return false;
        if (r - l == 2 && s[l] - '0' >= 3) return false;

        int num = 0;
        while (l <= r) {
            num *= 10;
            num += (s[l] - '0');
            l ++ ;
        }
        
        if (num >= 0 &&  num <= 255) return true;
        return false;
    }
};