/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "antlr4-common.h"

namespace antlr4 {
namespace misc {

  class ANTLR4CPP_PUBLIC MurmurHash {

  private:
    static const size_t DEFAULT_SEED = 0;

    /// Initialize the hash using the default seed value.
    /// Returns the intermediate hash value.
  public:
    static size_t initialize();

    /// Initialize the hash using the specified seed.
    static size_t initialize(size_t seed);

    /// Update the intermediate hash value for the next input { value}.
    /// <param name="hash"> the intermediate hash value </param>
    /// <param name="value"> the value to add to the current hash </param>
    /// Returns the updated intermediate hash value.
    static size_t update(size_t hash, size_t value);

    /**
     * Update the intermediate hash value for the next input { value}.
     *
     * @param hash the intermediate hash value
     * @param value the value to add to the current hash
     * @return the updated intermediate hash value
     */
    template <class T>
    static size_t update(size_t hash, Ref<T> const& value) {
      return update(hash, value != nullptr ? value->hashCode() : 0);
    }

    template <class T>
    static size_t update(size_t hash, T *value) {
      return update(hash, value != nullptr ? value->hashCode() : 0);
    }

    /// <summary>
    /// Apply the final computation steps to the intermediate value { hash}
    /// to form the final result of the MurmurHash 3 hash function.
    /// </summary>
    /// <param name="hash"> the intermediate hash value </param>
    /// <param name="entryCount"> the number of calls to update() before calling finish() </param>
    /// <returns> the final hash result </returns>
    static size_t finish(size_t hash, size_t entryCount);

    
    template<typename T> // where T is C array type
    static size_t hashCode(const std::vector<Ref<T>> &data, size_t seed) {
      size_t hash = initialize(seed);
      for (auto entry : data) {
        hash = update(hash, entry->hashCode());
      }

      return finish(hash, data.size());
    }
  };

} // namespace atn
} // namespace antlr4
