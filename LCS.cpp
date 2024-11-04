#include<iostream>
#include<string>
using namespace std;

void LCS(string X, string Y, int m,int n){
	int DP[m+1][n+1];
	for(int i = 0 ; i <=m;i++){
		for(int j = 0; j<=n;j++){
			if(i==0 or j==0){
				DP[i][j]=0;
			}
			else if (X[i-1] == Y[j-1]){
				DP[i][j]=1+DP[i-1][j-1];
			}
			else{
				DP[i][j] = max(DP[i-1][j],DP[i][j-1]);
			}
		}
	}
	
	int i = m, j = n;
	string lcs ="";
	while (i>0 && j>0)
	{
		if (X[i-1]==Y[j-1])
		{
			lcs=X[i-1]+lcs;
			i--;
			j--;
		}
		else if (DP[i-1][j]>DP[i][j-1]){
			i--;
		}
		else{
			j--;
		}
		
	}

	cout<<"The longest common subsequence is "<<lcs<<" of length "<<DP[m][n]<<endl;
	
}

int main(){
	string S="Computer",SS="put";
	int m=8, n=3;
	
	LCS(S,SS,8,3);

}
