#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int t,n=1;
	FILE *f1,*f2;
    f1=fopen("D-large.in","r");
    f2=fopen("output.txt","w");
	fscanf(f1,"%d",&t);
	while(t--)
    {
		int N,dwar=0,war=0;
		double ken[1001],naomi[1001];

        fscanf(f1,"%d",&N);
        for(int i=0;i<N;i++)
            fscanf(f1,"%lf",&naomi[i]);
        for(int i=0;i<N;i++)
            fscanf(f1,"%lf",&ken[i]);
        
		sort(naomi,naomi+N);
        sort(ken,ken+N);
		
		for(int i=0,j=0;j<N;j++)
            if(ken[j] > naomi[i])
            {
				war++;	
				i++;
			}
        for(int i=0,j=0;i<N;i++)
            if(naomi[i] > ken[j])
            {
				dwar++;	
				j++;
			}
		
		fprintf(f2,"Case #%d: %d %d\n",n,dwar,N-war);
		n++;
    }
	return 0;
}