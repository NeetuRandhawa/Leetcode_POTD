class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>&points) {

        sort(points.begin(),points.end());

        int  r = points[0][1], cnt = 0;

        for(int i = 1; i < points.size(); ++i)
        {
            if(r > points[i][0])
            {
                r = min(r, points[i][1]);
                cnt++; 
            }

            else r = points[i][1];
                    
        }
         return cnt; 
    }
};
