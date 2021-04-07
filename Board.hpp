#include "Direction.hpp"
#include <string>
#include <map>

using namespace std;

struct vMap{
    char v = '_';
};

namespace ariel {
    
    class Board{
    
        u_int dRow = 10;
        u_int dColumn = 10;
        std::map<u_int, std::map<u_int, vMap>>my_board;
        

    public:
        Board();
        void post(unsigned int row, unsigned int column,Direction direction ,string message);
        string read(unsigned int row, unsigned int column,Direction direction ,unsigned int length);
        void show();
    };
}