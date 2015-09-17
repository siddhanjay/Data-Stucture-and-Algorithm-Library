#define MAX_N 100000
bool prime[MAX_N+1]={true};

void primes()
{
	forall(i,0,MAX_N-1)
		prime[i]=true;
	int sq=sqrt(MAX_N);
	forall(i,2,sq)
	{
		if(prime[i]==true)
		{
			int flag=0;
			for(int j=i*i;j<=MAX_N;j+=i)
			{
				
				if(prime[j]==true)
				{
					prime[j]=false;
					flag=1;
				}
				
			}
			if(flag==0)break;
		}
	}
}