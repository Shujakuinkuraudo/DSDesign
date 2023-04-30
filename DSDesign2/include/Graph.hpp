#pragma once

#include "bits/stdc++.h"

using namespace std;


template<class T>
struct Edge {
    int to;
    T cost;
};

template<class T>
class Graph {

public:

    vector<Edge<T>> *G; // 存储图的邻接表
    int vex_num;
    vector<pair<int, int>> pos;

    ~Graph();

    /**
    @brief 生成节点的坐标
    @param x_start 节点横坐标起始值
    @param y_start 节点纵坐标起始值
    @param x_size 生成的横坐标范围
    @param y_size 生成的纵坐标范围
    **/
    void generatePos(int x_start, int y_start, int x_size, int y_size);

    /**
    @brief 从文件中读取图的数据并构建图
    @param file_name 文件名
    **/
    void readFromFile(string file_name);

    /**
    @brief Dijkstra算法，计算从起点到所有节点的最短距离和最短路径
    @param start 起点的编号
    @return 返回一个pair，第一个vector存储从起点到每个节点的最短距离，第二个vector存储每个节点的前驱节点编号
    **/
    pair<vector<int>, vector<int>> dijkstra(int start);

    /**
    @brief 根据节点的前驱节点信息，查找起点到目标节点的路径
    @param target 目标节点的编号
    @param pre 存储每个节点的前驱节点编号的vector
    @return 返回一个vector，存储起点到目标节点的路径，按顺序存储每个节点的编号
    */
    static vector<int> findPath(int target, const vector<int> &pre);
};


#include "Graph.ipp"