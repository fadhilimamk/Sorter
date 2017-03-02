// file: TabelSorter.cpp

#include "TabelSorter.h"
#include <cstdlib>

TabelSorter::TabelSorter(int size):size(size){
  data = new int[size];
  for(long i=0; i<size; i++)
    data[i] = rand();
}

TabelSorter::~TabelSorter(){
  delete[] data;
}

TabelSorter::TabelSorter(const TabelSorter& t):size(t.size){
  data = new int[size];
  for(long i=0; i<size; i++)
    data[i] = t.data[i];
}

TabelSorter& TabelSorter::operator=(const TabelSorter& t){
  if(this != &t){
    for(long i=0; i<size; i++)
      data[i] = t.data[i];
  }else{
      return *this;
  }
}

void TabelSorter::print(){
  for(long i=0; i<size; i++)
    cout << data[i] << " ";
}

ostream& operator<<(ostream& os, const TabelSorter& t){
  os << "";
  for(long i=0; i<t.size; i++)
    os << t.data[i] << endl;
  return os;
}

void TabelSorter::mergeSort(bool isIncrease){
  mergeSortProccess(0,size-1,isIncrease);
}

void TabelSorter::quickSort(bool isIncrease){
  quickSortProcsess(0,size-1,isIncrease);
}

void TabelSorter::mergeSortProccess(long start, long end, bool isIncrease){
  if (start < end){
    long mid = ((end - start) / 2) + start;
    this->mergeSortProccess(start,mid, isIncrease);
    this->mergeSortProccess(mid+1,end, isIncrease);
    // gabungin
    int* temp = new int[end-start+1];
    long i = start, j = mid+1, k = 0;
    while(i <= mid && j <=end){
      if(isIncrease){
        if(data[i] < data[j]){
          temp[k] = data[i];
          i++;
        }else{
          temp[k] = data[j];
          j++;
        }
      }else{
        if(data[i] > data[j]){
          temp[k] = data[i];
          i++;
        }else{
          temp[k] = data[j];
          j++;
        }
      }
      k++;
    }
    while(i<=mid){
      temp[k] = data[i];
      i++;
      k++;
    }
    while(j<=end){
      temp[k] = data[j];
      k++;
      j++;
    }

    i = start; k = 0;
    while(i <= end){
      data[i] = temp[k++];
      i++;
    }
    delete[] temp;
  }
}

void TabelSorter::quickSortProcsess(long start, long end, bool isIncrease){
  if (start < end){
    long mid = ((end - start) / 2) + start;
    int pivot = data[mid];
    // pisahin sesuai pivot
    long i = start, j = end;
    do {
      if(isIncrease){
        while (data[i] < pivot){
          i++;
        }
        while (data[j] > pivot){
          j--;
        }
      }else{
        while (data[i] > pivot){
          i++;
        }
        while (data[j] < pivot){
          j--;
        }
      }
      if(i<=j){
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;

        if (i+1 <= end)
          i++;
        if ( j-1 >= start)
          j--;
      }

    } while(i <= j);
    quickSortProcsess(start, j, isIncrease);
    quickSortProcsess(j+1, end, isIncrease);

  }
}

void TabelSorter::insertionSort(bool isIncrease){
  long j = 0;
  for (long i=0 ; i<size; i++){
    int idxExtreme = i;
    j = i;
    while(j < size){
      if(isIncrease){
        if (data[j] < data[idxExtreme]){
          idxExtreme = j;
        }
      }else{
        if (data[j] > data[idxExtreme]){
          idxExtreme = j;
        }
      }
      j++;
    }
    int temp = data[idxExtreme];
    data[idxExtreme] = data[i];
    data[i] = temp;
  }
}

void TabelSorter::selectionSort(bool isIncrease){
  long j = 1;
  for(long i=1; i < size; i++){
    j = i;
    while(j > 0){
      if (isIncrease){
        if (data[j-1] > data[j]){
          int temp = data[j];
          data[j] = data[j-1];
          data[j-1] = temp;
        }
      }else{
        if (data[j-1] < data[j]){
          int temp = data[j];
          data[j] = data[j-1];
          data[j-1] = temp;
        }
      }
      j--;
    }
  }
}
