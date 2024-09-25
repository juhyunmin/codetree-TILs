#include <iostream>
#include <string>

#define DIR_NUM 4

using namespace std;

string dirs;
int x = 0, y = 0;
int curr_dir = 3;

// 동, 남, 서, 북 순으로 dx, dy를 정의합니다.
int dx[DIR_NUM] = {1,  0, -1, 0};
int dy[DIR_NUM] = {0, -1,  0, 1};

int main() {
    // 입력
    cin >> dirs;
    
    // 움직이는 것을 진행합니다.
    for(int i = 0; i < (int) dirs.size(); i++) {
        char c_dir = dirs[i];
        
		// 반시계방향 90' 회전
        if(c_dir == 'L')
            curr_dir = (curr_dir - 1 + 4) % 4;
		// 시계방향 90' 회전
        else if(c_dir == 'R')
            curr_dir = (curr_dir + 1) % 4;
		// 직진
        else {
            x += dx[curr_dir];
            y += dy[curr_dir];
        }
    }
    
    cout << x << " " << y;
    return 0;
}