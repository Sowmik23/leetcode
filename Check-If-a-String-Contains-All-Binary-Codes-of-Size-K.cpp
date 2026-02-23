1class Solution {
2public:
3    bool hasAllCodes(string s, int k) {
4        
5        //Approach: 01
6        /*
7        int n = s.size();
8        string str = "";
9        int limit = pow(2, k)-1;
10        //cout<<"limit: "<<limit<<endl;
11        set<int> st;
12
13        for(int i=0;i<n;i++){
14            str+=s[i];
15            if(i>=k){
16                str = str.substr(1);
17                int num = stoi(str, nullptr, 2);
18                //cout<<num<<" "<<str<<endl;
19                st.insert(num);
20                if(num<0 or num>limit) return false;
21            }
22            else if(i==k-1){
23                int num = stoi(str, nullptr, 2);
24                //cout<<num<<" "<<str<<endl;
25                st.insert(num);
26                if(num<0 or num>limit) return false;
27            }
28        }
29        return st.size()==limit+1;
30        */
31
32        //Approach: 02
33        int n = s.size();
34        set<string> st;
35        string str = "";
36        int limit = pow(2, k); // 1<<k same
37
38        for(int i=k;i<=n;i++){
39            str = s.substr(i-k, k);
40            if(st.find(str)==st.end()){
41                st.insert(str);
42                if(st.size()==limit) return true;
43            }
44        }
45        return false;
46    }
47};