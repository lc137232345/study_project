#include <gtest/gtest.h>
#include <iostream>
class UmmTest : public ::testing::Test
{
public:
    UmmTest() = default;

    ~UmmTest() = default;

    void SetUp() override
    {
        std::cout << "SetUp" << std::endl;
        Umm_dbg_attach_process();
    }

    void TearDown() override
    {
        std::cout << "TearDown" << std::endl;
    }

protected:
    uint32_t result_u32;
    uint32_t result_s32;
    uint32_t print_level;
    uint16_t u16CellId = 1;
    uint16_t u16T_crnit = 0x2900;
    uint16_t u16Gid = 0;

    void Umm_dbg_attach_process();
};