#include "YBoard.h"

void YBoard<Cells::Cell_Y>::InitBoard()
{
    for (int index1 = 0; index1 <= m_cells; index1++)
    {
        std::vector<Cells::Cell_Y> aux;
        for (int index2 = 0; index2 <= index1; index2++)
        {
            Cells::Cell_Y obj;
            if (index2 == 0)
                obj.edge.left = true;
            if (index1 == index2)
                obj.edge.right = true;
            if (index1 == m_cells )
                obj.edge.bottom = true;

            obj.color = Player::Color::white;
            obj.visited = false;

            aux.push_back(obj);
        }
        m_board.push_back(aux);
    }
}
