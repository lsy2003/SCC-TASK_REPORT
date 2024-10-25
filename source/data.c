#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "time.h"
int rd(int x,int y){
	return rand()%(y-x+1)+x;
}
int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	int n=pow(10,(argv[1][0]-'0')),w=pow(10,(argv[2][0]-'0'));
	freopen("data.in","w",stdout);
	printf("%d\n",n);
	for(int i=1;i<=n;i++)printf("%d ",rd(1,w));
	return 0;
}

