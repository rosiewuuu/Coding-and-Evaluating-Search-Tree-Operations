#include<time.h>
#include <iostream>
#include <iomanip>
#include "BinarySearchTree.h"
#include "AvlTree.h"
using namespace std;
double elapsed_time(clock_t start, clock_t finish) { // returns elapsed time in milliseconds
	return (finish - start) / (double) (CLOCKS_PER_SEC / 1000);
}

int main(int argc, char *const argv[]) {
	//Building T1 and T2
	BinarySearchTree<int> T1;
	AvlTree<int> T2;

	int NUMS = 30000;
	int i, key;
	int arr[NUMS + 1];
	clock_t start, finish, start11, finish11, start22, finish22;
	double total_insert_time_T1 = 0;
	double total_insert_time_T2 = 0;
	double minimum_time_T1 = 10000;
	double maximum_time_T1 = 0;
	double minimum_time_T2 = 10000;
	double maximum_time_T2 = 0;
	for (i = 0; i < NUMS; i++) { 	//making an ordered array or T1 and T2
		arr[i] = i + 1;
		key = arr[i];

		start11 = clock();
		T1.insert(key);
		finish11 = clock();
		double interval_T1 = elapsed_time(start11, finish11);
		total_insert_time_T1 = total_insert_time_T1 + interval_T1;
		if (interval_T1 < minimum_time_T1) {
			minimum_time_T1 = interval_T1;
		}
		if (interval_T1 > maximum_time_T1) {
			maximum_time_T1 = interval_T1;
		}

		start22 = clock(); 	//T1,T2 is inserted with number small to big
		T2.insert(key);
		finish22 = clock();
		double interval_T2 = elapsed_time(start22, finish22);
		total_insert_time_T2 = total_insert_time_T2 + interval_T2;
		if (interval_T2 < minimum_time_T2) {
			minimum_time_T2 = interval_T2;
		}
		if (interval_T2 > maximum_time_T2) {
			maximum_time_T2 = interval_T2;
		}

	}

	double avg_insert_T1 = total_insert_time_T1 / NUMS;
	double avg_insert_T2 = total_insert_time_T2 / NUMS;


	//timing: average time for checking T1
	double total_time_taken_T11 = 0;
	double minimum_time_T11 = 10000;
	double maximum_time_T11 = 0;
	/* stuff to time here */
	for (i = 0; i < NUMS; i++) {
		start = clock();
		T1.contains(arr[i]);
		finish = clock();
		double interval = elapsed_time(start, finish);
		total_time_taken_T11 = total_time_taken_T11 + interval;
		if (interval < minimum_time_T11) {
			minimum_time_T11 = interval;
		}
		if (interval > maximum_time_T11) {
			maximum_time_T11 = interval;
		}
	}
	double avg_time_T1 = total_time_taken_T11 / NUMS;

	//timing: average time for T2
	double total_time_taken_T22 = 0;
	double minimum_time_T22 = 10000;
	double maximum_time_T22 = 0;
	/* stuff to time here */
	for (i = 0; i < NUMS; i++) {
		start = clock();
		T2.contains(arr[i]);
		finish = clock();
		double interval = elapsed_time(start, finish);
		total_time_taken_T22 = total_time_taken_T22 + interval;
		if (interval < minimum_time_T22) {
			minimum_time_T22 = interval;
		}
		if (interval > maximum_time_T22) {
			maximum_time_T22 = interval;
		}
	}
	double avg_time_T2 = total_time_taken_T22 / NUMS;


	//timing: average depth for tree T1
	int cumulated_depth_T1 = 0;
	int min_depth_T1 = 100000;
	int max_depth_T1 = 0;
	for (i = 0; i < NUMS; i++) {
		int d = T1.depth(arr[i]);
		cumulated_depth_T1 = cumulated_depth_T1 + d;
		if (d > max_depth_T1) {
			max_depth_T1 = d;
		}
	}
	double avg_treedepth__T1 = cumulated_depth_T1 / NUMS;

	//timing: average depth for tree T2
	int cumulated_depth_T2 = 0;
	int max_depth_T2 = 0;
	int min_depth_T2 = 100000;
	for (i = 0; i < NUMS; i++) {
		int d = T2.depth(arr[i]);
		cumulated_depth_T2 = cumulated_depth_T2 + d;
		if (d > max_depth_T2) {
			max_depth_T2 = d;
		}
	}

	double avg_treedepth__T2 = cumulated_depth_T2 / NUMS;



	//avg search depth
	int cumulated_searchdepth_T1 = 0;
	int cumulated_searchdepth_T2 = 0;
	int min_searchdepth_T1 = T1.contains_search_depth(arr[0]);
	int min_searchdepth_T2 = T2.contains_search_depth(arr[0]);
	int max_searchdepth_T1 = 0;
	int max_searchdepth_T2 = 0;

	for (int h = 0; h < 2 * NUMS; h++) {
		int d1 = T1.contains_search_depth(arr[0] + h);
		int d2 = T2.contains_search_depth(arr[0] + h);
		cumulated_searchdepth_T1 = cumulated_searchdepth_T1 + d1;
		cumulated_searchdepth_T2 = cumulated_searchdepth_T2 + d2;
		if (d1 < min_searchdepth_T1) {
			min_searchdepth_T1 = d1;
		}
		if (d2 < min_searchdepth_T2) {
			min_searchdepth_T2 = d2;
		}
		if (d1 > max_searchdepth_T1) {
			max_searchdepth_T1 = d1;
		}
		if (d2 > max_searchdepth_T2) {
			max_searchdepth_T2 = d2;
		}
	}
	double aavg_depth_search_T1 = cumulated_searchdepth_T1 / (2 * NUMS);
	double aavg_depth_search_T2 = cumulated_searchdepth_T2 / (2 * NUMS);


	cout << "Experiment 2: change NUMS change size of input list" << endl;
	cout << "T1 and T2 both have " << NUMS << " of nodes inserted" << endl
			<< endl;

	cout<<"T1"<<endl;
	cout <<"Height: "<<T1.height() << endl;
	cout <<"AVG tree depth "<<avg_treedepth__T1 << endl;
	cout <<"AVG inserting time "<<avg_insert_T1 << endl;
	cout <<"AVG checking: "<<avg_time_T1<< endl;
	cout <<"min checking: "<<minimum_time_T1 << endl;
	cout <<"max checking: "<<maximum_time_T1 << endl;
	cout <<"AVG search depth "<<aavg_depth_search_T1<< endl;
	cout<<"min search depth: " <<min_searchdepth_T1 << endl;
	cout <<"max search depth: "<<max_searchdepth_T1 << endl<<endl;


	cout<<"T2"<<endl;
	cout <<"Height: "<<T2.height() << endl;
	cout <<"AVG tree depth "<<avg_treedepth__T2 << endl;
	cout <<"AVG inserting time "<<avg_insert_T2 << endl;
	cout <<"AVG checking: "<<avg_time_T2<< endl;
	cout <<"min checking: "<<minimum_time_T2 << endl;
	cout <<"max checking: "<<maximum_time_T2 << endl;
	cout <<"AVG search depth "<<aavg_depth_search_T2<< endl;
	cout<<"min search depth: " <<min_searchdepth_T2 << endl;
	cout <<"max search depth: "<<max_searchdepth_T2 << endl<<endl;




}
