#include <iostream>
#include<vector>
using namespace std;
int N;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
struct Node{
    char dir;
    int cnt;
};
int ny;
int nx;
vector<Node>v;
void input(){
    cin >> N;
    for(int i=0;i<N;i++){
        char a;
        int b;
        cin >> a >> b;
        v.push_back({a,b});
    }
}

void solution(){
    for(int i=0;i<N;i++){
        if(v[i].dir == 'N'){
            ny = ny +v[i].cnt;
        }
        else if(v[i].dir == 'S'){
            ny = ny -v[i].cnt;
        }
        else if(v[i].dir == 'E'){
            nx =nx + v[i].cnt;
        }
        else{
            nx =nx - v[i].cnt;
        }
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    input();
    solution();

    cout << nx <<" "<<ny;

    return 0;
}