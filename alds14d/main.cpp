#include <iostream>


long *getinput(long *n, long *k)
{
  std::cin >> *n >> *k;
  long *w = new long[(*n)];
  for (int i=0; i<*n; i++)
    std::cin >> w[i];

  return w;
}

bool check_track_count(long w[], long n, long target, long k)
{
  long tmpw=w[0], count=1;
  for(int i=1; i<n; i++)
  {
    if (w[i] > target) return false;
    if (w[i] + tmpw <= target)
    {
      tmpw += w[i];
    }else{
      tmpw = w[i];
      count ++;
    }
  }
  if (count > k) return 1;//�ȥ�å��������¿�� -> �Ѻ��̤�­��ʤ�
  if (count < k) return -1;//�ȥ�å�����������ʤ� -> �Ѻ���¿����

  if (tmpw > k) return -1;
  return 0;
}

long sum (long w[], long n)
{
  long s =0;
  for(int i=0; i<n; i++) s += w[i];
  return s;
}

int main() 
{
  long n, k, *w;
  long high;
  long low;
  w = getinput(&n, &k);

  high = 2*sum(w,n)/k;
  low = sum(w,n)/(k+1);
  do{
    long mid = (high + low)/2;
    int tcheck = check_track_count(w, n,mid,k);
    std::cout << "high:"<<high<<",low:"<<low<<
                 ",mid:"<< mid<<",tcount"<<tcheck <<std::endl;
    if (tcheck > 0) //�ȥ�å����Ѻ��̤�¿����
      high = mid;
    else if (tcheck == -1) //�ȥ�å����Ѻ��̤�­��ʤ�
      low = mid ;

    if (high - low == 1){
      low++;
      continue;
    }
  }
  while (high != low);
  std::cout << high << std::endl;

  delete w;
}
