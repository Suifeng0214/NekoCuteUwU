// merge(0, n); [0, n)
int count = 0;
void merge(int left, int right){
    if (left+1 == right) return;
    int mid = (left + right) / 2;
    merge(left, mid);
    merge(mid, right);
    int i = left, j = mid, k = left;
    while(i < mid || j < right){
        if (i >= mid){
            tmp[k++] = arr[j++];
        }else if (j >= right){
            tmp[k++] = arr[i++];
        }else{
            if (arr[i] <= arr[j]){
                tmp[k++] = arr[i++];
            }else{
                counts += mid-i;
                tmp[k++] = arr[j++];
            }
        }
    }
    for (int i = left; i < right; i++){
        arr[i] = tmp[i];
    }
}