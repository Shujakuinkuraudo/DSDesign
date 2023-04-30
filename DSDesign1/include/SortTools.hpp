#pragma once

#include "head.h"

template<class T>
class SortTools {
public:
    static void insertSort(vector<T> &arr, int n, int &move_count);

    static void quickSort(vector<T> &arr, int low, int high, int &move_count);

    static void heapSort(vector<T> &arr, int n, int &move_count);

    static void mergeSort(vector<T> &arr, vector<T> &temp, int low, int high, int &move_count);

    static void shellSort(vector<T> &arr, int n, int &move_count);

    static void menu(vector<T> &last_data, int &move_count);
};



#include "SortTools.ipp"