#ifndef MPZ_TEST_H
#define MPZ_TEST_H

#include "integer.h"
#include <gmpxx.h>

namespace mpz_test
{
mpz_class copy(const integer& i);
integer copy(const mpz_class& i);
bool operator==(const mpz_class& a, const integer& b);
bool operator==(const integer& b, const mpz_class& a);

bool simpleEqualityTestLoop(integer k, const integer& max);
bool simpleCmpTestLoop(integer k, const integer& max);
bool simpleSumTestLoop(integer k, const integer& max);
bool simpleSubTestLoop(integer k, const integer& max);
bool simpleBsTestLoop(integer k, const integer& max);
bool simpleMulTestLoop(integer k, const integer& max);
bool singleDigitMulTestLoop(integer k, const integer& max);
bool simpleDivTestLoop(integer k, const integer& max);
}
int mpz_test_loop();

#endif
