#include <bits/stdc++.h>
using namespace std;

#define S second

int n,s;
int value[2001], sizex[2001];
int memo[2001][2001];
int dp(int i , int S){
	if(i == n || S <= 0)
		return 0;
	int &ans = memo[i][S];
	if(ans != -1)return ans;
	ans = dp(i+1,S);
	if(S-sizex[i] >= 0){
		ans = max( dp(i+1,S-sizex[i])+value[i] , dp(i+1,S) );
	}
	return ans;
}

int main()
{
	memset(memo,-1,sizeof memo);
	scanf("%d %d",&s,&n);
	for(int i = 0 ; i < n ; ++i)
		scanf("%d %d",sizex+i,value+i);
	cout << dp(0,s);
    cout << '\n';
	return 0;
}