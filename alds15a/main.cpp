#include <iostream>

int anslist[2001];

void inputdata(int *n, int **A, int *q, int **m)
{
  std::cin >> *n;
  *A=new int[*n];

  for(int i=0; i<*n; i++)
    std::cin >> (*A)[i];

  std::cin >> *q;
  *m = new int [*q];
  for(int i=0; i<*q; i++)
    std::cin >> (*m)[i];
}

void calcnum(int n, int A[], int sum, int index)
{
  if (index == n)
  {
    if (0 <= sum && sum <=2000)
    {
      anslist[sum] = 1;

    }
  }else{
    calcnum(n,A,sum+A[index], index+1);
    calcnum(n,A,sum,index+1); 
  }
}

int main(void)
{
  int n, *A, q, *m;
  for(int i =0; i<2001; i++)
    anslist[i] = 0;

  inputdata(&n, &A, &q, &m);
  calcnum(n,A,0,0);

  for(int i = 0; i<q; i++)
    std::cout << ((anslist[m[i]])?"yes":"no") << std::endl;
  

  delete A;
  delete m;

}
