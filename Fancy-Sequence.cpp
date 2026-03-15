1class Fancy {
2private:
3    static constexpr int mod = 1000000007;
4    vector<int> v, a, b;
5
6public:
7    Fancy() {
8        a.push_back(1);
9        b.push_back(0);
10    }
11
12    // fast exponentiation
13    int quickmul(int x, int y) {
14        int ret = 1;
15        int cur = x;
16        while (y) {
17            if (y & 1) {
18                ret = (long long)ret * cur % mod;
19            }
20            cur = (long long)cur * cur % mod;
21            y >>= 1;
22        }
23        return ret;
24    }
25
26    // multiplicative inverse
27    int inv(int x) { return quickmul(x, mod - 2); }
28
29    void append(int val) {
30        v.push_back(val);
31        a.push_back(a.back());
32        b.push_back(b.back());
33    }
34
35    void addAll(int inc) { b.back() = (b.back() + inc) % mod; }
36
37    void multAll(int m) {
38        a.back() = (long long)a.back() * m % mod;
39        b.back() = (long long)b.back() * m % mod;
40    }
41
42    int getIndex(int idx) {
43        if (idx >= v.size()) {
44            return -1;
45        }
46        int ao = (long long)inv(a[idx]) * a.back() % mod;
47        int bo = (b.back() - (long long)b[idx] * ao % mod + mod) % mod;
48        int ans = ((long long)ao * v[idx] % mod + bo) % mod;
49        return ans;
50    }
51};