#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	int x,y;
	cin>>x>>y;
	int ground[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>ground[i][j];
		}
	}
	int self_energy = ground[x-1][y-1];
	ground[x-1][y-1] = 0;
	for(int i=x;i<n;i++){
		ground[i][y-1] += ground[i-1][y-1];
	}
	for(int j=y;j<m;j++){
		ground[x-1][j] += ground[x-1][j-1];
	}
	for(int i=x;i<n;i++){
		for(int j=y;j<m;j++){
			ground[i][j] += min(ground[i-1][j], ground[i][j-1]);
		}
	}
	int final_energy = ground[n-1][m-1];
	if(final_energy <= self_energy){
		cout<<"Y "<<(self_energy - final_energy)<<endl;
	}
	else{
		cout<<"N"<<endl;	
	}
	return 0;
}
