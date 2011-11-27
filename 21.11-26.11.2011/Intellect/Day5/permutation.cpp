#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iterator>

int main()
{
  int n, i;
  freopen("permutations.in",  "r", stdin);
  freopen("permutations.out", "w", stdout);
  scanf("%d", &n);
  int *x = new int[n];
  for(i = 0; i < n; i++)
  {
      x[i] = i+1;
      printf("%d ", i+1);
  }
  printf("\n");
  while (std::next_permutation(x, x + n)) {
    std::copy(x, x + n, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
  }
    return 0;
}
