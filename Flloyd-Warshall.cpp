//AnkitCode99 here....
//every ups and downs matter!

#include<bits/stdc++.h>
#define endl "\n"
#define Ryuga ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)

using namespace std;

const ll sz=1e5+5;
const ll szz=1e6+6;
const ll mod=1e9+7;

ll n;
ll ar[300][300];
ll minTime[300][300];

void floydd()
{
	rep(i,0,n)
	{
		rep(j,0,n)
		{
			rep(k,0,n)
			{
				if(minTime[j][k] > minTime[j][i] + minTime[i][k]) 
					minTime[j][k] = minTime[j][i] + minTime[i][k];
			}
		}
	}
}

int main()
{
	//Easiest example - HOMDEL (CodeChef)

	Ryuga;

	#ifndef ONLINE_JUDGE
	freopen("IP.txt","r",stdin);
	freopen("OP.txt","w",stdout);
	#endif

	clock_t startTime=clock();

	cin>>n;
	rep(i,0,n)
	{
		rep(j,0,n)
		{
			cin>>ar[i][j];
			minTime[i][j]=ar[i][j];
		}
	}

	floydd();

	ll q;
	cin>>q;
	while(q--)
	{
		ll s,g,d;
		cin>>s>>g>>d;
		ll old=minTime[s][g]+minTime[g][d];
		ll naya=minTime[s][d];
		cout<<old<<" "<<old-naya<<endl;
	}

	cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

}//Goodbye...