class Solution {
    vector<int> dir = {-1,0,1,0,-1};
    struct node{
        int r,c,time,cost;
        node(int r,int c,int time,int cost){
            this->r=r;
            this->c=c;
            this->time=time;
            this->cost=cost;
        }
    };
    struct comparator {
        bool operator()(node* p1, node* p2){
            return p1->time > p2->time;
        }
    };
    bool isValid(int& r,int& c,int& m,int& n){
        return (r>=0 and r<m and c>=0 and c<n);
    }
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m=moveTime.size();
        int n=moveTime[0].size();   
        priority_queue<node*,vector<node*>,comparator> minheap;
        node* start = new node(0,0,0,1);
        minheap.push(start);
        vector<vector<bool>> visited(m,vector<bool>(n));
        visited[0][0]=true;
        while(!minheap.empty()){
            node* curr = minheap.top();
            minheap.pop(); 
            if(curr->r==m-1 and curr->c==n-1)
                return curr->time;
            
            for(int i=0;i<4;++i){
                int newR = curr->r + dir[i];
                int newC = curr->c + dir[i+1];
                int cost = curr->cost;
                int nextCost = cost==1?2:1;
                
                if(isValid(newR,newC,m,n) and !visited[newR][newC]){
                    node *newnode = new node(newR,newC,cost+max(curr->time,moveTime[newR][newC]),nextCost);
                    minheap.push(newnode);
                    visited[newR][newC] = true;
                }
            }
        }
        return -1;
    }
};