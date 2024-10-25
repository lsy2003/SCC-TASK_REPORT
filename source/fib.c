#include "stdio.h"
#define N 1000007
#define M 1000027
const int inf=0x3f3f3f3f;
int hd[N],pre[M],to[M],num;
int d[N],point;
int a[N],n;
int stack[N],cnt;
int get(){
    return cnt?stack[cnt--]:++num;
}
void adde(int x,int y){
    int nm=get();pre[nm]=hd[x];hd[x]=nm;to[nm]=y;
}
void update(int i){
    if(a[d[i]]<a[d[point]])point=i;
}
#define swap(x,y) { x=x^y; y=y^x;  x=x^y; }
int top,deg[N];
int max(int x,int y){
    return x>y?x:y;
}
void insert(int x,int i){
    while(d[i]){
	if(a[d[i]]>a[x])swap(d[i],x);
	adde(d[i],x); deg[d[i]]++;
	x=d[i]; d[i]=0; i++;
    }
    d[i]=x; update(i);
    top=max(top,i);
}
void mesh(){
    printf("%d ",a[d[point]]);
    int x=d[point]; d[point]=0;
    if(point==top)top--;
    for(int i=hd[x];i;i=pre[i]){
	int u=to[i]; 
	insert(u,deg[u]);
    }
    for(int i=hd[x];i;i=pre[i])stack[++cnt]=i;
    for(int i=0;i<=top;i++)update(i);
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("fib.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=inf;
    for(int i=1;i<=n;i++)insert(i,0);
    for(int i=1;i<=n;i++)mesh();
    printf("\n");
    return 0;
}
    

    

