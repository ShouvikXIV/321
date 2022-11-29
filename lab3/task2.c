#include <stdio.h>
void perfect_number(int s,int e)
{
  for (s; s < e; s++)
  {
    int i = 1;
    int n = s;
    int sum = 0;
    for(i;i<n;i++)
    {
        if(s%i==0)
        {
            sum+=i;
        }
    }
    if(sum==s)
    {
        printf("%d\n",sum);
    }
  }
}
int main() {
  int s;
  int e;
  scanf("%d",&s);
  scanf("%d",&e);

  perfect_number(s,e);
    
  return 0;
} 

