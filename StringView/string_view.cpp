#ifndef ARRAY
#define ARRAY

#include "string_view.h"
#include <stdexcept>
#include <cstdlib>
#include <cstring>

StringView::StringView() : line_(nullptr) {
  size_n_ = 0;
}

StringView::StringView(const char* line1) {
  line_ = line1;
  size_n_ = std::strlen(line_);
}

StringView::StringView(const char* line1, size_t n) {
  line_ = line1;
  size_n_ = n;
}

const char& StringView::operator[](size_t i) const {
  return line_[i];
}

const char& StringView::At(size_t idx) const {
  if (idx >= size_n_) {
    throw StringViewOutOfRange();
  } else {
    return line_[idx];
  }
}

const char& StringView::Front() const {
  return line_[0];
}

const char& StringView::Back() const {
  return line_[size_n_ - 1];
}

const char* StringView::Data() const {
  return line_;
}

int StringView::Size() const {
  return size_n_;
}

int StringView::Length() const {
  return size_n_;
}

bool StringView::Empty() const {
  return size_n_ == 0;
}

void StringView::Swap(StringView& line1) {
  std::swap(line1.line_, line_);
  std::swap(line1.size_n_, size_n_);
}

void StringView::RemovePrefix(size_t prefix_size) {
  line_ = line_ + prefix_size;
  size_n_ -= prefix_size;
}

void StringView::RemoveSuffix(size_t suffix_size) {
  size_n_ = size_n_ - suffix_size;
}

StringView StringView::Substr(size_t pos, size_t count) const {
  if (pos > size_n_) {
    throw StringViewOutOfRange();
  } else {
    size_t size = std::min(count, size_n_ - pos);
    return StringView(line_ + pos, size);
  }
}

#endif