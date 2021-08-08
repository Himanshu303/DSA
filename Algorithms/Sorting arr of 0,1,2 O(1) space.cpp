#include<bits/stdc++.h>
using namespace std;
void sortArr(vector<int> &arr)
{
    int low=0,mid=0;
    int high=arr.size()-1;

    while(mid<=high)
    {
        if(arr[mid]==0) 
          swap(arr[mid++],arr[low++]);
      
        else if(arr[mid]==1) 
          mid++;
      
        else if(arr[mid]==2) 
          swap(arr[mid],arr[high--]);
    }
}
int main()
{
    int n;
    cin>>n;
  
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sortArr(arr);
    for(int i:arr) cout<<i<<" ";
  
    /*
    Input:
    6
    2 2 1 1 0 0

    Output:
    0 0 1 1 2 2
     */
}
