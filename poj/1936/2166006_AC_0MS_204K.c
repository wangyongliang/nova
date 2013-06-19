#include <stdio.h>
#define N 100000

int main()
{
    char s[N], t[N];
    int i, index;

    while (EOF != scanf("%s%s", s, t))
    {
        index = 0;
        for (i = 0; t[i] != '\0'; i++)
        {
            if (s[index] == t[i])
            {
                index++;
                if (s[index] == '\0')
                {
                    printf("Yes\n");
                    break;
                }
            }
        }
        if (t[i] == '\0')
            printf("No\n");
    }

    return 0;
}
