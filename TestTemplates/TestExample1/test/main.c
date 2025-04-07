#include "CUnit.h"
#include "Basic.h"
#include "Console.h"
#include "Automated.h"
#include "math.h"

void test_add() {
    CU_ASSERT(add(2, 3) == 5);
    CU_ASSERT(add(-1, 1) == 0);
}

void test_subtract() {
    CU_ASSERT(subtract(5, 2) == 3);
    CU_ASSERT(subtract(2, 5) == -3);
}

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

int main() {
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    CU_pSuite suite = CU_add_suite("MathTestSuite", init_suite, clean_suite);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((CU_add_test(suite, "test_add", test_add) == NULL) ||
        (CU_add_test(suite, "test_subtract", test_subtract) == NULL)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Basic tests
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // XML output ayarı
    CU_set_output_filename("build/cunit_report");
    CU_automated_run_tests();
    
    //CU_console_run_tests();

    CU_cleanup_registry();

    return 0;
}
