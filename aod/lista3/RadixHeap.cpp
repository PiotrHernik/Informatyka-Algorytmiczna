
// #include "RadixHeap.hpp"
// #include <queue>
// #include <algorithm>

// RadixHeap::RadixHeap() : size_(0), last_(0) {
//     buckets_min_.fill(std::numeric_limits<long long int>::max()); 
// }

// void RadixHeap::push(KeyType key, ValueType value) {
//     long long int encoded_key = key;
//     assert(last_ <= encoded_key);
//     ++size_;
//     size_t bucket = find_bucket(encoded_key, last_);
//     buckets_[bucket].emplace_back(encoded_key, value);
//     buckets_min_[bucket] = std::min(buckets_min_[bucket], encoded_key);
// }

// RadixHeap::KeyType RadixHeap::top_key() {
//     ensure_non_empty();
//     return last_;
// }

// RadixHeap::ValueType RadixHeap::top_value() {
//     ensure_non_empty();
//     return buckets_[0].back().second;
// }

// void RadixHeap::pop() {
//     ensure_non_empty();
//     buckets_[0].pop_back();
//     --size_;
// }

// bool RadixHeap::empty() const {
//     return size_ == 0;
// }

// size_t RadixHeap::size() const {
//     return size_;
// }

// void RadixHeap::clear() {
//     size_ = 0;
//     last_ = 0;
//     for (auto &bucket : buckets_) {
//         bucket.clear();
//     }
//     buckets_min_.fill(std::numeric_limits<long long int>::max());
// }


// size_t RadixHeap::find_bucket(long long int x, long long int last) { 
//     return x == last ? 0 : 64 - __builtin_clzll(x ^ last);
// }

// void RadixHeap::ensure_non_empty() {
//     assert(size_ > 0);
//     if (!buckets_[0].empty()) return;

//     size_t i = 1;
//     while (buckets_[i].empty()) ++i;
//     last_ = buckets_min_[i];

//     for (const auto &[key, value] : buckets_[i]) {
//         size_t bucket = find_bucket(key, last_);
//         buckets_[bucket].emplace_back(key, value);
//         buckets_min_[bucket] = std::min(buckets_min_[bucket], key);
//     }
//     buckets_[i].clear();
//     buckets_min_[i] = std::numeric_limits<long long int>::max();
// }


