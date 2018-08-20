#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &segments)
{
    int count = -1;
    int prev = 0;
    int next = 1;
    if(segments.size() == 0 || segments.size() == 1)
        count = 0;
    else if(segments.size() > 1)
    {
        count = 0;
        int prev_segment = segments[prev];
        int next_segment = segments[next];
        int lane_exists = segments[0];
        for(int i = 1; i < segments.size() ; i+=1)
        {
            next_segment = segments[i];
            lane_exists = lane_exists & next_segment;
            if( lane_exists )
            {
                continue;
            }
            else if((prev_segment<<1) & next_segment)
            {
                count++;
                lane_exists = (prev_segment<<1) & next_segment;
            }
            else if((prev_segment>>1) & next_segment)
            {
                count++;
                lane_exists = (prev_segment>>1) & next_segment;
            }
            else
            {
                count = -1;
                break;
            }
            prev_segment = segments[i];
        }
    }
    return count;
}

int main()
{
    vector<int> segments = {1,10,1,15}; //expected ans 2 : 0001,1010,0001,1111
    //vector<int> segments = {1,1,1,1}; //expected ans 0 : 0001, 0001, 0001, 0001
    //vector<int> segments = {1,16,4,8}; // expected ans -1 : 0001, 10000,0100, 1000
    //vector<int> segments = {1,2,4,8}; // expected ans 3 : 0001, 0010, 0100, 1000
    //vector<int> segments = {1,3,5,7}; // expected ans 0 : 0001, 0011, 0101, 0111
    //vector<int> segments = {7,11,10,4};// expected ans 1 : 0111, 1011, 1010,0100

    int laneChangeCount = solution(segments);

    cout<<"Lane Change Count:"<<laneChangeCount<<endl;
}
