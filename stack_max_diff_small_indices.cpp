//geeks
int findMaxDiff(int A[], int n)
{
  //Your code here
  stack<int > lstack,rstack;
  int l[n];
  int r[n];
  for (int i=0;i<n;i++)
  {
      while (!lstack.empty() && A[i]<=lstack.top())
                    lstack.pop();
                    
        if (lstack.empty()) l[i]=0;
        else l[i]=lstack.top();
        lstack.push(A[i]);
  }
   for (int i=n-1;i>=0;i--)
  {
      while (!rstack.empty() && A[i]<=rstack.top())
                    rstack.pop();
                    
        if (rstack.empty()) r[i]=0;
        else r[i]=rstack.top();
        rstack.push(A[i]);
  }
  int ans=INT_MIN;
  for (int i=0;i<n;i++)
  {
        ans=max(abs(l[i]-r[i]),ans);   
  }
  return ans;
}
