#pragma  once

#include "head.h"

template<class T>
class IOTools {
public:
    static void O(string file_name, const vector<T> &data);

    static void O(const vector<T> &data);;

    static void I(string file_name, vector<T> &data);

    static void I(vector<T> &data);

    static void output(const vector<T> &last_data);
};

#include "IOTools.ipp"

