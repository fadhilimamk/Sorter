// file : TabelSorter.h
#include <iostream>
using namespace std;

class TabelSorter{
public:
  // Konstruktor TabelSorter
  // Membuat tabel dengan elemen sebanyak size dan diisi dengan bilangan acak
  TabelSorter(int);
  // CopyConstructor
  // Memastikan tidak terjadi bitwise copy pada data
  TabelSorter(const TabelSorter&);
  // Destruktor TabelSorter
  // Melepas memori data yang telah dialokasi pada konstruktor
  ~TabelSorter();
  // Operator Overloading
  // Memastikan tidak terjadi bitwise copy pada data
  TabelSorter& operator=(const TabelSorter&);
  // Prosedur untuk mencetak isi TabelSorter
  void print();
  // Prosedur untuk mencetak isi TabelSorter
  friend ostream& operator<<(ostream&, const TabelSorter&);
  // Prosedur untuk mengurutkan data menggunakan mergesort
  void mergeSort(bool);
  // Prosedur untuk mengurutkan data menggunakan quicksort
  void quickSort(bool);
  // Prosedur untuk mengurutkan data menggunakan selectionsort
  void selectionSort(bool);
  // Prosedur untuk mengurutkan data menggunakan insertionsort
  void insertionSort(bool);

private:
  // Prosedur rekursif untuk mengurutkan data menggunakan mergeSort
  void mergeSortProccess(long, long, bool);
  // Prosedur rekursif untuk mengurutkan data menggunakan quickSort
  void quickSortProcsess(long, long, bool);

  const int size;
  int* data;
};
