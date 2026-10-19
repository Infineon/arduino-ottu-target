#include "ottu.hpp"

OTTUNITY_TEST(is_null_pointer)
{
    int* ptr = nullptr;

    TEST_ASSERT_NULL_MESSAGE(ptr, "Pointer should be null");
}

OTTUNITY_TEST(does_truth_exist) {
    bool truth = false;
    
    TEST_ASSERT_FALSE(truth);
}

OTTUNITY_RUN();