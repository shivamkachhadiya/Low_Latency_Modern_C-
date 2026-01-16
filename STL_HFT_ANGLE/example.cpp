#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*
--------------------------------------------------
SECTION 1: VECTOR REALLOCATION & GROWTH
--------------------------------------------------
*/

void vector_growth_demo()
{
    vector<int> v;
    v.reserve(8); // Pre-allocate memory

    size_t prev_capacity = v.capacity();

    for (int i = 0; i < 20; i++)
    {
        v.push_back(i);

        if (v.capacity() != prev_capacity)
        {
            cout << "Reallocation happened! New capacity = "
                 << v.capacity() << endl;
            prev_capacity = v.capacity();
        }
    }
}

/*
--------------------------------------------------
SECTION 2: ARRAY VS VECTOR
--------------------------------------------------
*/

void array_vs_vector()
{
    array<int, 5> arr = {1, 2, 3, 4, 5}; // stack allocated
    vector<int> vec = {1, 2, 3, 4, 5};   // heap allocated

    cout << "array size: " << arr.size() << endl;
    cout << "vector size: " << vec.size() << endl;
}

/*
--------------------------------------------------
SECTION 3: CACHE FRIENDLINESS (CONTIGUOUS MEMORY)
--------------------------------------------------
*/

void cache_friendly_demo()
{
    const int N = 10'000'000;

    vector<int> v(N, 1);
    auto start = high_resolution_clock::now();

    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += v[i]; // sequential access
    }

    auto end = high_resolution_clock::now();
    cout << "Vector sequential access time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;
}

/*
--------------------------------------------------
SECTION 4: MAP VS UNORDERED_MAP
--------------------------------------------------
*/

void map_vs_unordered_map()
{
    const int N = 1'000'000;

    map<int, int> ordered;
    unordered_map<int, int> unordered;
    unordered.reserve(N); // IMPORTANT

    // map insertion
    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        ordered[i] = i;
    }
    auto end = high_resolution_clock::now();
    cout << "map insertion time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;

    // unordered_map insertion
    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
    {
        unordered[i] = i;
    }
    end = high_resolution_clock::now();
    cout << "unordered_map insertion time: "
         << duration_cast<milliseconds>(end - start).count()
         << " ms" << endl;
}

/*
--------------------------------------------------
SECTION 5: ITERATOR INVALIDATION
--------------------------------------------------
*/

void iterator_invalidation()
{
    vector<int> v = {1, 2, 3};
    auto it = v.begin();

    v.push_back(4); // may reallocate

    // it is now INVALID
    // cout << *it;   // ❌ undefined behavior

    it = v.begin(); // fix
    cout << "Safe iterator value: " << *it << endl;
}

/*
--------------------------------------------------
SECTION 6: ALGORITHMS & BIG-O
--------------------------------------------------
*/

void algorithm_demo()
{
    vector<int> v = {5, 4, 3, 2, 1};

    sort(v.begin(), v.end()); // O(N log N)

    bool found = binary_search(v.begin(), v.end(), 3); // O(log N)
    cout << "Found 3? " << found << endl;
}

/*
--------------------------------------------------
MAIN
--------------------------------------------------
*/

int main()
{
    vector_growth_demo();
    //array_vs_vector();
    //cache_friendly_demo();
    //map_vs_unordered_map();
    //iterator_invalidation();
    //algorithm_demo();

    return 0;
}
