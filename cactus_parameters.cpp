//==================================================================
//   Drawing cactus using Function with parameters (2)
//==================================================================

#include "TXLib.h"

void Cactus_drawer (int x, int y);

int main()
    {
    txCreateWindow (1000, 1000);
    txClear();

    Cactus_drawer ( 30, 500);
    Cactus_drawer (530, 500);
    return 0;
    }

void Cactus_drawer (int x, int y)
    {
    txSetColor (RGB (128, 64, 64), 10);
    txSetFillColor (RGB (128, 64, 64));

    POINT pot [4] = {{x, y}, {x + 457, y}, {x + 337, y + 310}, {x + 157, y + 310}};
    txPolygon (pot, 4);

    txSetFillColor (TX_BLACK);
    txEllipse (x + 3, y - 30, x + 460, y + 27);

    txSetColor (TX_GREEN, 5);
    txSetFillColor (RGB (90, 255, 90));

    POINT cactus [8] = {{x + 177, y +  10}, {x +  87, y - 180}, {x + 117, y - 240}, {x + 177, y - 280},
                        {x + 287, y - 280}, {x + 337, y - 240}, {x + 357, y - 180}, {x + 287, y +  10}};
    txPolygon (cactus, 8);

    POINT child_cactus [8] = {{x + 282, y - 280}, {x + 287, y - 360}, {x + 327, y - 405}, {x + 397, y - 410},
                              {x + 452, y - 360}, {x + 457, y - 295}, {x + 417, y - 260}, {x + 337, y - 240}};
    txPolygon (child_cactus, 8);

    txSetColor (TX_BLACK, 5);
    txLine (x + 192, y - 240, x + 127, y - 240);
    txLine (x + 237, y - 240, x + 302, y - 240);

    txLine (x + 177, y - 110, x + 217, y -  90);
    txLine (x + 217, y -  90, x + 257, y - 110);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_WHITE);
    txEllipse (x + 132, y - 225, x + 187, y - 155);
    txEllipse (x + 247, y - 225, x + 302, y - 155);

    txSetFillColor (TX_BLACK);
    txCircle (x + 167, y - 185, 15);
    txCircle (x + 282, y - 185, 15);
    }

