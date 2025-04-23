#include <CUnit/CUnit.h>
#include "../include/leFicheiro_test.h"
#include "../include/gravaFicheiro_test.h"
#include "../include/comandos_test.h" 
#include "../include/condicoes_test.h"
#include "../include/stackMats_test.h" 
#include "../include/listasFunc_test.h" 
#include <stdio.h>

int main() {
    if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();
    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    pSuite = CU_add_suite("test_suite", 0, 0);
    if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_leFicheiro", testar_leFicheiro)) {
      CU_cleanup_registry();
      return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite, "testar_gravaFicheiro", testar_gravaFicheiro)) {
      CU_cleanup_registry();
      return CU_get_error();
    }
     
    if (NULL == CU_add_test(pSuite, "testar_riscar", testar_riscar)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_branco", testar_branco)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_verifRiscadaOrt", testar_verifRiscadaOrt)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_verifBranco", testar_verifBranco)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_verificar", testar_verificar)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_copiaMatriz", testar_copiaMatriz)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_initStackMat", testar_initStackMat)) {
      CU_cleanup_registry();
      return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite, "testar_isFull", testar_isFull)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_initMatriz", testar_initMatriz)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_push", testar_push)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_pop", testar_pop)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_isEmpty", testar_isEmpty)) {
      CU_cleanup_registry();
      return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite, "testar_posPertencente", testar_posPertence)) {
      CU_cleanup_registry();
      return CU_get_error();
    }
    
    if (NULL == CU_add_test(pSuite, "testar_listasIguais", testar_listasIguais)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_pertenceAoGrupo", testar_pertenceAoGrupo)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_adicionarPos", testar_adicionarPos)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_adicionarLista", testar_adicionarLista)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    if (NULL == CU_add_test(pSuite, "testar_ordenaLista", testar_ordenaLista)) {
      CU_cleanup_registry();
      return CU_get_error();
    }

    CU_basic_run_tests();
    return CU_get_error();
  }