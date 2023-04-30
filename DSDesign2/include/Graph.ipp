template<class T>
Graph<T>::~Graph() {
    delete[] G;
}

template<class T>
void Graph<T>::readFromFile(string file_name) {
    ifstream fin(file_name); // 从文件
    T temp;
    if (fin.is_open()) {
        int n, m;
        G = new vector<Edge<T>>[n + 1];

        fin >> n >> m;
        vex_num = n;
        for (int i = 0; i < m; i++) {
            int u, v, cost;
            fin >> u >> v >> cost;
            G[u].push_back((Edge<T>) {v, cost});
            G[v].push_back((Edge<T>) {u, cost});
        }
        fin.close();
        cout << "Data has been readFromFile from the file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }

    fin.close();

}

template<class T>
pair<vector<int>, vector<int>> Graph<T>::dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int >>, greater<>>
            pq;
    // 第一个int存储到起点的距离，第二个int存储当前节点编号
    pq.push(make_pair(0, start));
    vector<int> distance_from_start(vex_num + 1, 1 << 30), pre(vex_num + 1, -1); // 存储前驱节点
    distance_from_start[start] = 0;

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        int v = p.second;
        if (distance_from_start[v] < p.first) continue;
        //更新进树节点的紧邻
        for(auto &e:G[v]){
            if (distance_from_start[e.to] > distance_from_start[v] + e.cost && pre[e.to] == -1) {
                distance_from_start[e.to] = distance_from_start[v] + e.cost;
                pre[e.to] = v;
                pq.push(make_pair(distance_from_start[e.to], e.to));
            }
        }
    }
    return make_pair(distance_from_start, pre);
}

template<class T>
vector<int> Graph<T>::findPath(int target, const vector<int> &pre) {
    //打印路径
    vector<int> path;
    for (int v = target; v != -1; v = pre[v]) {
        path.push_back(v);
    }
    return path;
}

template<class T>
void Graph<T>::generatePos(int x_start, int y_start, int x_size, int y_size) {
    pos = vector<pair<int, int >>(vex_num + 1); // 存储每个节点的坐标
    for (int i = 1; i <= vex_num; i++) {
        pos[i].first = rand() % (x_size - x_start) + x_start;
        pos[i].second = rand() % (y_size - y_start) + y_start;
    }
}


