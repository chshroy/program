//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#ifdef brian
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<" ,";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
#else
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#endif // brian
//}


const ll MAXn=1e3+5,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1.5e9);

int d[MAXn];
int pre[MAXn];
int dp[MAXn][MAXn],pi[MAXn][MAXn];


int main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    m=min(n,m);
    REP1(i,n-1)cin>>d[i];
    sort(d+1,d+n+1);
    REP1(i,n)pre[i]=d[i]+pre[i-1];
    REP1(i,n)pi[i][0]=0,pi[n+1][i]=n,dp[i][0]=INF;
    REP1(j,m)for(int i=n;i>=j;i--)
    {
      dp[i][j]=INF;

      for(int k=pi[i][j-1];k<=pi[i+1][j]&&k<i;k++)
      {
        int x=(i+k+1)>>1;
        int t=dp[k][j-1]+d[x]*(x-k+x-i)-(pre[x]-pre[k])+pre[i]-pre[x];
        if(t<dp[i][j])pi[i][j]=k,dp[i][j]=t;
      }
    }
    cout<<dp[n][m]<<endl;
}
