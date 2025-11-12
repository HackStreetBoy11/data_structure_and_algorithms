class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low<high)
        {
            int pivot =  partition(arr,low,high);
             quickSort(arr,low,pivot-1);
             quickSort(arr,pivot+1,high);
            
        }
        
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        
        // code here
        int pivot_num = arr[high];
        int ind=0;
        for(int i =low;i<high;i++)
        {
            if(arr[i]<pivot_num)
            {
                ind++;
            }
        }
        int pivotIndex= low+ind;
        swap(arr[pivotIndex],arr[high]);
        
        int i =low,j=high;
        while(i<pivotIndex&& j>pivotIndex)
        {
            while(i<pivotIndex && arr[i]<pivot_num)
            {
                i++;
            }
            while(j>pivotIndex && arr[j]>=pivot_num)
            {
                j--;
            }
            if(i<pivotIndex && j>pivotIndex)
            {
                swap(arr[i],arr[j]);
            }
        }
        return pivotIndex;
    }
};
