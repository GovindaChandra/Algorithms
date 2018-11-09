#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
void BubbleSort(vector<T> &vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        bool check = false;
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                T temp = vec[j + 1];
                vec[j + 1] = vec[j];
                vec[j] = temp;
                check = true;
            }
        }
        if (!check) {
            break;
        }
    }
}

template<typename T>
void PrintVector(vector<T> &vec) {
    for (auto item : vec) {
        cout << item << " ";
    }
    cout << endl;
}

int main() {
    vector<int> vec_int = {1, 10, 2, 5, 6, 3, 9, 4, 8, 7, 0};
    BubbleSort(vec_int);
    PrintVector(vec_int);

    vector<string> vec_str = {"bb", "ccc", "aaa", "b", "a"};
    BubbleSort(vec_str);
    PrintVector(vec_str);

    return 0;
}