
void concat(int a[] , int n , int b[] , int m , int c[], int &k){

  int i = 0 , j = 0 ; 
  k = 0 ; 
  while (i < n && j < m) {
    if(a[i] <= b[j]){
      c[k] = a[i] ;
      i++;
    }
    else{
      c[k] = b[j] ;
      j++;
    }
    k++;
  }
  while (i < n) {
    c[k] = a[i] ;
    i++;
    k++;
  }
  while (j < m) {
    c[k] = b[j] ;
    j++;
    k++;
  }
}