//Demonstrate the correctness of displayLinks()

#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"
using namespace std;

// Test program
int main( )
{
	 BinarySearchTree<int> T1;
	 AvlTree<int> T2;
    int NUMS = 15;
    int i;
    int key;
    int arr[NUMS+1];
    for (i = 0; i<NUMS; i++) {
       	arr[i] = i+1;
       	key = arr[i] ;
       	T1.insert( key );
       	T2.insert( key );
    }


    cout << "Start of displayLinks() test" << endl;
    cout << "Both trees are inserted with the same keys form "<<arr[0]<<" to "<<arr[NUMS-1]<< endl << endl;


    cout << "BST Links:" << endl ;
    T1.displayLinks();

    cout << "AVL tree Links:" << endl ;
    T2.displayLinks();

    cout << "End of displayLink()" << endl;
    return 0;
}




