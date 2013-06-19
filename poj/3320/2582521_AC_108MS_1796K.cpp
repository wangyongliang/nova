//pku 1468 1470 的其他方法
//pku 1084
#include <stdio.h>

 

#define PRIME 99991

 

struct hashnode

{

    int key;

    int num;

    int next;

}a[1000005];

int b[1000005];

int hashl;

 

int hash(int num)

{

    int i;

    i = num % PRIME;

    while(a[i].next != -1){

        if(num > a[a[i].next].key) break;

        else if(num == a[a[i].next].key) return a[i].next;

        i = a[i].next;

    }

    //插入新结点 

    a[hashl].key = num;

    a[hashl].next = -1;

    a[hashl].num = 0;

    a[hashl].next = a[i].next;

    a[i].next = hashl;

    hashl++;

    return hashl - 1;

}

 

int main()

{

    int n, i, tmp, left, ans;

    while(scanf("%d", &n) != EOF){

        for(i = 0;i < PRIME;i++) a[i].next = -1;

        hashl = PRIME;

        left = 0;

        ans = 1;

        scanf("%d", &b[0]);

        tmp = hash(b[0]);

        a[tmp].num++; 

        for(i = 1;i < n;i++){

            scanf("%d", &b[i]);

            tmp = hash(b[i]);

            a[tmp].num++;

            if(a[tmp].num <= 1){

                ans = i - left + 1;

                continue;

            }

            while(1){

                tmp = hash(b[left]);

                if(a[tmp].num <= 1) break;

                a[tmp].num--;

                left++;

            }

            if(ans > i - left + 1) ans = i - left + 1;    

        }

        printf("%d\n", ans);       

    }

    return 0;

}
