#ifndef STRINGC
#define STRINGC

#include <cstdlib>
#include <stdexcept>
class StringViewOutOfRange : public std::out_of_range {
 public:
  StringViewOutOfRange() : std::out_of_range("StringViewOutOfRange") {
  }
};

class StringView {
  const char* line_;
  size_t size_n_;

 public:
  StringView();
  StringView(const char* line1);  // NOLINT
  StringView(const char* line1, size_t n);
  const char& operator[](size_t i) const;
  const char& At(size_t idx) const;
  const char& Front() const;
  const char& Back() const;
  const char* Data() const;
  int Size() const;
  int Length() const;
  bool Empty() const;
  void Swap(StringView& line1);
  void RemovePrefix(size_t prefix_size);
  void RemoveSuffix(size_t suffix_size);
  StringView Substr(size_t pos, size_t count = -1) const;
};
#endif