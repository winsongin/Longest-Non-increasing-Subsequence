///////////////////////////////////////////////////////////////////////////////
// subsequence.hpp
//
// Two algorithms for solving the longest non-increasing subsequence problem.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <cassert>
#include <random>
#include <string>
#include <sstream>
#include <vector>

using sequence = std::vector<int>;

// Convert a sequence into a human-readable string useful for pretty-printing
// or debugging.
std::string sequence_to_string(const sequence& seq) {
  std::stringstream ss;
  ss << "[";
  bool first = true;
  for (auto& x : seq) {
    if (!first) {
      ss << ", ";
    }
    ss << x;
    first = false;
  }
  ss << "]";
  return ss.str();
}

// Generate a pseudorandom sequence of the given size, using the given
// seed, where all elements are in the range [0, max_element]. 
// max_element must be non-negative.
sequence random_sequence(size_t size, unsigned seed, int max_element) {

    assert(max_element >= 0);

    sequence result;

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dist(0, max_element);

    for (size_t i = 0; i < size; ++i) {
        result.push_back(dist(gen));
    }

    return result;
}

bool is_nonincreasing(const sequence& A) {
  //TO DO: Write code for this function, including rewriting the return
  // statement, and then delete these comments.
  return false;
  }

sequence longest_nonincreasing_end_to_beginning(const sequence& A) {
  
  const size_t n = A.size();
  
  // populate the array H with 0 values
  std::vector<size_t> H(n, 0);
  
  // calculate the values of array H
  // note that i has to be declared signed, to avoid an infinite loop, since
  // the loop condition is i >= 0
  for (signed int i = n-2;  i>= 0; i--) {
    for (size_t j = i+1; j < n ; j++) {
      // TODO: write the statements that compute the value of
      // H[i] based on conditions that involve A[i], A[j] and H[j]
    }
  }
  
  // calculate in max the length of the longest non-increasing subsequence
  // by adding 1 to the maximum value in H
  auto max = *std::max_element(H.begin(), H.end()) + 1;
  
  // allocate space for the subsequence R
  std::vector<int> R(max);
  
  // add elements to R in non-increasing order whose H's values are 
  // in decreasing order, starting with the element whose H value is max-1
  // store in index the H values sought: max-1, max-2, max-3, .. 0
  
  size_t index = max-1, j = 0;
  for (size_t i = 0; i < n; ++i) {
    if (H[i] == index) {
      // TODO: write the statements to add A[i] to the
      // sequence R by storing it into R[j], decrement
      // index and increment j
    }
  }
  
  return sequence(R.begin(), R.begin() + max);
}

sequence longest_nonincreasing_powerset(const sequence& A) {
  const size_t n = A.size();
  sequence best;
  std::vector<size_t> stack(n+1, 0);
  size_t k = 0;
  while (true) {
    
    if (stack[k] < n) {
      stack[k+1] = stack[k] + 1;
      ++k;
    } else {
      stack[k-1]++;
      k--;
    }
    
    if (k == 0) {
      break;
    }
    
    sequence candidate;
    for (size_t i = 1; i <= k; ++i) {
      candidate.push_back(A[stack[i]-1]);
    }
    // TODO: write the if statement to test whether candidate
    // determines a non-increasing sequence AND has a size
    // larger than the size of the current best if both 
    // conditions are satisfied, then stored candidate 
    // in best
  }
  return best;
}
