1
2//very very very hard problem
3
4constexpr int mod = 1e9 + 7;
5// using 1D vector to denote the compressed form: a[i*m+j]=m[i][j]
6using matrix = vector<int>;
7static int m, m2;
8static inline matrix operator*(const matrix& A, const matrix& B) {
9    // all matrix size m*m
10    matrix C(m2, 0);
11    for (int i = 0; i < m; i++) {
12        for (int k = 0; k < m; k++) {
13            if (A[i * m + k] == 0)
14                continue;
15            for (int j = 0; j < m; j++) {
16                C[i * m + j] =
17                    (C[i * m + j] + 1LL * A[i * m + k] * B[k * m + j]) % mod;
18            }
19        }
20    }
21    return C;
22}
23// matrix A*B=B*A with A, B symmetric=> A*B symmetric
24static inline matrix symMul(const matrix& A, const matrix& B) {
25    matrix C(m2, 0);
26    for (int i = 0; i < m; i++) { // compute the lower triangle part
27        for (int j = 0; j <= i; j++) {
28            long long dotSum = 0;
29            for (int k = 0; k < m; k++) {
30                dotSum += 1LL * A[i*m+k] * B[j*m+k];
31                if (dotSum >= mod)
32                    dotSum %= mod;
33            }
34            C[i*m+j] = C[j*m+i] = dotSum; // use symmetric property
35        }
36    }
37    return C;
38}
39static matrix I() {
40    matrix ans(m * m, 0);
41    for (int i = 0; i < m; i++)
42        ans[i * m + i] = 1;
43    return ans;
44}
45// MSBF modular Matrix Exponentiation
46static matrix pow(const matrix& M, unsigned m) {
47    if (m == 0)
48        return I();
49    int bMax = 31 - __builtin_clz(m);
50    matrix ans = M;
51    for (int i = bMax - 1; i >= 0; i--) {
52        ans = symMul(ans, ans);
53        if ((m >> i) & 1)
54            ans = symMul(ans, M);
55    }
56    return ans;
57}
58
59class Solution {
60public:
61    static int zigZagArrays(int n, int l, int r) {
62        m = r - l + 1;
63        m2=m*m;
64        matrix U(m2, 0), L(m2, 0);
65        for (int i = 0; i < m; i++) {
66            for (int j = i + 1; j < m; j++)
67                U[i * m + j] = 1;
68        }
69        for (int i = 0; i < m; i++) {
70            for (int j = 0; j < i; j++)
71                L[i * m + j] = 1;
72        }
73        n--;
74        const int n0 = n >> 1;
75        const matrix UL = U * L;
76        matrix P = pow(UL, n0);
77        if (n & 1)
78            P = L * P;
79        return 2LL * reduce(P.begin(), P.end(), 0LL) % mod;
80    }
81};
82auto init = []() {
83    ios::sync_with_stdio(false);
84    cin.tie(nullptr);
85    cout.tie(nullptr);
86    return 'c';
87}();
88