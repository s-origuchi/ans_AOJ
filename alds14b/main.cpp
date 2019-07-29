#include <iostream>


const int SMAX = 200000;

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
int bin_search(int n_src, int *src, int dst)
{
  int fr=0, bk=n_src-1;
  int center;
  if (dst < src[fr] || src[bk] < dst) return -1; 
  
  if (dst == src[fr] ) return fr;
  if (dst == src[bk]) return bk;
  while(true){
    center = (fr+bk +1)/2;

    if (src[ center] == dst)
      return center;

    if (fr == center || center == bk)
      return -1;
    if (src[ center ] > dst )
      bk = center;
    else if (src[ center ] < dst )
      fr = center;
  }

  return -1;
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
    if (bin_search(n_src, src, dst[i]) != -1) 
      flag[i] = true;
  }
  
  int count=0;
  for (int i=0; i<n_dst; i++)
    if (flag[i]) count++;
  std::cout << count <<std::endl;
}

