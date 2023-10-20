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
    int NUMS = 16;
    int i;
    int key;
    int arr[NUMS+1];
    for (i = 0; i<NUMS; i++) {
       	arr[i] = i+1;
       	key = arr[i] ;
       	T1.insert( key );
       	T2.insert( key );
    }
    int wanted_key = arr[NUMS/2];


    cout << "Start of  depth() test"<<endl ;
    cout << "Both trees are inserted with the same keys "<< arr[0]<<" to "<<arr[NUMS-1]<<" in order."<< endl << endl;

    cout<<"In BST tree, T1, depth of key "<<wanted_key<<" is "<< T1.depth(wanted_key)<<endl;
    cout<<"In AVL tree, T2, depth of key "<<wanted_key<<" is "<< T2.depth(wanted_key)<<endl<<endl;;


    cout<<"Tree of T1"<<endl;
    T1.displayTree();
    cout<<"Tree of T2"<<endl;
    T2.displayTree();

    cout<<"The depth is correct by re-checking with the graph above."<<endl;





    cout << "End of depth() test" << endl;
    return 0;
}






