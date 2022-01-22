#include "ex12_05.h"
#include <iostream>

void test(const StrBlob &strBlob) { return; }

int main() {
  // StrBlob strBlob = {"aa", "bb", "cc"}; // Explicit constructor
  StrBlob strBlob({"aa", "bb", "cc"});

  // test({"aa", "bb", "cc"}); // cannot convert initializer list argument to
                               // 'const StrBlob'
  test(StrBlob({"aa", "bb", "cc"}));
}