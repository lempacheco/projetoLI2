#include <CUnit/CUnit.h>
#include "../include/leFicheiro_test.h"
#include "../include/gravaFicheiro_test.h"
#include "../include/comandos_test.h" 
#include "../include/condicoes_test.h"
#include "../include/stackMats_test.h" 
#include "../include/listasFunc_test.h" 
#include "../include/queueFunc_test.h" 
#include "../include/dicas_test.h"
#include "../include/resolve_test.h" 
#include <stdio.h>

int main() {
    CU_initialize_registry();
    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;

    pSuite = CU_add_suite("test_suite", 0, 0);

    CU_add_test(pSuite, "testar_dicas", testar_dicas);

    CU_add_test(pSuite, "testar_resolve", testar_resolve);  

    CU_add_test(pSuite, "testar_leMatriz", testar_leMatriz);
    
    CU_add_test(pSuite, "testar_lestackMat", testar_leStackMat);

    CU_add_test(pSuite, "testar_leFicheiro", testar_leFicheiro);

    CU_add_test(pSuite, "testar_leNumero", testar_leNumero);

    CU_add_test(pSuite, "testar_gravaMatriz", testar_gravaMatriz);

    CU_add_test(pSuite, "testar_gravaStackMats", testar_gravaStackMat);

    CU_add_test(pSuite, "testar_gravaFicheiro", testar_gravaFicheiro);

    CU_add_test(pSuite, "testar_riscar", testar_riscar);

    CU_add_test(pSuite, "testar_branco", testar_branco);

    CU_add_test(pSuite, "testar_escolheComandos", testar_escolheComandos);

    CU_add_test(pSuite, "testar_verifRiscadaOrt", testar_verifRiscadaOrt);

    CU_add_test(pSuite, "testar_verifBranco", testar_verifBranco);

    CU_add_test(pSuite, "testar_verificar", testar_verificar);

    CU_add_test(pSuite, "testar_verificaCaminho", testar_verificaCaminho);

    CU_add_test(pSuite, "testar_leMatriz", testar_leMatriz);
    
    CU_add_test(pSuite, "testar_lestackMat", testar_leStackMat);

    CU_add_test(pSuite, "testar_leFicheiro", testar_leFicheiro);

    CU_add_test(pSuite, "testar_leNumero", testar_leNumero);

    CU_add_test(pSuite, "testar_gravaMatriz", testar_gravaMatriz);

    CU_add_test(pSuite, "testar_gravaStackMats", testar_gravaStackMat);

    CU_add_test(pSuite, "testar_gravaFicheiro", testar_gravaFicheiro);
     
    CU_add_test(pSuite, "testar_riscar", testar_riscar);

    CU_add_test(pSuite, "testar_branco", testar_branco);

    CU_add_test(pSuite, "testar_verifRiscadaOrt", testar_verifRiscadaOrt);

    CU_add_test(pSuite, "testar_verifBranco", testar_verifBranco);

    CU_add_test(pSuite, "testar_verificar", testar_verificar);
    
    CU_add_test(pSuite, "testar_verificaCaminho", testar_verificaCaminho);

    CU_add_test(pSuite, "testar_copiaMatriz", testar_copiaMatriz);

    CU_add_test(pSuite, "testar_initStackMat", testar_initStackMat);

    CU_add_test(pSuite, "testar_isEmpty", testar_isEmpty);
    
    CU_add_test(pSuite, "testar_isFull", testar_isFull);

    CU_add_test(pSuite, "testar_initMatriz", testar_initMatriz);

    CU_add_test(pSuite, "testar_push", testar_push);

    CU_add_test(pSuite, "testar_pop", testar_pop);

    CU_add_test(pSuite, "testar_posPertencente", testar_posPertence);
    
    CU_add_test(pSuite, "testar_listasIguais", testar_listasIguais);

    CU_add_test(pSuite, "testar_pertenceAoGrupo", testar_pertenceAoGrupo);

    CU_add_test(pSuite, "testar_adicionarPos", testar_adicionarPos);

    CU_add_test(pSuite, "testar_adicionarLista", testar_adicionarLista);

    CU_add_test(pSuite, "testar_initQueue", testar_initQueue);

    CU_add_test(pSuite, "testar_isEmptyQ", testar_isEmptyQ);

    CU_add_test(pSuite, "testar_enqueue", testar_enqueue);

    CU_add_test(pSuite, "testar_dequeue", testar_dequeue);

    CU_add_test(pSuite, "testar_tudoBranco", testar_tudoBranco); 

    CU_add_test(pSuite, "testar_encontraAAXA", testar_encontraAAXA);

    CU_add_test(pSuite, "testar_encontraABA", testar_encontraABA);

    CU_add_test(pSuite, "testar_resolveAAXA", testar_resolveAAXA);

    CU_add_test(pSuite, "testar_resolveABA", testar_resolveABA);

    CU_add_test(pSuite, "testar_retrocedeCaminho", testar_retrocedeCaminho);

    CU_add_test(pSuite, "testar_ganhou", testar_ganhou); 

    CU_basic_run_tests();
    return CU_get_error();
  }