#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define swap(x,y) { x=x^y; y=y^x;  x=x^y; }
#define N 1000007
#define M 2000007
const int inf=0x3f3f3f3f;
int a[N],b[M],n,cnt;
void insert(int x){
	b[++cnt]=x; int i=cnt;
	while(i!=1&&b[i/2]>b[i]){
		swap(b[i],b[i/2]);
		i/=2;
	}
}
void mesh(){
	printf("%d ",b[1]);
	b[1]=b[cnt]; b[cnt]=inf; cnt--;
	int i=1;
	while(b[i]>b[i*2]||b[i]>b[i*2+1]){
		int x=b[i*2]<b[i*2+1]?i*2:i*2+1;
		swap(b[i],b[x]); i=x;
	}
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("bin.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=n;i++)insert(a[i]);
	for(int i=1;i<=n;i++)mesh();
	return 0;
}
