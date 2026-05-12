#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> vec(n,0);
  for(int i=0;i<n;i++) cin>>vec[i];
  // int help(){
  //   if(curr=-1 ) update curr, idx++
  //   curr,idx++
  // }
  vector<vector<int>> dp(n+1,vector<int>(n+1,0));
  for(int i=n-1;i>=0;i--){
    for(int j=i-1;j>=-1;j--){
      int a=0;
      if(j==-1 or vec[i]>vec[j]) a=dp[i+1][i+1]+1;
      int b=dp[i+1][j+1];
      dp[i][j+1]=max(a,b);
    }
  }
  cout<<dp[0][0];
  
}