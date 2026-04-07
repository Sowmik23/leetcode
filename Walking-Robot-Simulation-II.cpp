1class Robot {
2public:
3    int currX = 0;
4    int currY = 0;
5    
6    int w;
7    int h;
8    
9    string directions = "East";
10    
11    Robot(int width, int height) {
12        w = width;
13        h = height;
14    }
15    
16    void move(int num) {
17        
18        num = num%((w-1+h-1)*2);
19        if(num==0){
20            if(currX==0 and currY==0) directions="South";
21        }
22        if(directions.compare("East")==0){
23            while(currX<w-1 and num>0){
24                currX++;
25                num--;
26                directions = "East";
27            }
28            while(currY<h-1 and num>0){
29                currY++;
30                num--;
31                directions = "North";
32            }
33            while(currX>0 and num>0){
34                currX--;
35                num--;
36                directions = "West";
37            }
38            while(currY>0 and num>0){
39                currY--;
40                num--;
41                directions = "South";
42            }
43            while(currX<w-1 and num>0){
44                currX++;
45                num--;
46                directions = "East";
47            }
48        }
49        else if(directions.compare("North")==0){
50            while(currY<h-1 and num>0){
51                currY++;
52                num--;
53                directions = "North";
54            }
55            while(currX>0 and num>0){
56                currX--;
57                num--;
58                directions = "West";
59            }
60            while(currY>0 and num>0){
61                currY--;
62                num--;
63                directions = "South";
64            }
65            while(currX<w-1 and num>0){
66                currX++;
67                num--;
68                directions = "East";
69            }
70            while(currY<h-1 and num>0){
71                currY++;
72                num--;
73                directions = "North";
74            }
75        }
76        else if(directions.compare("West")==0){
77            while(currX>0 and num>0){
78                currX--;
79                num--;
80                directions = "West";
81            }
82            while(currY>0 and num>0){
83                currY--;
84                num--;
85                directions = "South";
86            }
87            while(currX<w-1 and num>0){
88                currX++;
89                num--;
90                directions = "East";
91            }
92            while(currY<h-1 and num>0){
93                currY++;
94                num--;
95                directions = "North";
96            }
97            while(currX>0 and num>0){
98                currX--;
99                num--;
100                directions = "West";
101            }
102        }
103        else if(directions.compare("South")==0){
104            while(currY>0 and num>0){
105                currY--;
106                num--;
107                directions = "South";
108            }
109            while(currX<w-1 and num>0){
110                currX++;
111                num--;
112                directions = "East";
113            }
114            while(currY<h-1 and num>0){
115                currY++;
116                num--;
117                directions = "North";
118            }
119            while(currX>0 and num>0){
120                currX--;
121                num--;
122                directions = "West";
123            }
124            while(currY>0 and num>0){
125                currY--;
126                num--;
127                directions = "South";
128            }
129        }
130    }
131    
132    void step(int num) {
133        move(num);
134    }
135    
136    vector<int> getPos() {
137        return {currX, currY};
138    }
139    
140    string getDir() {
141        return directions;
142    }
143};
144
145/**
146 * Your Robot object will be instantiated and called as such:
147 * Robot* obj = new Robot(width, height);
148 * obj->step(num);
149 * vector<int> param_2 = obj->getPos();
150 * string param_3 = obj->getDir();
151 */