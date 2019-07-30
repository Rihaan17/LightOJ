using namespace std;

#include<iostream>
#include<cmath>
#include<cstdio>

int main()
{
    double pi=(2*acos(0.0)),r;
    int T,Case=1;
    cin>>T;

    while(T--)
    {
        scanf("%lf",&r);
        printf("Case %d: %.2lf\n",Case++,((4.0*r*r)-(r*r*pi)));
    }
    return 0;
}
