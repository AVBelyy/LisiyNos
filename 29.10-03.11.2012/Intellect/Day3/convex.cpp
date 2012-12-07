#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define Noel_Wermillion "convex."

using namespace std;
struct point
{
    int x, y;

};
istream& operator >> (istream& x,point& e)
{
    x >> e.x >> e.y;
    return x;
}
ostream& operator << (ostream& x,point e)
{
    x << e.x << " " << e.y << endl;
    return x;
}
vector <point> a;

bool cmp (const point& a, const point& b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int orient (point a,point b,point c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

int main()
{
    freopen(Noel_Wermillion"in","r",stdin);
    freopen(Noel_Wermillion"out","w",stdout);
    int n;
    cin >> n;
    point w;
    for (int i = 0;i<n;i++)
     {
         cin >> w;
         a.push_back(w);
     }
     sort(a.begin(),a.end(),cmp);
     point p1 = a[0], p2 = a.back();
     vector <point> up,down;
     up.push_back(p1);
     down.push_back(p1);
     size_t length = a.size();
     for (size_t i = 1;i<length; ++i)
      {
          if (i == a.size()-1 || orient(p1,a[i],p2) < 0)
            {
                while (up.size() > 1 && orient(up[up.size()-2],up[up.size()-1],a[i]) >= 0)
                up.pop_back();
                up.push_back(a[i]);
            }
          if (i == a.size()-1 || orient(p1,a[i],p2) > 0)
           {
                while (down.size()>1 && orient(down[down.size()-2],down[down.size()-1],a[i]) <= 0)
                down.pop_back();
                down.push_back(a[i]);
           }
      }
     for (size_t i = down.size()-2;i>0;--i)
        up.push_back(down[i]);
     cout << up.size() << endl;
     for (size_t i = 0;i<up.size();++i)
       cout << up[i];

    return 0;
}