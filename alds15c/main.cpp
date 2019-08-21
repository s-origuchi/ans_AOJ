#include <iostream>
#include <cmath>
#include <cstdio>
//#include <list>
#include <initializer_list>
#include <vector>
struct Point {
  double x,y;
};
/*
 * 1.与えられた線分を三等分にして、点3,点5を求める
 * 2.点3を原点に点5を回転させて点4を求める
 */

const double rad60 = M_PI/3;
const double cos60 = std::cos(rad60);
const double sin60 = std::sin(rad60);

Point* koch_curve(const Point p1, const Point p2, Point p[])
{
  Point tp1;
  tp1.x = (p2.x - p1.x)/3;
  tp1.y = (p2.y - p1.y)/3;
  p[0].x = p1.x + tp1.x;
  p[0].y = p1.y + tp1.y;

  p[2].x = p1.x + tp1.x *2;
  p[2].y = p1.y + tp1.y *2;

  p[1].x = p[0].x+ tp1.x * cos60 - tp1.y *sin60;
  p[1].y = p[0].y +tp1.x * sin60 + tp1.y *cos60;

  return p;
}

void koch_curve_r(const std::vector<Point>& ppl, const int depth, const int target)
{
  if (depth > target) return;

  const std::vector<Point>::const_iterator itEnd = ppl.end(); 
  std::vector<Point>::const_iterator it, itp1;

  for(it = itp1 = ppl.begin(), itp1++; itp1 != itEnd; it = itp1, itp1++)
  {
    Point p[3];
    koch_curve(*it, *itp1, p);
    std::initializer_list<Point> tlist = {p[0],p[1],p[2]};
    ppl.insert(itp1, tlist);
  }
  
  koch_curve_r(ppl, depth+1, target);
}

void print_koch_curve(std::vector<Point>& pl)
{
  const std::vector<Point>::const_iterator itEnd = pl.end();
  for(std::vector<Point>::const_iterator it = pl.begin(); it != itEnd; it++)
  {
    std::cout << (*it).x << " "<<(*it).y << std::endl;
  }
}

void init_list(std::vector<Point>& pl)
{
  Point p1=Point{0.0, 0.0}, p2 = Point{100.0, 0};
  pl.push_back(p1);
  pl.push_back(p2);
}

int main(void)
{
  std::vector<Point> pl;
  init_list(pl);
  

  print_koch_curve(pl);

  
}
