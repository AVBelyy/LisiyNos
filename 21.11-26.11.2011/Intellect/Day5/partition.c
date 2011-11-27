#include <stdlib.h>
#include <stdio.h>
#define N 40
int main()
{
        freopen("partition.in",  "r", stdin);
        freopen("partition.out", "w", stdout);
        int i,n,m[N],temp;
        for(i=0;i<N;i++) m[i]=1;
 
        scanf("%d", &n);

        temp=n-1; 
        do
        {
                printf("%d=",n);
                for(i=0;i<n;i++)
                {
                       if(m[i]!=0)
                           if(i==n-1 || m[i+1]==0) {
                                printf("%d\n",m[i]);
                                }
                        else printf("%d+",m[i]);
                }
 
                if(m[temp]-1>=m[temp-1]+1 && temp>=1) m[temp]--,m[temp-1]++;
                else{ 
                m[temp-1]+=m[temp];
                m[temp--]=0;
                }
        }while(m[0]!=n);
 
}
