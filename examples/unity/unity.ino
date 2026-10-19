#include "ottu.hpp"

/**
 * This example uses the Unity framework and Unity Fixture
 * directly in an Arduino sketch.
 *
 * To add a test, you need to:
 *
 * 1. Define a TEST_GROUP.
 * 2. Define TEST_SETUP and TEST_TEAR_DOWN functions for the
 *    group.
 * 3. Define the test cases in the group.
 * 4. Define a TEST_GROUP_RUNNER that adds all the group's
 *    test cases.
 * 5. Define a runner function that calls all the
 *    TEST_GROUP_RUNNERs.
 * 6. Implement the Arduino setup() function to initialize
 *    the Serial interface.
 * 7. Call UnityMain with the runner function.
 *
 * This requires considerable boilerplate, especially when
 * multiple test groups are bundled into a single test
 * executable.
 *
 * The macros also avoid duplicating function definitions
 * for each test group, which would cause compilation errors.
 *
 * Using separate test groups is useful not only for
 * modularity, but also because different groups may need
 * different setup and teardown functions.
 *
 * However, some of this boilerplate could be eliminated,
 * including:
 * - Defining a TEST_GROUP_RUNNER function for each group
 * - Defining a runner function that calls all the
 *   TEST_GROUP_RUNNERs
 *
 * Ideally, all defined tests would be included in a runner
 * function automatically, or at least with simpler syntax.
 *
 * The same applies to Arduino's mandatory setup() and loop()
 * functions. If they are used only to run tests, their
 * implementations can remain the same, provided the function
 * that runs all the group runners has a consistent name.
 *
 * In addition, most sketches use only one test group. Unlike
 * on a desktop, where a single executable can bundle multiple
 * test groups and runners, isolating tests and ensuring
 * reproducible initial conditions on embedded devices can be
 * difficult without resetting the hardware between tests.
 *
 * In such cases, it may make sense to run tests for a single
 * module in each binary loaded onto the device. Tests can
 * then be grouped by file, making the boilerplate redundant
 * and cumbersome.
 *
 * Ideally, you would need to define only TEST_SETUP,
 * TEST_TEAR_DOWN, and the test cases.
 *
 * Ceedling provides a similar boilerplate-free approach for
 * desktop tests through automatic code generation. The
 * ottunity test framework aims to provide a similarly simple
 * way to add tests and test files.
 *
 * To keep the Arduino library simple and avoid code
 * generation, we accept some boilerplate rather than
 * eliminating it entirely, while still simplifying the
 * process significantly.
 *
 * See the basic.ino example for a demonstration.
 */

TEST_GROUP(numeric_check);

TEST_SETUP(numeric_check) { 
    /* no setup */ 
}

TEST_TEAR_DOWN(numeric_check) { 
    /* no teardown */
}

TEST(numeric_check, test_greater_than) {
    TEST_ASSERT_GREATER_THAN_INT_MESSAGE(5, 10, "10 should be greater than 5");
}

TEST(numeric_check, test_less_than) {
    TEST_ASSERT_LESS_THAN_INT_MESSAGE(3, 1, "1 should be less than 3");
}

TEST_GROUP_RUNNER(numeric_check) {
    RUN_TEST_CASE(numeric_check, test_greater_than);
    RUN_TEST_CASE(numeric_check, test_less_than);
}

void run_all_tests() {
    RUN_TEST_GROUP(numeric_check);
};

void setup() {
    /* The Serial interface is used as Unity's standard output. */
    Serial.begin(115200);
    while (!Serial) { ; } 
} 
    
void loop() { 
    const int   argc       = 2; 
    const char *argv[argc] = { "", "-v" }; 
    UnityMain(argc, argv, run_all_tests);
    
    while(true) {} /* Run the tests just once.*/
} 