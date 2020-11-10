//AnkitCode99 here....
//every ups and downs matter!

#include<bits/stdc++.h>
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr)
typedef long long int ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back

using namespace std;

const ll sz=1e5+5;
const ll szz=1e6+6;
const ll mod=1e9+7;

vector<string> grid;

// Dijkstra in GRID

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

bool isValid(ll x,ll y,ll row,ll col)
{
    return (x>=0 and x<row and y>=0 and y<col);
}

void dijkstra()
{
    ll n = grid.size();
    ll m = grid[0].size();

    ll dist[n][m];
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            dist[i][j] = 1e15;
        }
    }

    bool vis[n][m];
    memset(vis,0,sizeof vis);

    vis[0][0]=1;
    dist[0][0]=0;
    queue<pair<ll,ll>> q;
    q.push({0,0});

    // cout<<"Fine\n";
    // return;
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();

        if(it.first==(n-1) and it.second==(m-1))
        {
            break;
        }


        for(ll i=0;i<4;i++)
        {
            ll nx = it.first + dx[i];
            ll ny = it.second + dy[i];
            // cout<<nx<<" "<<ny<<endl;

            if(isValid(nx,ny,n,m))
            {
                if(!vis[nx][ny] and grid[nx][ny]=='.')
                {
                    dist[nx][ny] = dist[it.first][it.second]+1;
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }

            // if(!vis[nx][ny] and grid[nx][ny]=='.' and isValid(nx,ny,n,m))
            // {
            //     cout<<nx<<" "<<ny<<endl;
            // //     dist[nx][ny] = dist[it.first][it.second]+1;
            // //     vis[nx][ny]=1;
            //     q.push({nx,ny});
            // }
        }
    }


    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
}

int main()
{
    IOS;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif

    clock_t startTime=clock();

    ll n;
    cin>>n;
    rep(i,0,n)
    {
        string s;
        cin>>s;
        grid.pb(s);
    }

    // cout<<"entered\n";

    dijkstra();


    cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

}//Goodbye...