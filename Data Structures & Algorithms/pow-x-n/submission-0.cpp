class Solution {
public:
    double myPow(double x, int n) {
        
        if (n < 0) x = 1 / x;

        function<double(double, int)> go = [&](double x, int n) {
            if (n == 0) return 1.0;
            if (n == 1) return x;
            double res = go(x, n / 2);
            if (n & 1) return res * res * x;
            return res * res;
        };

        return go(x, n);
    }
};
