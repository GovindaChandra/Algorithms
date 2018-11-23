#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

template<typename T>
void SelectSort(vector <T> &vec) {
    for (size_t i = 0; i + 1 < vec.size(); ++i) {

        size_t min_index = i;
        bool swap_flag = false;

        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[min_index] > vec[j]) {
                min_index = j;
                swap_flag = true;
            }
        }

        if (swap_flag) {
            T temp = vec[i];
            vec[i] = vec[min_index];
            vec[min_index] = temp;
        }
    }
}

TEST_CASE("Sorting integers") {
	vector<int> collection_unsorted = {1, 10, 2, 5, 6, 3, 9, 4, 8, 7, 0};
	vector<int> collection_sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	SelectSort(collection_unsorted);
	REQUIRE(collection_sorted == collection_unsorted);
}

TEST_CASE("Sorting string") {
	vector<string> collection_unsorted = {"bb", "ccc", "aaa", "b", "a"};
	vector<string> collection_sorted = {"a", "aaa", "b", "bb", "ccc"};
	SelectSort(collection_unsorted);
	REQUIRE(collection_sorted == collection_unsorted);
}