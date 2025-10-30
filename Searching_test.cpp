#define UNIT_TEST
#include "Searching.cpp"
#include <cassert>

static list<long long> makeSortedList(initializer_list<long long> vals) {
    list<long long> lst(vals);
    lst.sort();
    return lst;
}

int main() {
    // Base cases: empty and single-element lists
    {
        list<long long> lst;
        assert(Searching::SequentialSearch(lst, 10) == -1);
        assert(Searching::SequentialRecursiveSearch(lst, 10) == -1);
        assert(Searching::BinarySearch(lst, 10) == -1);
        assert(Searching::BinaryRecursiveSearch(lst, 10) == -1);
    }
    {
        auto lst = makeSortedList({5});
        assert(Searching::SequentialSearch(lst, 5) == 0);
        assert(Searching::SequentialRecursiveSearch(lst, 5) == 0);
        assert(Searching::BinarySearch(lst, 5) == 0);
        assert(Searching::BinaryRecursiveSearch(lst, 5) == 0);
        assert(Searching::SequentialSearch(lst, 6) == -1);
        assert(Searching::BinarySearch(lst, 6) == -1);
    }

    // General cases
    auto lst = makeSortedList({9, 1, 5, 7, 3}); // becomes {1,3,5,7,9}
    // Present targets
    assert(Searching::SequentialSearch(lst, 1) == 0);
    assert(Searching::SequentialRecursiveSearch(lst, 1) == 0);
    long long idx3 = Searching::BinarySearch(lst, 3);
    assert(idx3 != -1);
    {
        auto it = lst.begin();
        advance(it, idx3);
        assert(*it == 3);
    }
    long long idx9r = Searching::BinaryRecursiveSearch(lst, 9);
    assert(idx9r != -1);
    {
        auto it = lst.begin();
        advance(it, idx9r);
        assert(*it == 9);
    }
    // Absent target
    assert(Searching::SequentialSearch(lst, 2) == -1);
    assert(Searching::SequentialRecursiveSearch(lst, 2) == -1);
    assert(Searching::BinarySearch(lst, 2) == -1);
    assert(Searching::BinaryRecursiveSearch(lst, 2) == -1);

    // Larger list
    list<long long> big;
    for (int i = 0; i < 100; ++i) big.push_back(i * 2); // even numbers
    // present
    long long idx = Searching::BinarySearch(big, 64);
    assert(idx != -1);
    auto it = big.begin();
    advance(it, idx);
    assert(*it == 64);
    // absent
    assert(Searching::BinaryRecursiveSearch(big, 63) == -1);

    return 0;
}


