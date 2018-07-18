void swap (int &a,int &b)
{
  int temp=a;
  a=b;
  b=temp;
}
int  partition(int input[],int si,int ei)
{
  int  SmallElements=0,pivot=input[si];


  //Counr no of elements smaller than pivot
  for (int i=si;i<=ei;i++)
  {
    if (pivot>input[i]) SmallElements++;
  }

  //Position(key) of pivot is found
  int key=si+SmallElements;
  swap(input[si],input[key]); //Place pivot correctly

  int i=si,j=ei;
  while (i!=key && j!=key){ //While any reaches pivot position
  if (input[i]<pivot) i++;
  else if (input[j]>=pivot) j--;
  else {
    swap(input[i++],input[j--]); //If  a[i] and a[j] both wrong swap
  }
  }
  return key;


}

void quicksort(int input[],int si,int ei)
{
  if (si>=ei) return ;

  int pivot=partition(input,si,ei);
  quicksort(input,si,pivot-1);
  quicksort(input,pivot+1,ei);
}

void quickSort(int input[], int size) {

  int si=0,ei=size-1;
  quicksort(input,si,ei);
}
