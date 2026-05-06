1class Solution {
2public:
3    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
4        
5        
6        int row = box.size();
7        int column = box[0].size();
8        
9        for(int i=0;i<row;i++){
10            
11            int obstacle = column-1, stone=0;
12            for(int j = column-1; j>=0;j--){
13                if(box[i][j]=='*'){
14                    obstacle = j-1;
15                    stone = 0;
16                }
17                else if(box[i][j]=='#'){
18                    box[i][j] = '.';
19                    int newJ = obstacle-stone;
20                    box[i][newJ] = '#';
21                    stone++;
22                }  
23            }
24        }
25        
26        // for(int i=0;i<box.size();i++){
27        //     for(int j=0;j<box[i].size();j++){
28        //         cout<<box[i][j]<<" ";
29        //     }
30        //     cout<<endl;
31        // }
32    
33        
34        // rotating this 2d vector in 90 degree clockwise
35        vector<vector<char>> res;
36        
37        for(int i=0;i<column;i++){
38            
39            vector<char> tmp;
40            for(int j=row-1;j>=0;j--){
41                tmp.push_back(box[j][i]);
42            }       
43            res.push_back(tmp);
44        }
45        
46        return res;
47    }
48};