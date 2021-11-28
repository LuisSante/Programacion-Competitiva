#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;
char A[31][31][31];
int l,r,c;
int next_[6][3]={{1,0,0},
                {-1,0,0},
                {0,1,0},
                {0,-1,0},
                {0,0,1},
                {0,0,-1}};

struct Node{
    int x,y,z,step;
}start_,end_,current,net;

int bfs(){
    queue<Node> q;
    q.push(start_);
    while(q.size()){
        current=q.front();

        if(current.x==end_.x && current.y==end_.y && current.z==end_.z)
            return current.step;

        for(int i=0; i<6; i++){
            net.x = current.x + next_[i][0];
            net.y = current.y + next_[i][1];
            net.z = current.z + next_[i][2];
            if(net.x>0 && net.x<=l && net.y>0 && net.y<=r && net.z>0 && net.z<=c && A[net.x][net.y][net.z]!='#'){
                A[net.x][net.y][net.z]='#';
                net.step=current.step+1;
                q.push(net);
            }
        }
        q.pop();
    }
    return -1;
}

int main(){
    while(cin>>l>>r>>c){
        if(l==0 && r==0 && c==0)
            break;

        for(int i=1; i<=l; i++){
            for(int j=1; j<=r; j++){
                for(int k=1; k<=c; k++){
                    cin>>A[i][j][k];

                    if(A[i][j][k]=='S'){
                        start_.x=i;
                        start_.y=j;
                        start_.z=k;
                        start_.step=0;
                    }

                    if(A[i][j][k]=='E'){
                        end_.x=i;
                        end_.y=j;
                        end_.z=k;
                    }
                }
            }
        }
        int ans=bfs();
        if(ans == -1)
            cout<<"Trapped!"<<endl;
        else 
            cout<<"Escaped in "<<ans<<" minute(s).\n";
    }
    return 0;
}