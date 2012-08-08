#include <stdio.h>
#include <math.h>

typedef struct Point
{
    float x, y;
} Point;

float Square(Point p1, Point p2, Point p3)
{
    return 0.5*(p1.x*p2.y + p1.y*p3.x + p3.y*p2.x - p3.x*p2.y - p3.y*p1.x - p2.x*p1.y);
}

int main()
{
    Point X, a, b, c;
    float d, x, y;
    float ax, bx, cx;
    freopen("triangle.in", "r", stdin);
    freopen("triangle.out", "w", stdout);
    scanf("%f%f%f", &d, &x, &y);
    X.x = x; X.y = y;
    a.x = 0; a.y = 0;
    b.x = d; b.y = 0;
    c.x = 0; c.y = d;
    if(Square(a, b, c) == (fabs(Square(X, a, b))+fabs(Square(X, a, c))+fabs(Square(X, b, c))))
    {
        printf("0\n");
    } else {
        ax = sqrt(pow(x, 2)+pow(y, 2));
        bx = sqrt(pow(x-d, 2)+pow(y, 2));
        cx = sqrt(pow(x, 2)+pow(y-d, 2));
             if((ax <= bx) && (ax <= cx)) printf("1\n");
        else if((bx <= ax) && (bx <= cx)) printf("2\n");
        else if((cx <= ax) && (cx <= bx)) printf("3\n");
    }
    return 0;
}
