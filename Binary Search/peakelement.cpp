//geeks
int peak(int arr[], int n)
{
   int left=0,right=n-1;
   int mid;
   while (left<=right)
   {
       mid=(left+right)/2;
       if (mid==0 && arr[mid]>=arr[mid+1])
                return mid;
        if  (mid==n-1 && arr[mid]>=arr[mid-1])
                return mid;
        if (arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1])
                return mid;
                
        if  (arr[mid]<arr[mid-1])
                right=mid-1;
        else if (arr[mid]<arr[mid+1])
                left=mid+1;
   }
   
}
