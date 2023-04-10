/* 
문제 출처 :  https://school.programmers.co.kr/learn/courses/30/lessons/1845
💡 Targets
- N(1 ~ 10,000 - 항상 짝수) 마리 중 1/2 가져도 됨
- 폰켓몬 종류에 따라 번호로 구분되어 있음
- 가질 수 있는 폰켓몬 종류의 최댓값을 return

🔑 Strategy
- 벡터의 중복제거

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
