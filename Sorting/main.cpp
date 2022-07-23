#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>

using namespace std;

template<typename T>
void counting_sort(T arr[], int len) {
    map<T, int> sortMap;
    for(int i = 0; i < len; ++i) {
        sortMap[arr[i]]++;
    }
    int j = 0;
    for(auto entry: sortMap) {
        for(int k = 0; k < entry.second; ++k) {
            arr[j] = entry.first;
            j++;
        }
    }
}

template<typename T>
void max_heapify(T arr[], int start, int end) {
    // 二叉树连续储存，所以子节点的下标=父节点下标*2 + 1（左边）/父节点下标*2 + 2（右边）
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 确认子节点在arr内
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 比较两个子节点大小，选择大的那个
            son++;
        if (arr[dad] > arr[son]) // 如果父节点大于子节点，则不需要调整
            return;
        else { // 如果父节点小于子节点，交换父子内容，并继续比较
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

template<typename T>
void heap_sort(T arr[], int len) {
    // 初始化，i从最后一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    // 先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
        // 每次 max_heapify都能将最大的元素放到跟节点0
    }
}

template<typename T>
void QuickSortV2(T arr[], int low, int high) {
    if(low >= high) return;

    int upperBound = high;
    T pivot = arr[low];
    while(low < high) {
        // right to left
        while(low < high && arr[high] >= pivot) --high;
        swap(arr[high], arr[low]);

        // left to right
        while(low < high && arr[low] <= pivot) ++low;
        swap(arr[low], arr[high]);
    }
    QuickSortV2(arr, 0, low - 1);
    QuickSortV2(arr, low + 1, upperBound);
}

template<typename T>
void quick_sort_v2(T arr[], int len) {
    QuickSortV2(arr, 0, len - 1);
}


template<typename T>
int partition(T arr[], int low, int high) {
    int pivot = arr[low];
    while(low < high) {
        while(low < high && arr[high] >= pivot) {
            --high;
        }
        arr[low] = arr[high];
        while(low < high && arr[low] <= pivot) {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

template<typename T>
void QuickSort(T arr[], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

template<typename T>
void quick_sort(T arr[], int len) {
    QuickSort(arr, 0, len - 1);
}

template<typename T>
void Merge(T arr[], int front, int mid, int end) {
    vector<T> LeftSubArray(arr + front, arr + mid + 1);
    vector<T> RightSubArray(arr + mid + 1, arr + end + 1);

    int idxLeft = 0, idxRight = 0;
    LeftSubArray.insert(LeftSubArray.end(), numeric_limits<T>::max());
    RightSubArray.insert(RightSubArray.end(), numeric_limits<T>::max());

    for(int i = front; i <= end; ++i) {
        if(LeftSubArray[idxLeft] < RightSubArray[idxRight]) {
            arr[i] = LeftSubArray[idxLeft];
            idxLeft++;
        }
        else {
            arr[i] = RightSubArray[idxRight];
            idxRight++;
        }
    }
}

template<typename T>
void MergeSort(T arr[], int front, int end) {
    if (front >= end) return;
    int mid = (front + end) / 2;
    MergeSort(arr, front, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, front, mid, end);
}

template<typename T>
void merge_sort(T arr[], int len) {
    MergeSort(arr, 0, len - 1);
}

template<typename T>
void shell_sort(T arr[], int len) {
    int h = 1;
    while(h < len / 3) {
        h = 3 * h + 1;
    }

    while(h >= 1) {
        for(int i = h; i < len; ++i) {
            for(int j = i; j >=h && arr[j] < arr[j - h]; j -= h) {
                swap(arr[j], arr[j - h]);
            }
        }
        h = h / 3;
    }
}

template<typename T>
void insertion_sort(T arr[], int len) {
    for(int i = 1; i < len; ++i) {
        for(int j = i; j >= 1 & arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

template<typename T>
void selection_sort(T arr[], int len) {
    for(int i = 0; i < len - 1; ++i) {
        int min_index = i;
        for(int j = i + 1; j < len; ++j) {
            if(arr[j] < arr[min_index]) min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

template<typename T>
void bubble_sort(T arr[], int len) {
    // 每次i循环可以保证最后i个元素有序，因此j的循环次数可以减少为len - i 次
    for(int i = 0; i < len - 1; ++i) {
        for(int j = 0; j < len - 1 - i; ++j) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);
//    bubble_sort(arr, len);
//    selection_sort(arr, len);
//    insertion_sort(arr, len);
//    shell_sort(arr, len);
//    merge_sort(arr, len);
//    quick_sort(arr, len);
//    quick_sort_v2(arr, len);
//    heap_sort(arr, len);
    counting_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
    len = (float) sizeof(arrf) / sizeof(*arrf);
//    bubble_sort(arrf, len);
//    selection_sort(arrf, len);
//    insertion_sort(arrf, len);
//    shell_sort(arrf, len);
//    merge_sort(arrf, len);
//    quick_sort(arrf, len);
//    quick_sort_v2(arrf, len);
//    heap_sort(arrf, len);
    counting_sort(arrf, len);
    for (int i = 0; i < len; i++)
        cout << arrf[i] << ' ';
    cout << endl;
    return 0;
}
