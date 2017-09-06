#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)
#define itloop(i,a) for(i=a.begin();i!=a.end();i++)
#define ms(a,c)    memset(a,c,sizeof(a))
#define READ(file)  freopen(file, "r", stdin)
#define WRITE(file) freopen(file, "w", stdout)
#define pb(a)    push_back(a)
#define pf(a)    push_front(a)
#define tup(a,b) make_pair(a,b)
#define popb()   pop_back()
#define popf()   pop_front()
#define X        first
#define Y        second
#define LIM      100
#define INF      1000000010
#define SZ       1000005
#define upA(a)   a*a
#define base     10000
#define EPS      1e-9
#define LSOne(i) (i&(-i))

using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef deque<int> di;
typedef deque<ii> dii;
typedef di::iterator dit;
typedef vector<int> vi;
typedef set<int> si;
typedef set<large> sl;
typedef complex<double> im;
typedef vector<char*> vs;
typedef vector<large> bigint;

enum{L=0,R};

dii c1,c2;

int main(){
	int casos,n,t,m,i,x;
	char tmp[50];
	scanf("%d",&casos);
	while(casos--){
		c1.clear();c2.clear();
		scanf("%d %d %d",&n,&t,&m);
		loop(i,0,m){
			scanf("%d %s",&x,tmp);
			if(tmp[0]=='l') c1.pb(ii(i,x));
			else c2.pb(ii(i,x));
		}
		int tiempo=0,pos=0,mc;
		int posi[m];
		while(!c1.empty() || !c2.empty()){
			mc = INF;
			if(!c1.empty()) mc = c1.front().Y;
			if(!c2.empty()) mc = min(mc, c2.front().Y);
			tiempo = max(tiempo, mc);
			loop(i,0,n){
				if(!pos && !c1.empty() && c1.front().Y<=tiempo) posi[c1.front().X] = tiempo+t, c1.popf();
				else if(pos && !c2.empty() && c2.front().Y<=tiempo) posi[c2.front().X] = tiempo+t, c2.popf();
			}
			pos=1-pos;
			tiempo+=t;
		}
		loop(i,0,m) printf("%d\n",posi[i]);
		if(casos) puts("");
	}
  return 0;
}