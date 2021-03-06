//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
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


const ll MAXn=752,MAXlg=__lg(MAXn)+2;
const ll MOD=1000000007;
const ll INF=ll(1e15);

int d[MAXn][MAXn];
int tmpct[MAXn][MAXn],td[MAXn];
ll ct[MAXn][MAXn];

int main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    REP(i,n)
    {
      string s;
      cin>>s;
      REP(j,m)d[i][j]=s[j]-'0';
    }

    ll tt=0;
    REP(i,n)
    {
      REP(j,m)td[j]=1;
      //FILL(tmpct,0);
      for(int j=i;j<n;j++)
      {
        REP(k,m)td[k]&=d[j][k],tmpct[j][k]=0;
        int it=0,it2=0;

        while(it<m)
        {
            int tmp=0;
            for(;it2<m&&td[it2];it2++)tmp+=it2-it+1;
            tt+=tmp;
            for(int k=it;k<it2;k++)tmpct[j][k]=(k-it+1)*(it2-k);
            it2++;
            it=it2;
        }
      }
      for(int j=n-1;j>=i;j--)
      {
        REP(k,m)
        {
          tmpct[j][k]+=tmpct[j+1][k];
          ct[j][k]+=tmpct[j][k];
        }
      }
    }
    ll mn=tt;
    debug(tt);
    REP(i,n)REP(j,m)mn=min(mn,tt-ct[i][j]);
    cout<<mn<<endl;
}
