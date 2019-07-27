#include <iostream>


const int SMAX = 20000;

void input_data(int *src, int *n_src, int *dst, int *n_dst)
{
  std::cin >> *n_src;
  for (int i =0; i < *n_src; i++)
    std::cin >> src[i];

  std::cin >> *n_dst;
  for (int i=0; i<*n_dst; i++)
    std::cin >> dst[i];

  return;
}

//line search
//配列を探索　見つかったらindex, 見つからなかったら-1を返す。
int line_search(int n_src, int *src, int dst)
{
  int index = -1;
  for(int i=0; i<n_src; i++)
  {
    if(src[i] == dst)
    {
      index = i;
      break;
    }
  }
  return index;
}
int main()
{
  int n_src, src[SMAX];
  int n_dst, dst[SMAX];

  input_data(src, &n_src, dst, &n_dst);

  //dstの配列を一個ずつsrc内に無いか、を確認する
  bool flag[n_dst];
  for (int i=0; i<n_dst; i++)
  {
    flag[i] = false;
    if (line_search(n_src, src, dst[i]) != -1) flag[i] = true;
  }
  
  int count=0;
  for (int i=0; i<n_dst; i++)
    if (flag[i]) count++;
  std::cout << count <<std::endl;
}

