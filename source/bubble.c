#include "stdio.h"
#define N 1000007
#define swap(x,y) { x=x^y; y=y^x;  x=x^y; }

int a[N];
int main()
{	
	freopen("data.in","r",stdin);
	freopen("bubble.out","w",stdout);
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
		for(int j=1;j<i;j++)
			if(a[j]>a[j+1])swap(a[j],a[j+1]);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}
