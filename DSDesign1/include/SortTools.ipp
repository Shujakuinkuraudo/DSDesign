template<class T>
void SortTools<T>::insertSort(vector<T> &arr, int n, int &move_count) {
    move_count = 0;
    int i, j;
    for (i = 1; i < n; i++) {
        int temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--) {
            arr[j + 1] = arr[j];
            move_count++;
        }
        arr[j + 1] = temp;
    }
}

template<class T>
void SortTools<T>::quickSort(vector<T> &arr, int low, int high, int &move_count) {
    if (low >= high) {
        return;
    }

    int i = low, j = high - 1;
    int pivot = arr[low];

    while (i < j) {
        while (i < j && arr[j] >= pivot) {
            j--;
            move_count++;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot) {
            i++;
            move_count++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;

    quickSort(arr, low, i - 1, move_count);
    quickSort(arr, i + 1, high, move_count);
}

template<class T>
void SortTools<T>::heapSort(vector<T> &arr, int n, int &move_count) {
    move_count = 0;

    for (int i = n / 2 - 1; i >= 0; i--) {

        int parent = i;
        int child = 2 * parent + 1;
        while (child < n) {
            if (child + 1 < n && arr[child] < arr[child + 1]) {
                child++;
            }
            if (arr[parent] < arr[child]) {
                swap(arr[parent], arr[child]);
                parent = child;
                child = 2 * parent + 1;
                move_count++;
            } else {
                break;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        move_count++;

        int parent = 0;
        int child = 2 * parent + 1;
        while (child < i) {
            if (child + 1 < i && arr[child] < arr[child + 1]) {
                child++;
            }
            if (arr[parent] < arr[child]) {
                swap(arr[parent], arr[child]);
                parent = child;
                child = 2 * parent + 1;
                move_count++;
            } else {
                break;
            }
        }
    }
}

template<class T>
void SortTools<T>::mergeSort(vector<T> &arr, vector<T> &temp, int low, int high, int &move_count) {
    high--;
    if (low >= high)
        return;

    int mid = low + high >> 1;
    mergeSort(arr, temp, low, mid + 1, move_count);
    mergeSort(arr, temp, mid + 1, high + 1, move_count);

    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
            move_count++;
        } else {
            temp[k++] = arr[j++];
            move_count++;
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
        move_count++;
    }
    while (j <= high) {
        temp[k++] = arr[j++];
        move_count++;
    }
    for (int l = low; l <= high; l++) {
        arr[l] = temp[l];
    }
}

template<class T>
void SortTools<T>::menu(vector<T> &last_data, int &move_count) {
    int opt;
    cout << "The sort method you want to use 1.quick sort 2.heap sort 3.merge sort 4.shell sort" << endl;
    cin >> opt;
    switch (opt) {
        case 1:
            SortTools<int>::quickSort(last_data, 0, last_data.size(), move_count);
            break;
        case 2:
            SortTools<int>::heapSort(last_data, last_data.size(), move_count);
            break;
        case 3: {
            vector<int> temp(last_data.size());
            SortTools<int>::mergeSort(last_data, temp, 0, last_data.size(), move_count);
            break;
        }
        case 4:
            shellSort(last_data, last_data.size(), move_count);
            break;
    }
}
template<class T>
void SortTools<T>::shellSort(vector<T> &arr, int n, int &move_count) {
    // 设置增量gap，并逐步缩小增量
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对各个分组进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                move_count++;
            }
            arr[j] = temp;
            move_count++;
        }
    }
}
