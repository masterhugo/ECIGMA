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

char mat[1000][1000];
char mat2[1000][1000];

int n,m;

int match(){
	int res = 0, i,j,k,l,cont;
	loop(i,0,n)
		loop(j,0,n)
			if(i+m<=n && j+m<=n){
				cont=0;
				loop(k,0,m)
					loop(l,0,m)
						if(mat[i+k][j+l] == mat2[k][l]) cont++;
				if(cont == upA(m)) res++;
			}
	return res;
}

void rote(){
	char tmp[1000][1000];
	int i,j;
	loop(i,0,m)
		loop(j,0,m)
			tmp[i][j]=mat2[m-j-1][i];
	loop(i,0,m)
		loop(j,0,m)
			mat2[i][j]=tmp[i][j];
}

int main(){
	int i,j;
	char c;
	scanf("%d %d",&n, &m);
	while(n!= 0 || m!=0){
		getchar();
		ms(mat,0);
		ms(mat2,0);
		loop(i,0,n){
			loop(j,0,n){
				scanf("%c",&c);
				mat[i][j]=c;
			}
			getchar();
		}
		loop(i,0,m){
			loop(j,0,m){
				scanf("%c",&c);
				mat2[i][j]=c;
			}
			getchar();
		}
		loop(i,0,4){
			if(i) putchar(' ');
			printf("%d",match());
			rote();
		}
		puts("");
		scanf("%d %d",&n, &m);
	}

  return 0;
}