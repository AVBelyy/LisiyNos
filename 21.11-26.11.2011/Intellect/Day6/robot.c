#include <stdio.h>
#include <string.h>

char f[101][101];

int main()
{
    char cmd;
    int k = 0;
    int  x = 49,  y = 49;
    int vx =  0, vy =  1;
    freopen("robot.in",  "r", stdin);
    freopen("robot.out", "w", stdout);
    memset(f, 0, 101*101);
    f[x][y] = 1;
    while(!feof(stdin))
    {
        switch(getchar())
        {
            case 'S':
                k++;
                x += vx;
                y += vy;
                if(f[x][y])
                {
                    printf("%d\n", k);
                    return 0;
                }
                f[x][y] = 1;
                break;
            case 'L':
                if     ((vx == -1) && (vy ==  0)) { vy =  1; vx = 0;  }
                else if((vx ==  0) && (vy ==  1)) { vy =  0; vx = 1;  }
                else if((vx ==  1) && (vy ==  0)) { vy = -1; vx = 0;  }
                else if((vx ==  0) && (vy == -1)) { vy =  0; vx = -1; }
                break;
            case 'R':
                if     ((vx == -1) && (vy ==  0)) { vy = -1; vx = 0;  }
                else if((vx ==  0) && (vy == -1)) { vy =  0; vx = 1;  }
                else if((vx ==  1) && (vy ==  0)) { vy =  1; vx = 0;  }
                else if((vx ==  0) && (vy ==  1)) { vy =  0; vx = -1; }
        }
    }
    printf("-1\n");
    return 0;
}
