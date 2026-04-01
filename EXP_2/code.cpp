class Solution {
public:
    
    pii reducer(int x,int y, int z, int w){
        int a = x-y, b= z-w;
        if(!a) return {x,0};
        if(!b) return {0,z};
        int g = __gcd(a,b);
        return {a/g,b/g};
    }
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res=1;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                auto [x,y]= reducer(points[i][0],points[j][0], points[i][1],points[j][1]);
                int ctr=2;
                for(int k=j+1;k<n;k++){
                    auto [a,b]=reducer(points[i][0],points[k][0], points[i][1],points[k][1]);
                    if(a==x && b==y) ctr++;
                }
                res=max(res,ctr);
            }
        }
        return res;
    }
};
