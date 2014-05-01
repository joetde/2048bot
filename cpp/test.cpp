
#include <gtest/gtest.h>
#include <GameMatrix.h>

TEST(GameMatrixTest, GetPosTest)
{
    uint matrix[4][4]   = {{0,0,0,0},{0,2,0,0},{0,0,2,0},{0,0,0,0}};
    GameMatrix gm(matrix);
    EXPECT_TRUE(gm._get_pos(2, 3, UP) == position(3, 2));
    EXPECT_TRUE(gm._get_pos(2, 3, DOWN) == position(0, 2));
    EXPECT_TRUE(gm._get_pos(2, 3, RIGHT) == position(2, 0));
    EXPECT_TRUE(gm._get_pos(2, 3, LEFT) == position(2, 3));
}

TEST(GameMatrixTest, SimulateMoveSimple)
{
    uint ref[4][4]   = {{0,0,0,0},{0,2,0,0},{0,0,2,0},{0,0,0,0}};
    uint exp[4][4][4]    = {{{0,2,2,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
                            {{0,0,0,0},{0,0,0,2},{0,0,0,2},{0,0,0,0}},
                            {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,2,2,0}},
                            {{0,0,0,0},{2,0,0,0},{2,0,0,0},{0,0,0,0}}};
    GameMatrix g_ref(ref);
    for (uint m=0; m<4; ++m)
    {
        GameMatrix g_exp(exp[m]);
        GameMatrix g_res = g_ref.simulate_move((move)m);
        g_exp.dump();
        g_res.dump();
        EXPECT_TRUE(g_exp == g_res);
    }

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
