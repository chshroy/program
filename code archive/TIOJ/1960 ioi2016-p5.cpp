//{
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(ll i=0;i<n;i++)
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
template<typename _a,typename _b> ostream& operator << (ostream &_s,pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
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
template<typename _t>
struct ary
{
    _t _a,_b;
    ary(_t _ai,_t _bi):_a(_ai),_b(_bi){}
};
#else
#define debug(...)
//#define endl '\n'
#endif // brian
//}

const ll MAXn=129,MAXlg=8;
const ll MOD=1000000007;
const ll INF=ll(1e15);

#ifndef brian
#include "lib1960.h"
#else
ll cnta=0,cntc=0;
int p[MAXn];
ll n;
vector<string> v;
void add_element(char *d)
{
    //cout<<d<<endl;
    string s(d);
    v.pb(s);
    cnta++;
}
void compile_set()
{
    for(string &s:v)
    {
        string k=s;
        REP(i,n)k[i]=s[p[i]];
        s=k;
    }
    debug("COMPILED");
    //for(string &s:v)cout<<s<<endl;
}
int check_element(char *d)
{
    cntc++;
    string s(d);
    if(find(ALL(v),s)!=v.end())return 1;
    else return 0;
}
#endif

char d[MAXn];
vector<int> st[MAXlg][MAXn];
void restore_permutation(int n,int w,int r,int *ans)
{
    FILL(d,0);
    REP(i,MAXlg)REP(j,MAXn)st[i][j].resize(0);
    for(int i=1;i<n;i*=2)
    {
        ll l=n/i;
        REP(j,i)
        {
            REP(k,l/2)
            {
                REP(x,n)
                {
                    if(x<j*l||x>=(j+1)*l||x==j*l+k)d[x]='1';
                    else d[x]='0';
                }
                add_element(d);
            }
        }
    }
    compile_set();
    REP(i,n)st[0][0].pb(i);
    for(int i=1;i<n;i*=2)
    {
        ll lg=__lg(i);
        REP(j,i)
        {
            REP(k,n)d[k]='1';
            for(int tmp:st[lg][j])d[tmp]='0';
            for(int tmp:st[lg][j])
            {
                d[tmp]='1';
                if(check_element(d))
                {
                    st[lg+1][2*j].pb(tmp);
                }
                else st[lg+1][2*j+1].pb(tmp);
                d[tmp]='0';
            }
        }
    }
    //for(int i=1;i<=n;i*=2)REP(j,i)debug(i,__lg(i),j,st[__lg(i)][j]);
    REP(i,n)ans[st[__lg(n)][i][0]]=i;
}

#ifdef brian


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    int ans[n];
    REP(i,n)cin>>p[i];
    restore_permutation(n,896,896,ans);
    debug(cnta,cntc);
    _OUTC(cout,ans,ans+n);
    cout<<endl;
}
#endif // brian
