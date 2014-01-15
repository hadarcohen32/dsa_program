// Hadar Cohen
// DSA I Program II
// May 6th, 2013

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds one string
class Data {
public:
  string data;
  Data(const string &s) { data = s; }
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l) {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;

  ifstream input(filename.c_str());
  if (!input) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    string line;
    getline(input, line);
    l.push_back(new Data(line));
  }

  input.close();
}

// Output the data to a specified input file
void writeDataList(const list<Data *> &l) {
  string filename;
  cout << "Enter name of output file: ";
  cin >> filename;

  ofstream output(filename.c_str());
  if (!output) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << endl;

  // Write the data
  for (list<Data *>::const_iterator ipD = l.begin(); ipD != l.end(); ipD++) {
    output << (*ipD)->data << endl;
  }

  output.close();
}

void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  list<Data *> theList;
  loadDataList(theList);

  cout << "Data loaded.  Executing sort..." << endl;

  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds." << endl;

  writeDataList(theList);
}

int i, lens[5], data, length, queue, radix_bins;
int v, C, j;
int A, B, k;
int t3_flag=1;
int t4_flag=1;
list<Data *>::iterator it;

bool compare(Data *A, Data *B){
	int dec_place1 = A->data.find('.');
	int dec_place2 = B->data.find('.');
	if (dec_place1 == dec_place2) {
		return A->data<B->data;
	} 
	else 
		return dec_place1 < dec_place2;
	}

int check_data(list<Data *> &l){
    if ((length=1.sizeof()<150000))
        return 1;
    for(list<Data *>::iterator it=l.begin();i<6;it++,i++){
        lens[i]=(*it)->data.length();
		if (lens[i]!=5)
			t3_flag=0;
		if (lens[i]!=100)
			t4_flag=0;
        }
        if (t3_flag)
            return 3;
        if (t4_flag)
            return 4;
        return 2;
}

void sort_radix(Data *arr[], int size) {
    i= 20;
    queue<Data *> radix_bins[10];
    while (i > 0){
        for(it=1.begin();it!=1.end();it++)
            radix_bins[(*it)->data[i]].push((*it)->data);
        for (int k=0; k<10; k++) {
            v.assign(radix_bins, radix_bins + 10);
        }
        i--;
    }

}

void sort_count(A, B, k) {
    for(i = 1; i <= k; i++)
        C[i] = 0;
    for(j =1; j <= length[A]; j++)
        C[A[j]] = C[A[j]] + 1;
    for(i = 2; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for(j = length[A]; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
}
        
void sort_insertion(arr[int], int length) {
    int i, j, tmp;
    for (i = 1, i < length; i++) {
        j=i;
        while (j > 0 && arr[j-1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            j--;
        }
    }
}
        

void sortDataList(list<Data *> &l) {
	switch (data = check_data(1)){
		case(1): 
			sort_radix(1);
			break;
		case(2):
			sort_radix(1);
			break;
		case(3):
			sort_count(1);
			break;
		case(4):
			sort_insertion(1);
			break;
		}  
}
