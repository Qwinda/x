#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void bsort(int*, int);
bool is_set(const int*, int, int);



int main(void) {
     int i, n, m, k;
     int a[32], b[32], c[32];

     cout << "enter array size A: ";
     cin  >> n;
     cout << "enter elements: ";
     for(i = 0; i < n; i++)
            cin >> a[i];
     cout << endl;

     cout << "enter array size B: ";
     cin  >> m;
     cout << "enter elements: ";
     for(i = 0; i < m; i++)
            cin >> b[i];
     cout << endl << endl;
     cin.ignore();

    
     bsort(b, m);  
     for(k = i = 0; i < n; i++) {
            if(! is_set(b, m, a[i])) 
                   c[k++] = a[i]; 
     }

     
     bsort(c, k);
     cout << "print array C: ";
     for(i = 0; i < k; i++)
            cout << c[i] << ' ';
     cin.get();
     return 0;
}




void bsort(int* arr, int sz) {
     bool is = true;
     int  tmp;
     while(is) {
           is = false;
           for(int i = 0; i < (sz - 1); i++) {
                 if(arr[i] > arr[i + 1]) {
                        tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        is  = true;
                 }
           }
     }
}




bool is_set(const int* arr, int sz, int val) {
      if((val < *arr) || (val > arr[sz-1]))
            return false;
      int m, l, f;

      f = 0;
      l = sz;
      while(f < l) {
           m = (f + l) >> 1;
           if(arr[m] >= val)
                  l = m;
           else
                  f = ++m;
      }
      return (arr[m] == val);
}