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
    int NUMS = 30;
    int i;
    int key;
    int arr[NUMS+1];
    for (i = 0; i<NUMS; i++) {
       	arr[i] = i+1;
       	key = arr[i] ;
       	T1.insert( key );
       	T2.insert( key );
    }


    cout << "Start of  height() test" ;
    cout << ": Both trees are inserted with the same keys"<< arr[0]<<" to "<<arr[NUMS-1]<<" in order."<< endl << endl;

    cout<<"height of T1 is: "<< T1.height()<<endl;
    cout<<"height of T2 is: "<< T2.height()<<endl<<endl;


    cout<<"Tree of T1"<<endl;
    T1.displayTree();
    cout<<"Tree of T"<<endl;
    T2.displayTree();
    cout<<"The height is correct by re-checking with the graph above."<<endl;





    cout << "End of height() test" << endl;
    return 0;
}




