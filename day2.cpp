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

#define MAX_COST 1000000

int DFS(int x, int y, vector<vector<int>>& v, int& min_cost, int& curr_cost) {

    // boundary check
    if( x < 0 || y < 0 )
        return 0;

    curr_cost+= v[x][y];

    //cout << "current: " << curr_cost << ", v: " << v[x][y] << endl;
    if( x == 0 && y == 0 ) {
        // 도착 했을 때 현재까지의 min_cost와 비교하여 비용이 적응경우 UPDATE 함.
        cout << " finish , current cost : " << curr_cost << "  min_cost : " << min_cost << endl;
        //min_cost = min(curr_cost, min_cost);
        //curr_cost -=v[x][y];
        return curr_cost;
    }
    DFS(x-1, y, v, min_cost, curr_cost);
    DFS(x, y-1, v, min_cost, curr_cost);
    curr_cost -=v[x][y];
    return 1;

}

int solve(vector<vector<int>>& v) {

    int row = v.size();
    int col = v[0].size();
    int min_cost = INT_MAX;
    int curr_cost = 0;

    DFS(row-1, col-1, v, min_cost, curr_cost);

    //cout << min_cost << endl;
    return min_cost;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> v =
    {{3,9,2},
     {6,4,5},
     {1,7,3}
    };
    cout << solve(v) << endl;

    return 1;
}
