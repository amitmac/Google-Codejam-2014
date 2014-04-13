#include<cstdio>
using namespace std;
int main()
{
	int t,h=1;
	FILE *f1,*f2;
    f1=fopen("A-small-attempt0.in","r");
    f2=fopen("output.txt","w");
    fscanf(f1,"%d\n",&t);
	while(t--)
	{
		int x,a[4][4],b[16]={0},n1=0,n2=0,ans;
		bool flag=false;
		fscanf(f1,"%d",&x);
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				fscanf(f1,"%d",&a[i][j]);
				if(x-1==i)
					b[a[i][j]-1]++;
			}
		fscanf(f1,"%d",&x);
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				fscanf(f1,"%d",&a[i][j]);
				if(x-1==i)
					b[a[i][j]-1]++;
			}
		for(int i=0;i<16;i++)
			if(b[i]==1)
				n1++;
			else if(b[i]==2)
			{
				ans=i+1;
				n2++;
			}
		if(n1==8)
			fprintf(f2,"Case #%d: Volunteer cheated!\n",h);
		else if(n2>=2)
			fprintf(f2,"Case #%d: Bad magician!\n",h);
		else
			fprintf(f2,"Case #%d: %d\n",h,ans);
		h++;
	}
	return 0;
}