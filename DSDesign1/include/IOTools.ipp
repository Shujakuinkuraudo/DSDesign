template<class T>
void IOTools<T>::I(vector<T> &data) {
    cout << "press in the file name" << endl;
    string file_name;
    cin >> file_name;
    I(file_name, data);
}

template<class T>
void IOTools<T>::O(const vector<T> &data) {
    cout << "press in the file name" << endl;
    string file_name;
    cin >> file_name;
    O(file_name, data);
}

template<class T>
void IOTools<T>::I(string file_name, vector<T> &data) {
    ifstream inFile(file_name);
    if (!data.empty()) data.clear();
    T temp;
    if (inFile.is_open()) {
        while (inFile >> temp)
            data.push_back(temp);
        inFile.close();
        cout << "Data has been read from the file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

template<class T>
void IOTools<T>::O(string file_name, const vector<T> &data) {
    ofstream outFile(file_name);

    if (outFile.is_open()) {
        for (auto item: data)
            outFile << item << " ";
        outFile.close();
        cout << "Data has been written to the file." << endl;
    } else {
        cout << "Unable to open file." << endl;
    }
}

template<class T>
void IOTools<T>::output(const vector<T> &last_data) {
    for (int i = 0; i < last_data.size(); i++)
        cout << last_data[i] << " ";
    cout << endl;
}
