#include <stdio.h>

int ev[1000005];
int heapSize;

int HeapPush(int value)
{
    ev[heapSize] = value;
    int current = heapSize;
    while (current > 0 && ev[current] < ev[(current - 1) / 2])
    {
        int temp = ev[(current - 1) / 2];
        ev[(current - 1) / 2] = ev[current];
        ev[current] = temp;
        current = (current - 1) / 2;
    }
    heapSize = heapSize + 1;
    return 1;
}

int HeapPop()
{
    int ret = ev[0];
    heapSize = heapSize - 1;
    ev[0] = ev[heapSize];
    int current = 0;
    while (current * 2 + 1 < heapSize)
    {
        int child;
        if (current * 2 + 2 == heapSize)
        {
            child = current * 2 + 1;
        }
        else
        {
            child = ev[current * 2 + 1] < ev[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;
        }
        if (ev[current] < ev[child])
        {
            break;
        }
        int temp = ev[current];
        ev[current] = ev[child];
        ev[child] = temp;
        current = child;
    }
    return ret;
}

int getMin()
{
    return ev[0];
}

struct node
{
    int type, val;
    node() {}
} res[1000010];

bool Strcm(char *str1, char *str2)
{
    for(int i=0; ; i++)
    {
        if(str1[i] != str2[i])
            return false;
        if(str1[i] == 0)
            return true;
    }
}

int main()
{
    heapSize = 0;
    int n, x, ridx = 0;
    char kla[20];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", &kla);
        if(Strcm(kla, "insert"))
        {
            scanf("%d", &x);
            HeapPush(x);
            res[ridx].type = 1;
            res[ridx].val = x;
            ridx++;
        }
        else if(Strcm(kla, "removeMin"))
        {
            if(heapSize == 0)
            {
                HeapPush(0);
                res[ridx].type = 1;
                res[ridx].val = 0;
                ridx++;
            }
            HeapPop();
            res[ridx].type = 2;
            ridx++;
        }
        else
        {
            scanf("%d", &x);
            int temp;
            if(heapSize)
            {
                while(heapSize)
                {
                    temp = getMin();
                    if(temp == x)
                    {
                        res[ridx].type = 3;
                        res[ridx].val = x;
                        ridx++;
                        break;
                    }
                    else if(temp > x)
                    {
                        HeapPush(x);
                        res[ridx].type = 1;
                        res[ridx].val = x;
                        ridx++;
                        res[ridx].type = 3;
                        res[ridx].val = x;
                        ridx++;
                        break;
                    }
                    else
                    {
                        HeapPop();
                        res[ridx].type = 2;
                        ridx++;
                        if(heapSize == 0)
                        {
                            res[ridx].type = 1;
                            res[ridx].val = x;
                            ridx++;
                            res[ridx].type = 3;
                            res[ridx].val = x;
                            ridx++;
                            HeapPush(x);
                            break;
                        }
                    }
                }
            }
            else
            {
                res[ridx].type = 1;
                res[ridx].val = x;
                ridx++;
                res[ridx].type = 3;
                res[ridx].val = x;
                ridx++;
                HeapPush(x);
            }
        }
    }
    printf("%d\n", ridx);
    for(int i=0; i<ridx; i++)
    {
        if(res[i].type == 2)
        {
            printf("removeMin\n");
        }
        else if(res[i].type == 1)
        {
            printf("insert %d\n", res[i].val);
        }
        else if(res[i].type == 3)
        {
            printf("getMin %d\n", res[i].val);
        }
    }
}