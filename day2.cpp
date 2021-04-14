#include <iostream>

using namespace std;
/*
*   2021 4/13 algorithm study day_2
    vector

    자료구조 .  stack / array 로 사용


vector.end() 는 마지막요소의 다음인 null point를 가리킨다.

*
*/


// cache
// vector<vector<int>> cache;


//

/*
return min( dfs(x, y-1), dfs(x-1, y))
*/


// DAY2 과제..

// 100*100
// DFS를 탈때마다 몇번 타는지 출력하고
// 가지치기를 추가했을 때 얼마나 성능이 개선되는지 비교
// DFS 몇번타는지 횟수 출력..
// 가지치기는 min_cost를 들고있으면서 현재까지의 비용이 min_cost 보다 초과되면 탐색 종료

// DAY3 발표주제
//
//  stack
//  set
//  unordered set

// 멤버함수 중 많이쓰는것드만 10개 시간복잡도 까지..
//
#include <vector>
#include <climits>


int DFS_COUNT;
int DFS2_COUNT;

int DFS(int x, int y, vector<vector<int>>& v) {

    DFS_COUNT++;
    // boundary check
    if( x < 0 || y < 0 )
        return INT_MAX;

    if( x == 0 && y == 0 )
        return v[x][y];

    return v[x][y] + min( DFS(x-1, y, v), DFS(x, y-1, v));

}


// DFS  가지치기 추가된버전
int DFS2( int x, int y, vector<vector<int>>& v, int curr_cost, int& min_cost) {

    DFS2_COUNT++;
    // boundary check
    if( x < 0 || y < 0 )
        return INT_MAX;

    curr_cost += v[x][y];

    if( curr_cost > min_cost ) {
        return  INT_MAX;
    }

    if( x == 0 && y == 0 ) {
        min_cost = min(min_cost, curr_cost);
        return v[x][y];
    }
    return min(min_cost, abs(v[x][y] + min( DFS2(x-1, y, v, curr_cost, min_cost), DFS2(x, y-1, v, curr_cost, min_cost))));

}

int solve(vector<vector<int>>& v) {

    int row = v.size();
    int col = v[0].size();

    int curr_cost = 0;
    int min_cost = INT_MAX;

    cout << "DFS : " << DFS(row-1, col-1, v) << ", call count : " << DFS_COUNT << endl;

    cout << "DFS2 : " << DFS2(row-1, col-1, v, curr_cost, min_cost) << ", call count : " << DFS2_COUNT << endl;
    return 1;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> v =
    {{3,9,2,5,3,2,4},
     {6,4,5,2,4,2,6},
     {1,7,3,3,7,2,4},
     {1,7,3,6,7,2,5},
     {1,7,8,3,7,1,4},
     {1,7,3,9,9,2,7}
    };

    solve(v);
    //cout << "DFS : " << solve(v) << " call count : " << DFS_COUNT << endl;
    return 1;
}
