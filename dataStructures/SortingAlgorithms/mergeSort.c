/* C ile Merge Sort */
#include<stdlib.h> 
#include<stdio.h> 
   
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
   
    /* L ve R adında iki adet boş dizi oluştur */
    int L[n1], R[n2]; 
   
    /* Veriyi L ve R dizilerinde sakla */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
   
    /* Birleşmiş olan L[] ve R[] dizilerini tekrar arr[] dizisine atayın */
    i = 0; // İlk alt dizinin ilk dizini 
    j = 0; // İkinci alt dizinin ilk dizini
    k = l; // Birleştirilmiş dizinin ilk dizini
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
   
    /* Kalan herhangi bir L[] dizisi varsa , kopyalayın */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
   
    /* Kalan herhangi bir R[] dizisi varsa , kopyalayın */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
   
/* Sıralanacak arr[] dizisinin sol dizisi L[] sağ dizisi R[]'dir */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
         
        int m = l+(r-l)/2; 
   
        // Birinci ve ikinci yarıları sırala
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
   
        merge(arr, l, m, r); 
    } 
} 
   
 
/* Diziyi ekrana bastır */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
   
/* Programı test etmek için main fonksiyon */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
   
    printf("Verilen Dizi : \n"); 
    printArray(arr, arr_size); 
   
    mergeSort(arr, 0, arr_size - 1); 
   
    printf("\nSıralanmış Dizi :  \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 