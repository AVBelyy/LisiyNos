#include <stdio.h>
#include <stdlib.h>
 
long long  _mergeSort(long long arr[], long long temp[], long long left, long long right);
long long merge(long long arr[], long long temp[], long long left, long long mid, long long right);
 
long long mergeSort(long long arr[], long long array_size)
{
    long long *temp = (long long *)malloc(sizeof(long long)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
 
long long _mergeSort(long long arr[], long long temp[], long long left, long long right)
{
  long long mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
 
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
 
long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
  long long i, j, k;
  long long inv_count = 0;
 
  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
    inv_count = inv_count + (mid - i);
    }
  }
 
  while (i <= mid - 1)
    temp[k++] = arr[i++];
 
  while (j <= right)
    temp[k++] = arr[j++];
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
 
  return inv_count;
}
 
long long a[300000];
int main(int argv, char** args)
{
    long long n, i;
    freopen("inversions.in",  "r", stdin);
    freopen("inversions.out", "w", stdout);
    scanf("%I64d", &n);
    for(i = 0; i < n; i++) scanf("%I64d", &a[i]);
    printf("%I64d\n", mergeSort(a, n));
    return 0;
}
