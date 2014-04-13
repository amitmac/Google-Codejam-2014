#include<cstdio>
int main()
{
	int t,h=1;
	FILE *f1,*f2;
	f1=fopen("C-small-attempt2.in","r");
	f2=fopen("output.txt","w");
	fscanf(f1,"%d",&t);
	while(t--)
	{
		int r,c,m;
		char mines[51][51];
		bool check[51][51]={false};
		fscanf(f1,"%d%d%d",&r,&c,&m);
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				mines[i][j]='.';
		if(r==1 || c==1)
		{
			if(m>r*c-2)
				fprintf(f2,"Case #%d:\nImpossible\n",h);
			else
			{
				mines[0][0]='c';
				for(int i=r-1;i>=0;i--)
					for(int j=c-1;j>=0;j--)
						if(m>0)
						{
							mines[i][j]='*';
							m--;
						}
				fprintf(f2,"Case #%d:\n",h);
				for(int i=0;i<r;i++)
				{
					for(int j=0;j<c;j++)
						fprintf(f2,"%c",mines[i][j]);
					fprintf(f2,"\n");
				}
			}
		}
		else if(m>r*c-4)
			fprintf(f2,"Case #%d:\nImpossible\n",h);
		else
		{			
			mines[r-1][c-1]='c';
			check[r-1][c-1]=true;	check[r-2][c-1]=true;
			check[r-2][c-2]=true;	check[r-1][c-2]=true;
			for(int i=0;i<r;i++)
				for(int j=0;j<c;j++)
					if(!check[i][j] && m>0)
					{
						mines[i][j]='*';
						m--;
					}
			fprintf(f2,"Case #%d:\n",h);
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
					fprintf(f2,"%c",mines[i][j]);
				fprintf(f2,"\n");
			}
		}
		h++;
	}
}