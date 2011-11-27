#include <stdlib.h>
#include <stdio.h>

int a[5000];

int compare(void *a, void *b)
{
        return (*(int*)a-*(int*)b);
}

int binarySearch(int sortedArray[], int first, int last, int key) {
   while (first <= last) {
       int mid = (first + last) / 2;  // compute mid point.
       if (key > sortedArray[mid]) 
           first = mid + 1;  // repeat search in top half.
       else if (key < sortedArray[mid]) 
           last = mid - 1; // repeat search in bottom half.
       else
           return 1;     // found it. return position /////
   }
   return 0;    // failed to find key
}

int main()
{
        int n, i, k, tmp;
        freopen("find.in",  "r", stdin);
        freopen("find.out", "w", stdout);
        scanf("%d %d", &n, &k);
        for(i = 0; i < n; i++) scanf("%d", &a[i]);
        qsort(a, n, sizeof(int), compare);
        for(i = 0; i < k; i++)
        {
            scanf("%d", &tmp);
            if(binarySearch(a, 0, n, tmp))
                printf("YES\n");
            else
                printf("NO\n");
        }
        return 0;
}
