using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>

int main()
{
    long long int T,count,i,j,Case=1,low,high,mid;
    scanf("%lld",&T);

    while(T--)
    {
        cin>>count;
        i=ceil(sqrt(count));
        high = i*i;
        low = high-((2*i)-2);
        mid = (high+low)/2;
        if(i%2==0)
        {
            if(count==mid)
            {
                j=i;
            }
            else if(count>mid)
            {
                j = i-(count-mid);
            }
            else
            {
                j=i;
                i=i-(mid-count);
            }
        }
        else
        {
            if(count==mid)
            {
                j=i;
            }
            else if(count>mid)
            {
                j=i;
                i=i-(count-mid);
            }
            else
            {
                j=i-(mid-count);
            }

        }

        cout<<"Case "<<Case++<<": "<<i<<" "<<j<<endl;

    }
    return 0;
}

  /* scanf("%lld",&count);
        sum=1;
        i=1;
        j=1;
        for(m=2;sum<count;m+=2)
        {
            i++;
            sum+=m;
        }
        m-=2;

        low=sum-((i*i)-sum);
        high=i*i;

        if(count<=high&&count>=low)
        {
            if(count==sum)
            {
                j=i;
            }
            else if(count>sum)
            {
                if(i%2==0)
                {
                    j=i-(count-sum);
                }
                else
                {
                    j=i;
                    i=i-(count-sum);
                }
            }
            else
            {
                if(i%2==0)
                {
                    j=i;
                    i=i-(sum-count);

                }
                else
                {
                    j=i-(sum-count);
                }
            }
        }
        else
        {
            i--;
            sum-=m;
            //cout<<sum<<endl;
            //cout<<"dinka"<<endl;
            if(count==sum)
            {
                j=i;
            }
            else if(count>sum)
            {
                if(i%2==0)
                {
                    j=i-(count-sum);
                }
                else
                {
                    j=i;
                    i=i-(count-sum);
                }
            }
            else
            {
                if(i%2==0)
                {
                    j=i;
                    i=i-(sum-count);

                }
                else
                {
                    j=i-(sum-count);
                }
            }
        }





        cout<<"Case "<<Case++<<": "<<i<<" "<<j<<endl;*/

/*for(k=1;sum<count;k+=2)
        {
            sum+=k;
        }

        k-=2;

        if(sum==count)
        {
            if(k==1)
            {
                i=1;
                j=1;
            }
            else
            {
                if((k/2)%2)
                {
                    i=k/2+1;
                    j=1;
                }
                else
                {
                    j=k/2+1;
                    i=1;
                }
            }

        }
        else
        {
            sum-=k;
            if((k/2)%2==0)
            {
                i=(k/2)+1;
                j=1;
                sum++;
                while(sum<count)
                {
                    if(i>j)
                    {
                        j++;
                    }
                    else if(i<=j)
                    {
                        i--;
                    }
                    sum++;
                }

            }
            else
            {

                i=1;
                j=(k/2)+1;
                sum++;
                while(sum<count)
                {
                    if(j>i)
                    {
                        i++;
                    }
                    else if(j<=i)
                    {
                        j--;
                    }
                    sum++;
                }
            }
        }*/


/*while(count>0)
        {
            if(flag==0)
            {
                temp=(j*2)+1;
                while((count>0)&&temp--)
                {
                    if(flag==0)
                    {
                        j++;
                        flag=2;
                    }
                    else if(j>i)
                    {
                        i++;
                    }
                    else if(i>=j)
                    {
                        j--;
                    }
                    count--;
                }
                flag=1;
            }
            else if(flag)
            {
                temp=(i*2)+1;
                while(count>0&&temp--)
                {
                    if(flag==1)
                    {
                        i++;
                        flag=2;
                    }
                    else if(i>j)
                    {
                        j++;
                    }
                    else if(j>=i)
                    {
                        i--;

                    }
                    count--;
                }
                flag=0;
            }
        }*/



