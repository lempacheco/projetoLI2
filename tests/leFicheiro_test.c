#include "include/leFicheiro_test.h"

Matriz m;

void testar_leFicheiro() {
    CU_ASSERT_EQUAL(leFicheiro("exemplo.txt", 11, &m), 1);
    /*CU_ASSERT_EQUAL(fact(1), 1);
    CU_ASSERT_EQUAL(fact(5), 120);
    CU_ASSERT_EQUAL(fact(7), 5040); */
}