#include<iostream>
#include<vector>
using namespace std;
class DynamicArray {
private:
    int* data;
    int capacity;
    int size;
    int resizecheck;

    
public:
    DynamicArray(int resizecheck = 2)
        : capacity(1), size(0), resizecheck(resizecheck) {
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }
  void insert(int index, int value) {
        if (index < 0 || index > size) {
            throw out_of_range("Index out of bounds");
        }
        if (size == capacity) {
            resize(capacity * resizecheck);
        }
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }
    void delete_i(int index){
         if (index < 0 || index > size) {
            throw out_of_range("Index out of bounds");
        }
        for(int i=index;i<size;i++){
            data[i]=data[i+1];
        }
        size--;
}
     int size_array(){
       return size;
     }
     bool isempty(){
        if (size==0){
            return true;
        }
        return false;
     }
void reverse(int s , int e  ) {
    int temp;
    for (int i = s; i < (s + e) / 2; i++) {
        temp = data[i];
        data[i] = data[e - 1 - i + s];  
        data[e - 1 - i + s] = temp;     
    }
}
int rotate(int k){
  k=k%size;
  reverse(0,size-1);
  reverse(0,k);
  reverse(k,size-1);
}
void append(int val){
    size+=1;
    data[size]=val;

}
void append(int value) {
        if (size == capacity) {
            resize(capacity * resizecheck);
        }
        data[size] = value;
        ++size;
    }

void prepend(int value) {
        insert(0, value);
    }
void merge_two_sorted(int* array1[], int size1, int* array2[], int size2, int* merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (*array1[i] < *array2[j]) {
            merged[k++] = array1[i++];
        } else {
            merged[k++] = array2[j++];
        }
    }

    while (i < size1) {
        merged[k++] = array1[i++];
    }
    while (j < size2) {
        merged[k++] = array2[j++];
    }
}
void interleave_arrays(int* array1, int size1, int* array2, int size2, int* array3) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        array3[k++] = array1[i++];
        array3[k++] = array2[j++];
    }

    while (i < size1) {
        array3[k++] = array1[i++];
    }

    while (j < size2) {
        array3[k++] = array2[j++];
    }
}
    
     void resize(int new_capacity) {
        int* new_data = new int[new_capacity];
        for (int i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }


  
