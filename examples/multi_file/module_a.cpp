#include "ottu.hpp"

/* Boolean checks group */
OTTUNITY_GROUP(module_a);

OTTUNITY_GROUP_TEST_SETUP(module_a) {
    // No setup needed
}

OTTUNITY_GROUP_TEST_TEAR_DOWN(module_a) {
    // No teardown needed
}

OTTUNITY_GROUP_TEST(module_a, always_true) {
    TEST_ASSERT_TRUE_MESSAGE(true, "This should always be true");
}

OTTUNITY_GROUP_TEST(module_a, always_false) {
    TEST_ASSERT_FALSE_MESSAGE(false, "This should always be false");
}
