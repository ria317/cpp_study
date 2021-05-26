// 1260 DFS/BFS 문제
// https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
#include <algorithm>

#include <climits>

#include <queue>
using namespace std;


vector<int> bfs_res;
vector<int> dfs_res;

void DFS(vector<vector<int>>& v, int x, vector<bool>& footp) {
    if( x < 0 || x >= v.size() )
        return ;

    if( footp[x] == true) return ;

    footp[x] = true;
    dfs_res.push_back(x);

    for(int i=0; i< v[0].size() ; i++) {
        if( v[x][i] == 1 ) {
            DFS(v, i, footp);
        }
    }

}

void solve_DFS(vector<vector<int>> v, int start) {

    vector<bool> footp(v.size(), false);
    DFS(v, start, footp);

// print..
    for(int i=0; i<dfs_res.size(); i++) {
        if( i != dfs_res.size()-1)
            cout << dfs_res[i] << " ";
        else
            cout << dfs_res[i];
    }
    cout << endl;

}


bool IsExist(vector<int>& res, int x) {

    vector<int> cpy = res;

    for( int i=0; i<cpy.size(); i++) {
        if( cpy[i] == x ) return true;
    }
    return false;
}

void N_BFS(vector<vector<int>>& v, queue<int>& q ) {

    int N= v.size();

    while(!q.empty()) {
        int comp = q.front();
        //cout << comp << " " ;
        if( IsExist(bfs_res, comp) ) {
            q.pop();
            continue;
        }
        bfs_res.push_back(comp);
        //footp[comp] = true;
        q.pop();
        for(int i=0; i<N; i++) {
            if( v[comp][i] == 1 /*&& !(IsExist(bfs_res, i))*/ ) {

                q.push(i);
                v[comp][i] = -1;
                v[i][comp] = -1;
            }
        }
    }
    cout << endl;

}

void solve_BFS(vector<vector<int>> v, int start) {

    queue<int> q;

    q.push(start);
    N_BFS(v, q);

// print..
    for(int i=0; i<bfs_res.size(); i++ ) {
        if( i != bfs_res.size()-1 )
            cout << bfs_res[i] << " ";
        else
            cout << bfs_res[i];
    }
    cout << endl;

}


int main(void) {

    int N, node_cnt, start_node;


    cin >> N >> node_cnt >> start_node;

    vector<vector<int>> v(N+1, vector<int>(N+1, -1));
    for(int i=0; i<node_cnt; i++) {
        int x,y;

        cin >> x >> y;
        v[x][y] = 1;
        v[y][x] = 1;

    }

    solve_DFS(v, start_node);
    solve_BFS(v, start_node);

    return 0;
}
