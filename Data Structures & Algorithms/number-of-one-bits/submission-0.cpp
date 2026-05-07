class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        bitset<32> b(n);
        for(int i = 0; i <= b.size(); i++) {
            ans += (b[i]);
        }
        return ans;

    }
};
