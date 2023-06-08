/*
Strategy
- 노드들을 탐색하다가 연결이 끊기면 네트워크하나가 끝난 것으로 +1

Method
- 재귀함수를 이용하자 (깊이 탐색)
*/

#include <vector> 
using namespace std; 

int check[200]; 
void DFS(int current_computer, int n, vector< vector<int>> computers) { 
  check[current_computer] = 1;
  for(int i=0; i<n; i++) { 
    if(check[i] == 0 && computers[current_computer][i] == 1) {   
      dfs(i, n, computers); 
    } 
  } 
} 

int solution(int n, vector< vector<int> > computers) { 
  int answer = 0;
  for(int i=0; i<n; i++) { 
    if(check[i] == 0) { 
      DFS(i, n, computers);
            answer++; 
    } 
  } 
  return answer;
}
