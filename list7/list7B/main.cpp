
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

#define N 20

int prime[N * 2];

int ans[N];
int visited[N];
int n, flag;


void sieveofe(int p[], int n)
{
    int i, j;

    p[0] = 0;
    p[1] = 0;
    p[2] = 1;


    for(i=3; i<n; i++) {
        p[i++] = 1;
        p[i] = 0;
    }
    int max = sqrt(n);
    for(i=3; i<=max; i++){
        if(p[i]) {
            for(j=i+i; j<=n; j+=i)
                p[j]=0;
        }
    }
}

void print_result()
{
    int i;

    for(i=1; i<=n; i++) {
        if(i != 1)
            printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}

void dfs(int count)
{
    int i;

    if(count == n) {
        if(prime[ans[count] + ans[1]])
            print_result();
    } else {
        for(i=2; i<=n; i++)
            if(!visited[i] && prime[i + ans[count]]) {
                ans[count + 1] = i;
                visited[i] = 1;
                dfs(count + 1);
                visited[i] = 0;
            }
    }
}

int main(void)
{
    sieveofe(prime, N * 2 -1);

    int caseno=0;

    while(~scanf("%d", &n)) {

        memset(visited, 0, sizeof(visited));

        if(caseno == 0 ){}
        else{printf("\n");}

        printf("Case %d:\n",++caseno);


        ans[1] = 1;
        visited[1] = 1;
        flag = 1;
        dfs(1);


    }

    return 0;
}