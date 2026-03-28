class Solution {
  public:
    
    void merge(vector<int>& arr, int l,int mid,int r){
        vector<int> temp(r-l+1,0);
        int i=l;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=r){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i];
                i++;
            }else{
                temp[k++]=arr[j];
                j++;
            }
        }
        while(i<=mid){
            temp[k++]=arr[i];
            i++;
        }
        while(j<=r){
            temp[k++]=arr[j++];
        }
        k=0;
        for(int i=l;i<=r;i++){
            arr[i]=temp[k++];
        }
        return ;
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        
        if(l>=r)return;
        int mid  = l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
        
    }
};
