#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 참조 &에 의한 전달 a값 자체가 전달되는 것임으로 복사가 일어나지 않음 
bool cmp(const vector<int>& a, const vector<int>& b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), cmp);

    int answer = 0;
    int t = -300001;
    
    for (auto& rout:routes){
        if(rout[0] > t){
            t = rout[1];
            answer +=1;
        }
    }
    return answer;
}
