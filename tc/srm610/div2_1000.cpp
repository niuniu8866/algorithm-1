#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
const int MAXN = 51*51;
int dp[MAXN][MAXN];
const int INF = 1999999999;
class MiningGoldEasy {
public:
    int GetMaximumGold(int N, int M, vector <int> event_i, vector <int> event_j) {
        int sz = event_i.size();

        //vector< pii > points;
        set< pii > tmp_points;
        for(int da=0; da<sz; da++){
            for(int db = 0; db<sz; db++){
                int x1 = event_i[da], x2 = event_i[db];
                int y1 = event_j[da], y2 = event_j[db];

                tmp_points.insert( pii(x1, y2) );
                tmp_points.insert( pii(x2, y1) );
        
            }
        }

        vector< pii > points(tmp_points.begin(), tmp_points.end());

        for(int i=0; i<sz; i++){
            bool ok = true;
            for(int j=0; j<points.size(); j++){
                if(points[j] == pii(event_i[i], event_j[i]))
                    ok = false;
            }
            if(ok)
                points.push_back( pii(event_i[i], event_j[i]));
        }


        memset(dp, 0, sizeof(dp));
        int k = event_i.size();
        for(int i=0; i<MAXN; i++){
            for(int d=0; d<MAXN; d++){
                dp[i][d] = INF;
            }
            //dp[i][0] = abs(event_i[k]-points[i].first) + abs(event_j[k]-points[i].second);
            dp[i][0] = 0;
        }

        sz = points.size();
        for(int d=0; d<k; d++){
            for(int i=0; i<sz; i++){
                for(int j=0; j<sz; j++){
                    if(points[i].first == points[j].first || points[i].second == points[j].second){
                        dp[j][d+1] = min(dp[j][d+1], dp[i][d] + abs(event_i[d]-points[j].first) + abs(event_j[d]-points[j].second));
                    }
                }
            }
        }
        int tmp = INF;
        for(int i=0; i<sz; i++){
            tmp = min(tmp, dp[i][k]);
        }
        return k*(N+M) - tmp;
    }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, int p4) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p2[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p3.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p3[i];
    }
    cout << "}";
    cout << "]" << endl;
    MiningGoldEasy *obj;
    int answer;
    obj = new MiningGoldEasy();
    clock_t startTime = clock();
    answer = obj->GetMaximumGold(p0, p1, p2, p3);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p4 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p4;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;
    
    int p0;
    int p1;
    vector <int> p2;
    vector <int> p3;
    int p4;
    
    {
    // ----- test 0 -----
    p0 = 2;
    p1 = 2;
    int t2[] = {0};
            p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    int t3[] = {0};
            p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    p4 = 4;
    all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }
    
    {
    // ----- test 1 -----
    p0 = 2;
    p1 = 2;
    int t2[] = {0,2};
            p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    int t3[] = {0,1};
            p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    p4 = 7;
    all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }
    {
    // ----- test 2 -----
    p0 = 3;
    p1 = 3;
    int t2[] = {0,3,3};
            p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    int t3[] = {0,3,0};
            p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    p4 = 15;
    all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }
    
    {
    // ----- test 3 -----
    p0 = 3;
    p1 = 4;
    int t2[] = {0,3};
            p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    int t3[] = {4,1};
            p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    p4 = 11;
    all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }
    
    {
    // ----- test 4 -----
    p0 = 5;
    p1 = 6;
    int t2[] = {0,4,2,5,0};
            p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    int t3[] = {3,4,5,6,0};
            p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    p4 = 48;
    all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }
    
    {
    // ----- test 5 -----
    p0 = 557;
    p1 = 919;
    int t2[] = {81,509,428,6,448,149,77,142,40,405,109,247};
            p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
    int t3[] = {653,887,770,477,53,637,201,863,576,393,512,243};
            p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
    p4 = 16255;
    all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
    // ------------------
    }
    
    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
