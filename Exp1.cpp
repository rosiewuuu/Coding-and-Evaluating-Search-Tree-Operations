/*
 * Exp1.cpp
 *
 *  Created on: Oct 29, 2022
 *      Author: rosem
 */
#include<time.h>
#include <iostream>
#include <iomanip>
#include "BinarySearchTree.h"
using namespace std;
double elapsed_time( clock_t start, clock_t finish){ // returns elapsed time in milliseconds
    return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
}

int main (int argc, char * const argv[]) {
	//Building T1 and T2
	 BinarySearchTree<int> T1,T2;

	    int NUMS = 30000;
	    int i,key;
	    int arr[NUMS+1]; 				//list of numbers we want to insert to tree
	    for (i = 0; i < NUMS; i++) { 	//making an ordered array or T1 and T2
	       	arr[i] = i+1;
	        key = arr[i] ;
	        T1.insert( key );			//T1 is inserted with number small to big
	    }
	    T2.bushy(0,NUMS-1,arr); 		//T2 is inserted with median of the ordered array
	    								//then median of subtrees and so on
	    								//such that every sub root is the median of its descendant


	//timing: average time for T1
    clock_t start, finish ;// used for getting the time.
    double total_time_taken_T1=0;
    double minimum_time_T1=0;
    double maximum_time_T1=0;
    /* stuff to time here */
    for (i = 0; i < NUMS; i++) {
    	start = clock();
    	T1.contains(arr[i]);
    	finish = clock();
    	double interval = elapsed_time(start,finish);
    	total_time_taken_T1 = total_time_taken_T1 + interval;
    	if (interval < minimum_time_T1){
    		minimum_time_T1 = interval;
    	}
    	if (interval > maximum_time_T1){
    	    		maximum_time_T1 = interval;
    	    	}
    }
    double avg_time_T1 = total_time_taken_T1/NUMS;


    //timing: average time for T2
        double total_time_taken_T2=0;
        double minimum_time_T2=0;
        double maximum_time_T2=0;
        /* stuff to time here */
        for (i = 0; i < NUMS; i++) {
        	start = clock();
        	T2.contains(arr[i]);
        	finish = clock();
        	double interval = elapsed_time(start,finish);
        	total_time_taken_T2 = total_time_taken_T2 + interval;
        	if (interval < minimum_time_T2){
        		minimum_time_T2 = interval;
        	}
        	if (interval > maximum_time_T2){
        	    		maximum_time_T2 = interval;
        	    	}
        }
        double avg_time_T2 = total_time_taken_T2/NUMS;





    //timing: average depth for T1
        int depth_T1=0;
        for (i = 0; i < NUMS; i++) {
            	depth_T1 = depth_T1 + T1.depth(arr[i]);
            }
        double avg_depth_search_T1 = depth_T1/(NUMS);

    //timing: average depth for T2
		int depth_T2=0;
		for (i = 0; i < NUMS; i++) {
				depth_T2 = depth_T2 + T2.depth(arr[i]);
			}
		double avg_depth_search_T2 = depth_T2/(NUMS);





		//timing: average time for T1 for finding keys that are not in the tree
		    //clock_t start, finish ;// used for getting the time.
		    double unexist_node_T1=0;
		    /* stuff to time here */
		    for (i = 0; i < 1000; i++) {
		    	start = clock();
		    	T1.contains(arr[NUMS] + (rand() % 10000));
		    	finish = clock();
		    	double interval1 = elapsed_time(start,finish);
		    	unexist_node_T1 = unexist_node_T1 + interval1;
		    }
		    double avg_search_unexist_T1=(unexist_node_T1/1000);


			//timing: average time for T2 for finding keys that are not in the tree
			    //clock_t start, finish ;// used for getting the time.
			    double unexist_node_T2=0;
			    /* stuff to time here */
			    for (i = 0; i < 1000; i++) {
			    	start = clock();
			    	T2.contains(arr[NUMS] + (rand() % 10000));
			    	finish = clock();
			    	double interval2 = elapsed_time(start,finish);
			    	unexist_node_T2 = unexist_node_T2 + interval2;
			    }
			    double avg_search_unexist_T2=(unexist_node_T2/1000);



    cout<<fixed<<setprecision(20);
    cout<<"Experiment 1"<<endl;
    cout<<"T1 and T2 both have "<<NUMS<< " of nodes inserted"<<endl;

    cout<<"height of T1 is: "<< T1.height()<<endl;
    cout<<"height of T2 is: "<< T2.height()<<endl;

    cout<<"average time to search existing node in T1 is "<<avg_time_T1<<" seconds" <<endl;
    cout<<"average time to search existing node in T2 is "<<avg_time_T2 <<" seconds" <<endl;

    cout<<"Average depth of search for T1 is "<<avg_depth_search_T1<<endl;
    cout<<"Average depth of search for T2 is "<<avg_depth_search_T2<<endl;

    cout<<"Minimum time to search existing node in T1 is "<<minimum_time_T1<<" seconds" <<endl;
    cout<<"Minimum time to search existing node in T2 is "<<minimum_time_T2<<" seconds" <<endl;

    cout<<"Maximum time to search existing node in T1 is "<<maximum_time_T1<<" seconds" <<endl;
    cout<<"Maximum time to search existing node in T2 is "<<maximum_time_T2<<" seconds" <<endl;

    cout<<"Average time to search non-existing node in T1 is "<<avg_search_unexist_T1<<" seconds" <<endl;
    cout<<"Average time to search non-existing node in T2 is "<<avg_search_unexist_T2<<" seconds" <<endl;



}
