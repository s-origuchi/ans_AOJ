#include <iostream>
int count = 0;

void print_array(int a[], int n)
{
  for (int i=0; i<n; i++)
    std::cout << ((i!=0)?" ":"") << a[i];
  std::cout << std::endl;
}

void merge(int a[], int left,int mid, int right)
{
  int n1, n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1],R[n2];

  for (i=0; i < n1; i++)
    L[i] = a[left + i];
  for (i=0; i < n2; i++)
    R[i] = a[mid+i];

  j=i=0;
  for (k=left; k<right; k++)
  {
    if((j==n2  || L[i] <= R[j]) && i!=n1)
    {
      a[k] = L[i];
      i++;
    }else{
      a[k] = R[j];
      j++;
    }
    count ++;
  }
}

void merge_sort(int a[], int left, int right)
{
  int mid=-1;
  if (left + 1 < right)
  {
    mid = (left+right)/2;
    merge_sort(a, left,mid);
    merge_sort(a,mid,right);
    merge(a,left,mid,right);
  }
}


void inputdata(int *n, int **a)
{
  std::cin >> *n;
  *a= new int[*n];
  for(int i=0; i< *n; i++)
    std::cin >> (*a)[i];
}
int main(void)
{
  int *a, n;
  inputdata(&n, &a);
  merge_sort(a, 0, n);

  print_array(a,n);
  std::cout << count <<std::endl;
  delete a;
}

