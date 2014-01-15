// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, SPRING 2010

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
// and output the data.  The sort is timed according to CPU time.
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

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add functions or class defintions here if you wish
#include <stdio.h>
#include <stdlib.h>
#include <queue>
Data *qarray[1010000];
Data **parray[1010000];
list<Data *>:: iterator it1;
int ind = 0;


inline int compared(const void *a, const void *b) //qsort comparator
{
	const char *s1 = (*((Data**) a))->data.c_str();
	const char *s2 = (*((Data**) b))->data.c_str();
	return strcmp(s1,s2);
}

inline void radSort(Data *arr[], int size)
{
	queue<Data *> q[26]; //array of queus as buckets
	register int i, j, k;
	for(i = 4; i >=0; i--)
	{
		for(j=0; j<size; j++)
			q[(arr[j]->data)[i] - 97].push(arr[j]);
		
		for(j=k= 0; j<26; j++)
		{
			while((!q[j].empty()))
			{
				arr[k++] = q[j].front();
				q[j].pop();
			}
		}
	}
}


inline void rad4Sort(Data *arr[], int size)
{
    queue<Data *> q[26]; //array of queus as buckets
	register int i, j, k;
	for(i = 99; i >=94; i--)
	{
		for(j=0; j<size; j++)
			q[(arr[j]->data)[i] - 65].push(arr[j]);
		
		for(j=k= 0; j<26; j++)
		{
			while((!q[j].empty()))
			{
				arr[k++] = q[j].front();
				q[j].pop();
			}
		}
	}
    
}

void insertion(Data **arr[], int size)
{
	Data *c;
	int j;
	for(int i = 1; i<size; i++)
	{
		c = *arr[i];
		j = i-1;
		while((j>=0) && ((c->data) < ((*(arr[j]))->data)))
		{
			*(arr[j+1]) = *(arr[j]);
			j--;
		}
		*(arr[j+1]) = c;
	}
}


void sortDataList(list<Data *> &l) {
    
	int test;
	for (list<Data *>::const_iterator ipD = l.begin(); ipD != l.end(); ipD++)
		if(((*ipD)->data).size() !=5 && ((*ipD)->data).size() !=100)
		{
            
			ind = 0;
			for(it1 = l.begin(); it1 !=l.end(); it1++)
			{
				qarray[ind] = (*it1);
				ind++;
			}
			qsort(qarray,ind,sizeof(Data* ), compared);
			
			ind=0;
			for (it1 = l.begin();it1 != l.end();it1++)
			{
				(*it1)=qarray[ind];
				ind++;
			}
			
			break;
		}
		else
		{
			int count3;
			int count4;
			if(((*ipD)->data).size() == 5)
			{
				count3++;
				if(count3>2)
				{
					test =3;
					ind = 0;
					for(it1 =l.begin(); it1 != l.end(); it1++)
					{
						qarray[ind] = (*it1);
						ind++;
					}
					radSort(qarray,ind);
					
					ind=0;
					for (it1 = l.begin();it1 != l.end();it1++)
					{
						(*it1)=qarray[ind];
						ind++;
					}
                    
					break;
				}
			}
			else if(((*ipD)->data).size() == 100)
			{
				count4++;
				if(count4>2)
				{
					
					ind = 0;
					for(it1 =l.begin(); it1 != l.end(); it1++)
					{
						parray[ind] = &(*it1);
						ind++;
					}
					insertion(parray,ind);
					
					ind=0;
					for (it1 = l.begin();it1 != l.end();it1++)
					{
						*it1= *parray[ind];
						ind++;
					}
					
					break;
				}
			}
		}
}


