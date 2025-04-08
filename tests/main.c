#include <CUnit/CUnit.h>
#include "include/leFicheiro_test.h"
#include <stdio.h>

int main() {
    if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();
    //CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    pSuite = CU_add_suite("test_suite", 0,
                          0);
    if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_leFicheiro", testar_leFicheiro)) {
      CU_cleanup_registry();
      return CU_get_error();
    }
  
  
    CU_basic_run_tests();
    return CU_get_error();
  }
  