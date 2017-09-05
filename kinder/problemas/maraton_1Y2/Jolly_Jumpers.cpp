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

int main(){
	int i,j,n,tmp;
	int s[50000], ban;
	while(scanf("%d",&n)==1){
		ms(s,0);
		ban= 1;
		tmp = 0;
		loop(i,0,n){
			scanf("%d",&j);
			if(i>0){
				tmp = abs(j-tmp);
				if(s[tmp]) ban =0;
				if(tmp == 0 || tmp > n-1) ban = 0;
			}
			s[tmp]=1;
			tmp = j;
		}
		if(ban) puts("Jolly");
		else puts("Not jolly");
	}
  return 0;
}
