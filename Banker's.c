#include<stdio.h>

int main()
{
    int n1,n2;
    printf("Enter number of processes:   ");
    scanf("%d",&n1);
    printf("Enter number of resources:   ");
    scanf("%d",&n2);
    int available[n2],allocation[n1][n2],max[n1][n2];
    printf("Enter currently available resources:  \n");
    for(int i=0;i<n2;++i)
    {
        scanf("%d",&available[i]);
    }
    printf("Enter current allocation matrix:  \n");
    for(int i = 0;i<n1;++i)
    {
        for(int j = 0;j<n2;++j)
        {
            scanf("%d",&allocation[i][j]);
        }
    }
    printf("Enter Maximum need matrix:  \n");
    for(int i = 0;i<n1;++i)
    {
        for(int j = 0;j<n2;++j)
        {
            scanf("%d",&max[i][j]);
        }
    }
    printf("The current needs matrix is:  \n");
    for(int i = 0;i<n1;++i)
    {
        for(int j = 0;j<n2;++j)
        {
            printf("%d  ",(max[i][j] - allocation[i][j]));
        }
        printf("\n");
    }

    int count = n1;
    int status[n1],res[n1];
    for(int i =0;i<n1;++i)
    {
        status[i] = 0;
    }
    int safe = 1,flag=0,c=0;

    while(count!=0)
    {
        for(int i =0;i<n1;++i)
        {
            if(status[i] == 0)
            {
                flag = 1;
                for(int j =0;j<n2;++j)
                {
                    if(max[i][j] - allocation[i][j] > available[j])
                    {
                        flag = 0;
                    }
                }
                if(flag == 1)
                {
                    for(int j =0;j<n2;++j)
                    {
                        available[j]+=allocation[i][j];
                    }
                    status[i] = 1;
                    count--;
                    res[c] = i+1;
                    ++c;
                }
            }
        }
    }
    for(int i =0;i<n1;++i)
    {
        if(status[i] == 0)
        safe = 0;
        else
        safe=1;
    }
    if(safe)
    {
        printf("Safe state is:  \n");
        for(int i =0;i<n1;++i)
        {
            if(i==(n1-1))
            printf("P%d",res[i]);
            else
            printf("P%d->",res[i]);

        }
    }
    else
        printf("System is not in safe state!!");
    return 0;
}
