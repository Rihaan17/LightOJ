#include<stdio.h>

int main()
{
    long long int n;
    int t,Case=1;
    char str[10];
    scanf("%d",&t);

    while(t--)
    {
        scanf("%lld %s",&n,str);

        if(str[0]=='A')
        {
            if(n%3==1)
                printf("Case %d: Bob\n",Case++);
            else
                printf("Case %d: Alice\n",Case++);
        }

        else
        {
            if(n%3==0)
                printf("Case %d: Alice\n",Case++);
            else
                printf("Case %d: Bob\n",Case++);
        }
    }

    return 0;
}
