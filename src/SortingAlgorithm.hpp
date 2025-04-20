#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace SortLibrary {
	
template <typename T>
void BubbleSort(std::vector<T>& v) {
    bool scambiato;
    for (std::size_t i = 0; i < v.size() - 1; i++) {
        scambiato = false;
        for (std::size_t j = 0; j < v.size() - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                scambiato = true;
            }
        }
        if (!scambiato) break;
    }
}

template <typename T>
void Heapify(std::vector<T>& v, std::size_t n, std::size_t i) {
    std::size_t largest = i;
    std::size_t left = 2 * i + 1;
    std::size_t right = 2 * i + 2;

    if (left < n && v[left] > v[largest])
        largest = left;

    if (right < n && v[right] > v[largest])
        largest = right;

    if (largest != i) {
        std::swap(v[i], v[largest]);
        Heapify(v, n, largest);
    }
}

template <typename T>
void HeapSort(std::vector<T>& v) {
    std::size_t n = v.size();

    for (std::size_t i = n / 2 - 1; i != std::size_t(-1); --i) {
        Heapify(v, n, i);
    }

    for (std::size_t i = n - 1; i > 0; --i) {
        std::swap(v[0], v[i]);
        Heapify(v, i, 0);
    }
}
}


