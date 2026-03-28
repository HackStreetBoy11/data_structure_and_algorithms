class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low>=high)return ;
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        
        int pivotElement = arr[high];
        int larger = 0;
        for(int i=low;i<high;i++){
            if(arr[i]>pivotElement)larger++;
        }
        int pivotPosition = high-larger;
        swap(arr[high],arr[pivotPosition]);
        
        int i=low;
        int j=pivotPosition+1;
        while(i<pivotPosition && j<=high){
            
            while(i<pivotPosition && arr[i]<=pivotElement){
                i++;
            }
            while(j<=high && arr[j]>pivotElement){
                j++;
            }
             if (i < pivotPosition && j <= high) {
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
        }
        return pivotPosition;
    }
};
