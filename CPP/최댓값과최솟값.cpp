/* 
💡 Targets
- 문자열에 포함되어있는 숫자를 "최소값 최댓값"의 형태로 반환하라
🔑 Strategy
- 
🔑 Method
- cnt = 배열길이의 N/2 저장
- 중복 제거 길이(a) > cnt -> cnt 최댓값 
- 중복 제거 후 길이(a) < cnt -> nums의 길이가 최댓값
*/

#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int cnt = nums.size() / 2;
    set <int> a;
    for(int i=0; i<nums.size(); i++){
        a.insert(nums[i]);
    }
    if(a.size() >= cnt){
        answer = cnt;
    }
    else{
        answer = a.size();
    }
    return answer;
}


/*
#include <vector>
#include <set>
#include<algorithm>
using namespace std;
int solution(vector<int> nums)
{
    set<int> s1(nums.begin(), nums.end());
    return min(s1.size(), nums.size() / 2);
}
*/
