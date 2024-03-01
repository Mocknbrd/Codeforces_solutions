#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		long long c1,c2,c3,c4,c5,c6;
		cin>>c1>>c2>>c3>>c4>>c5>>c6;
		long long ans=INT_MAX;
		ans=abs(x)*(x>=0?c1:c4)+(abs(x-y)*(x-y>=0?c5:c2));
		ans=min(ans,(abs(x)*(x>=0?c6:c3)+(abs(y)*(y>=0?c2:c5))));
		ans=min(ans,(abs(y)*(y>=0?c1:c4)+(abs(y-x)*(y-x>=0?c3:c6))));
		cout<<ans<<endl;
	}
}