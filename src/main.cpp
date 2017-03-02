// file : main.cpp
#include <iostream>
#include <ctime>
#include "TabelSorter.h"
using namespace std;

int main(){
  long size;
  cout << "Please input number of data to be sorted : ";
  cin >> size;
  TabelSorter reference(size);
  TabelSorter tabel1 = reference;
  TabelSorter tabel2 = reference;
  TabelSorter tabel3 = reference;
  TabelSorter tabel4 = reference;
  clock_t t_start;
  clock_t t_end;
  double t_duration;


  // BEGIN testing mergeSort -------------------------------------------
  t_start = clock();
  tabel1.mergeSort(false);
  t_end = clock();

  t_duration = (double) ((double)t_end-(double)t_start) / CLOCKS_PER_SEC * 1000.0;
  cout  << endl
        << "Merge Sort duration: "
        << t_duration
        << " ms"
        << endl;
  // END testing mergeSort ---------------------------------------------

  // BEGIN testing insertionSort ---------------------------------------
  t_start = clock();
  tabel3.insertionSort(false);
  t_end = clock();

  t_duration = (double) (t_end-t_start) / CLOCKS_PER_SEC * 1000.0;
  cout  << endl
  << "Insertion Sort duration: "
  << t_duration
  << " ms"
  << endl;
  // END testing insertionSort -----------------------------------------

  // BEGIN testing quickSort -------------------------------------------
  t_start = clock();
  tabel2.quickSort(false);
  t_end = clock();

  t_duration = (double) (t_end-t_start) / CLOCKS_PER_SEC * 1000.0;
  cout  << endl
        << "Quick Sort duration: "
        << t_duration
        << " ms"
        << endl;
  // END testing quickSort ---------------------------------------------

  // BEGIN testing selectionSort ---------------------------------------
  t_start = clock();
  tabel4.selectionSort(false);
  t_end = clock();

  t_duration = (double) (t_end-t_start) / CLOCKS_PER_SEC * 1000.0;
  cout  << endl
        << "Selection Sort duration: "
        << t_duration
        << " ms"
        << endl;
  // // END testing selectionSort -----------------------------------------

  return 0;
}
