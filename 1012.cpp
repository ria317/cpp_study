// 유기농배추
//https://www.acmicpc.net/problem/1012

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;

void DFS(vector<vector<int>>& board, int x, int y) {

    if( x < 0 || y < 0 || x >= board.size() || y >= board[0].size() ) return ;

    if( board[x][y] == -1) return ;

    board[x][y] = -1;

    DFS( board, x+1, y);
    DFS( board, x-1, y);
    DFS( board, x, y+1);
    DFS( board, x, y-1);


}

void solve(vector<vector<int>>& board) {

   int n= board.size();  // x 축
   int m = board[0].size(); //y 축

   int result = 0;

   for(int i=0; i<n; i++) {
       for(int j=0; j<m; j++) {
           if( board[i][j] == 1) {
               DFS(board, i,j);
               result++;
           }
       }
   }

   res.push_back(result);

}


void input() {
//가로 m, 세로 n, d위치갯수 k
    int n, m, k;
    int x,y;

    cin >> m >> n >> k;

    vector<vector<int>> board(m, vector<int>(n, -1));

    for(int i=0; i<k; i++) {
        cin >> x >> y;
        board[x][y] = 1;
    }

    solve(board);

}


int main(void) {

    int t;

    cin >> t;

    for(int i=0; i<t; i++) {
        input();
    }

    for(int i=0; i<t; i++) {
        cout << res[i] << endl;
    }

}
