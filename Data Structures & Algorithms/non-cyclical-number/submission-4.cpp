class Solution {
public:
    bool isHappy(int n) {
        function<int(int)> go = [&](int n) {
            int res = 0;
            while(n) {
                res += pow(n % 10, 2); 
                n /= 10;
            }

            return res;
        };

        unordered_set<int> st;
        st.insert(n);
        while(true) {
            n = go(n);
            if (n == 1) return true;
            if (st.count(n)) return false;
            st.insert(n);
        }

    }
};
