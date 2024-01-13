#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include "Binary_tree.h"
using namespace std;

int performance(){
	T* tree = new T; 
	int n = 1000000;
	int* a =new int[n];
    for(int i=0;i<n;i++){
        a[i]=rand()%100000;
    }
    clock_t start,end;
	double time_taken ;
    
    start = clock();
    sort(a,a+n);    
    end = clock();
    
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
     cout << "Time taken by STL sort is : " << fixed
         << time_taken << setprecision(6);
     cout << " sec " << endl;
	
	delete(a);
	a = new int[n];
	srand(time(0));
	for(int i=0;i<n;i++){
        a[i]=rand()%100000;
    }
    start = clock();
    for(int i=0;i<n;i++){
    	tree->insert(a[i]);
    }
    tree->inorder_traverse(tree->root);
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
     cout << "Time taken by Binary tree method is : " << fixed
         << time_taken << setprecision(6);
     cout << " sec " << endl;
	
	
	return 0;
    
}
