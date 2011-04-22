#include <stdio.h>
#include <stdlib.h>

#define fabs(a) ((a) < 0) ? (-a) : (a)

typedef struct Point
  {
         float x;
         float y;
  }Point;  

float Square(Point p1, Point p2, Point p3)
{
    return 0.5*(p1.x*p2.y + p1.y*p3.x + p3.y*p2.x - p3.x*p2.y - p3.y*p1.x - p2.x*p1.y);    
}

int main(int argc, char *argv[])
{
  Point p, p1, p2, p3;
  printf("test point:\n");
  scanf("%f%f",&p.x,&p.y);
  printf("others points:\n");
  scanf("%f%f",&p1.x,&p1.y);
  scanf("%f%f",&p2.x,&p2.y);
  scanf("%f%f",&p3.x,&p3.y);
  if (Square(p1,p2,p3)==(fabs(Square(p,p1,p2))+fabs(Square(p,p1,p3))+fabs(Square(p,p2,p3))))
  {
     printf("in\n");
  }
  else
      printf("out\n");
  system("PAUSE");	
  return 0;
}
