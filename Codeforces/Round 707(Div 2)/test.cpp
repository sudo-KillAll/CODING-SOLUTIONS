#include <bits/stdc++.h>
using namespace std;
#define int               long  long
#define float             long double
#define vi                vector <int>
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define irep(i,n,b)       for(int i=n;i>=b;i--)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
 
signed main(){
    int t = 1;
    cin >> t;
 
    while(t--){
        int n;
        cin >> n;
        vi a,b;
        rep(i,0,n){
            int x,y;
            cin >> x >> y;
            a.pb(x);
            b.pb(y);
        } 
        vi tm;
        rep(i,0,n){
            int x;
            cin >> x;
            tm.pb(x);
 
        }
        int time = 0;
        if(n == 1){
            cout << a[0] + tm[0]<<"\n";
            //you didn't put '\n' ;)
        }
        else{
            rep(i,0,n){
                if(i == 0){
                    
                    //time = max(b[i],tm[i] + a[i] + (b[i]-a[i]+1)/2);
                    time += a[i]+tm[i];
                }
                else if(i == n-1){
                    cout << time + a[i] - b[i-1] + tm[i] << endl;
                    break;
                }
                else{
                    //int dep = max(time + a[i] - b[i-1] + tm[i] + (b[i]-a[i]+1)/2,b[i]);
                    time+=a[i]-b[i-1]+tm[i];
                }
                int dep = max(time+(b[i]-a[i]+1)/2,b[i]);
                time  = dep;
            }
        }
        
 
 
    }
 
    return 0;
        
        
        
}