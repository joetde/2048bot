
typedef unsigned int uint;

enum move
{
    UP=0, RIGHT, DOWN, LEFT
};

struct position
{
    position(uint i = 0, uint j = 0) : i(i), j(j) {}
    uint i;
    uint j;
};

/**
 * @brief The GameMatrix class (square matrix, size x size)
 */
class GameMatrix
{
public:
    /**
     * @brief GameMatrix constructor
     * @param m input matrix
     * @param size
     */
    GameMatrix(uint **m, uint size);

    /**
     *  @brief GameMatrix destructor
     */
    ~GameMatrix();

    /**
     * @brief GameMatrix constructor
     * @param copy
     */
    GameMatrix(const GameMatrix &copy);

private:
    uint _size;

    /**
     * @brief _get_pos, helper function to have only one way to treat positions
     * @param i
     * @param j
     * @param m
     * @return real position
     */
    position _get_pos(uint i, uint j, move m);

    /**
     * @brief _get_at, helper function to get value (relies _get_pos)
     * @param i
     * @param j
     * @param m
     * @return value in the real position
     */
    uint _get_at(uint i, uint j, move m);

    /**
     * @brief _set_at, helper function to set vale (relies on _get_pos)
     * @param i
     * @param j
     * @param m
     * @param value
     */
    void _set_at(uint i, uint j, move m, uint value);
};
