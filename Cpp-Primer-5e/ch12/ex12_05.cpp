#include "ex12_05.h"
#include <iostream>

void test(const StrBlob &strBlob) { return; }

/*
When a constructor is declared explicit, it can be used only with the direct
form of initialization (§ 3.2.1, p. 84). Moroever, the compiler will not use
this constructor in an automatic conversion.
*/

int main() {
  // StrBlob strBlob = {"aa", "bb", "cc"}; // Explicit constructor
  StrBlob strBlob({"aa", "bb", "cc"});

  // test({"aa", "bb", "cc"}); // cannot convert initializer list argument to
  // 'const StrBlob'
  test(StrBlob({"aa", "bb", "cc"}));
}