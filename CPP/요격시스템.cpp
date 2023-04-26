/* 
💡 Targets
- A로부터 받은 공격 미사일을 격추하는 최소 요격 미사일 수를 return하라
- y 축에 수평인 미사일로 공격하여 한번에 요격가능하며, 개구간 내에서만 가능함
🔑 Strategy
- 요격범위를 활용하여 미사일 범위를 조정함
- 미사일 범위에 맞춰 요격 범위를 좁히고, 범위 안에 들어오는 미사일만 처리
🔑 Solution
1) 미사일의 시작위치를 기준으로 오름차순으로 정렬함
2) 반복문을 돌며 미사일의 길이 범위를 검사
3) 미사일 요격 범위로 잡은 후 미사일 길이 범위에 따라 요격범위 축소
4) 요격 범위를 이탈하는 미사일이 등장하면 새로운 요격 범위 갱신 (answer++)
*/


#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution1(vector<vector<int>>targets) {
    int answer = 0;
    int b, e = 0;
    sort(targets.begin(), targets.end());
    for (int i = 0 ; i < targets.size(); i++){
        if (targets[i][0] >= e){
            b = targets[i][0];
            e = targets[i][1];
            answer += 1;
        }
    }
    return answer;
}

/*
Solution 1 

테스트 1 〉	통과 (0.01ms, 4.15MB)
테스트 2 〉	실패 (0.01ms, 4.2MB)
테스트 3 〉	실패 (0.02ms, 3.66MB)
테스트 4 〉	실패 (0.18ms, 4.13MB)
테스트 5 〉	실패 (1.52ms, 5.12MB)
테스트 6 〉	실패 (21.05ms, 22MB)
테스트 7 〉	실패 (222.25ms, 96.7MB)
테스트 8 〉	실패 (212.66ms, 96.5MB)
테스트 9 〉	통과 (178.66ms, 94.7MB)
테스트 10 〉	통과 (91.89ms, 77.8MB)
테스트 11 〉	통과 (0.01ms, 4.14MB)
*/

#include <bits/stdc++.h>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b) {
  cout<< "a" << a[1] <<"b"<< b[1];  
  return a[1] < b[1];
}

int solution2(vector<vector<int>> targets) {
  sort(targets.begin(), targets.end(), cmp);

  int ans = 0;
  int t = -1;
  for (auto& tar: targets) {
    if (tar[0] >= t) {
      t = tar[1];
      ans++;
    }
  }

  return ans;
}

/* 
비교함수를 사용하던지, begin과 end를 모두 검사해주는 항목이 있던지 해야했다.
내가 만든 정답은 [[1 5] [2 3] [3 4]] 라는 순서로 소팅 될 수 있으며, 이에 따라 정답은 2이지만 1이라는 결과를 내보낼 수 있다. 
sort의 compare를 통해서 end 끼리 비교하도록 한다면 
23 / 34 / 15 의 순으로 결과를 보낼 것이다.
*/
