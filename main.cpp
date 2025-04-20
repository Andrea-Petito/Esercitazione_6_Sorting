#include <cmath>
#include <iostream>
#include <numeric>
#include <sstream>
#include <chrono> 
#include <random>
#include "SortingAlgorithm.hpp"

using namespace std;
using namespace SortLibrary;

template<typename T>
string ArrayToString(const vector<T>& v) {
    string str;
    ostringstream toString;
    toString << "[ ";
    for (const T& e: v)
        toString << e << " ";
    toString << "]";

    return toString.str();
}

template <typename T>
void fillRandomVector(vector<T>& v, int min = 0, int max = 10000) {
	srand(time(0));
	for(size_t i = 0; i < v.size(); i++) {
		v[i] = min + rand() % (max - min + 1);
	}
}

int main(int argc, char *argv[]) {
	size_t m = 10000;
    if (argc > 1)
        m = stoi(argv[1]);

    unsigned int num_experiment = 10;

    vector<int> v1(m);
    fillRandomVector(v1);

    vector<double> v2(m);
    fillRandomVector(v2);

    vector<int> v3(m, 0);

    double time_bubble_v1 = 0.0;
    for (unsigned int t = 0; t < num_experiment; t++) {
        vector<int> v(v1);
        auto start = chrono::steady_clock::now();
        BubbleSort(v);
        auto end = chrono::steady_clock::now();
        time_bubble_v1 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_bubble_v1 /= num_experiment;
    cout << "BubbleSort - v1 (int): " << time_bubble_v1 << " µs" << endl;

    double time_bubble_v2 = 0.0;
    for (unsigned int t = 0; t < num_experiment; t++) {
        vector<double> v(v2);
        auto start = chrono::steady_clock::now();
        BubbleSort(v);
        auto end = chrono::steady_clock::now();
        time_bubble_v2 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_bubble_v2 /= num_experiment;
    cout << "BubbleSort - v2 (double): " << time_bubble_v2 << " µs" << endl;

    double time_bubble_v3 = 0.0;
    for (unsigned int t = 0; t < num_experiment; t++) {
        vector<int> v(v3);
        auto start = chrono::steady_clock::now();
        BubbleSort(v);
        auto end = chrono::steady_clock::now();
        time_bubble_v3 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_bubble_v3 /= num_experiment;
    cout << "BubbleSort - v3 (tutti 0): " << time_bubble_v3 << " µs" << endl;

    double time_heap_v1 = 0.0;
    for (unsigned int t = 0; t < num_experiment; t++) {
        vector<int> v(v1);
        auto start = chrono::steady_clock::now();
        HeapSort(v);
        auto end = chrono::steady_clock::now();
        time_heap_v1 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_heap_v1 /= num_experiment;
    cout << "HeapSort - v1 (int): " << time_heap_v1 << " µs" << endl;

    double time_heap_v3 = 0.0;
    for (unsigned int t = 0; t < num_experiment; t++) {
        vector<int> v(v3);
        auto start = chrono::steady_clock::now();
        HeapSort(v);
        auto end = chrono::steady_clock::now();
        time_heap_v3 += chrono::duration_cast<chrono::microseconds>(end - start).count();
    }
    time_heap_v3 /= num_experiment;
    cout << "HeapSort - v3 (tutti 0): " << time_heap_v3 << " µs" << endl;
    return 0;
}

