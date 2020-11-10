/**
 * Created by Xiaozhong on 2020/9/20.
 * Copyright (c) 2020/9/20 Xiaozhong. All rights reserved.
 */
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

/*template<typename _ForwardIterator, typename _Tp, typename _Compare>
_ForwardIterator
__upper_bound(_ForwardIterator __first, _ForwardIterator __last,
              const _Tp &__val, _Compare __comp) {
    typedef typename iterator_traits<_ForwardIterator>::difference_type
            _DistanceType;

    _DistanceType __len = std::distance(__first, __last);

    while (__len > 0) {
        _DistanceType __half = __len >> 1;
        _ForwardIterator __middle = __first;
        std::advance(__middle, __half);
        if (__comp(__val, __middle))
            __len = __half;
        else {
            __first = __middle;
            ++__first;
            __len = __len - __half - 1;
        }
    }
    return __first;
}

*//**
 *  @brief Finds the last position in which @p __val could be inserted
 *         without changing the ordering.
 *  @ingroup binary_search_algorithms
 *  @param  __first   An iterator.
 *  @param  __last    Another iterator.
 *  @param  __val     The search term.
 *  @return  An iterator pointing to the first element greater than @p __val,
 *           or end() if no elements are greater than @p __val.
 *  @ingroup binary_search_algorithms
 *//*

template<typename _ForwardIterator, typename _Tp>
inline _ForwardIterator
upper_bound(_ForwardIterator __first, _ForwardIterator __last,
            const _Tp &__val) {
    // concept requirements
    __glibcxx_function_requires(_ForwardIteratorConcept < _ForwardIterator >)
    __glibcxx_function_requires(_LessThanOpConcept <
                                _Tp, typename iterator_traits<_ForwardIterator>::value_type >)
    __glibcxx_requires_partitioned_upper(__first, __last, __val);

    return std::__upper_bound(__first, __last, __val,
                              __gnu_cxx::__ops::__val_less_iter());
}

*//**
 *  @brief Finds the last position in which @p __val could be inserted
 *         without changing the ordering.
 *  @ingroup binary_search_algorithms
 *  @param  __first   An iterator.
 *  @param  __last    Another iterator.
 *  @param  __val     The search term.
 *  @param  __comp    A functor to use for comparisons.
 *  @return  An iterator pointing to the first element greater than @p __val,
 *           or end() if no elements are greater than @p __val.
 *  @ingroup binary_search_algorithms
 *
 *  The comparison function should have the same effects on ordering as
 *  the function used for the initial sort.
 *//*

template<typename _ForwardIterator, typename _Tp, typename _Compare>
inline _ForwardIterator
upper_bound(_ForwardIterator __first, _ForwardIterator __last,
            const _Tp &__val, _Compare __comp) {
    // concept requirements
    __glibcxx_function_requires(_ForwardIteratorConcept < _ForwardIterator >)
    __glibcxx_function_requires(_BinaryPredicateConcept < _Compare,
                                _Tp, typename iterator_traits<_ForwardIterator>::value_type >)
    __glibcxx_requires_partitioned_upper_pred(__first, __last,
                                              __val, __comp);

    return std::__upper_bound(__first, __last, __val,
                              __gnu_cxx::__ops::__val_comp_iter(__comp));
}*/
/**
   *  @brief Finds the first position in which @a val could be inserted
   *         without changing the ordering.
   *  @param  __first   An iterator.
   *  @param  __last    Another iterator.
   *  @param  __val     The search term.
   *  @return         An iterator pointing to the first element <em>not less
   *                  than</em> @a val, or end() if every element is less than
   *                  @a val.
   *  @ingroup binary_search_algorithms
  *//*
template<typename _ForwardIterator, typename _Tp>
inline _ForwardIterator
lower_bound(_ForwardIterator __first, _ForwardIterator __last,
            const _Tp &__val) {
    // concept requirements
    __glibcxx_function_requires(_ForwardIteratorConcept < _ForwardIterator >)
    __glibcxx_function_requires(_LessThanOpConcept <
                                typename iterator_traits<_ForwardIterator>::value_type, _Tp >)
    __glibcxx_requires_partitioned_lower(__first, __last, __val);

    return std::__lower_bound(__first, __last, __val,
                              __gnu_cxx::__ops::__iter_less_val());
}

template<typename _ForwardIterator, typename _Tp, typename _Compare>
_ForwardIterator
__lower_bound(_ForwardIterator __first, _ForwardIterator __last,
              const _Tp &__val, _Compare __comp) {
    typedef typename iterator_traits<_ForwardIterator>::difference_type
            _DistanceType;

    _DistanceType __len = std::distance(__first, __last);

    while (__len > 0) {
        _DistanceType __half = __len >> 1;
        _ForwardIterator __middle = __first;
        std::advance(__middle, __half);
        if (__comp(__middle, __val)) {
            __first = __middle;
            ++__first;
            __len = __len - __half - 1;
        } else
            __len = __half;
    }
    return __first;
}*/

int main() {
    vector<int> nums = {1, 2, 3, 4, 4, 5};
    cout <<
         *upper_bound(nums.begin(), nums.end(), 3) << endl; // >: 4
    cout <<
         upper_bound(nums.begin(), nums.end(), 3) - nums.begin() << endl; // >: 3
    cout << *upper_bound(nums.begin(), nums.end(), 3, [&](const int &val, const int &b) {
        /**
         * 参数 val 就是 3
         * 参数 b 来自 nums 中的数
         */
        return val < b;
    }) << endl; // >: 4


    cout <<
         *lower_bound(nums.begin(), nums.end(), 3) << endl; // >: 3
    cout <<
         lower_bound(nums.begin(), nums.end(), 3) - nums.begin() << endl; // >: 2
    cout << *lower_bound(nums.begin(), nums.end(), 3, [](const int &val, const int &b) {
        return val < b;
    }) << endl; // >: 3
    cout << *lower_bound(nums.begin(), nums.end(), 3, [](const int &val, const int &b) {
        return val <= b;
    }) << endl; // >: 4
    cout << lower_bound(nums.begin(), nums.end(), 3, [](const int &val, const int &b) {
        return val <= b;
    }) - nums.begin() << endl; // >: 3
}
