#include <string>
#include <iostream>

const unsigned int JISHOMAX=20000000;

int array(char data)
{
  data -= 0x40;
  if (data == 1) return 1;
  if (data == 3) return 2;
  if (data == 7) return 3;
  return 4;
}

int get_hashkey(char *data)
{
  int dig = 1, i = 0, sum=-1;
  for (i=0; data[i] != '\0';i++)
  {
    sum += array(data[i])*dig;
    dig *= 4;
  }

  return sum; 
}


int main()
{
  char *jisho = new char[JISHOMAX];

  int n;
  std::cin >> n;

  for (int i=0; i<n; i++)
  {
    char order[7], mes[13];
    std::cin >>order >> mes;
    
    if (order[0] == 'i') jisho[get_hashkey(mes)] = 'Y';
    else 
    {
      if (jisho[get_hashkey(mes)] == 'Y')
        std::cout <<"yes"<<std::endl;
      else
        std::cout <<"yes"<<std::endl;

    }
  }
}

