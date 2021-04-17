//========================================================================
//   Drawing cactus. Using function with additional parameters of size (3)
//========================================================================

#include "TXLib.h"

void Cactus_drawer (int x, int y, double sizeX, double sizeY);

int main()
    {
    txCreateWindow (1000, 1000);
    txClear();

    Cactus_drawer ( 50, 500, 0.6, 0.6);
    Cactus_drawer (350, 500, 0.5, 0.5);
    Cactus_drawer (600, 500, 0.3, 0.3);
    Cactus_drawer (750, 500, 0.2, 0.2);


    return 0;
    }

void Cactus_drawer (int x, int y, double sizeX, double sizeY)
    {
    txSetColor (RGB (128, 64, 64), 10);
    txSetFillColor (RGB (128, 64, 64));

    POINT pot[4] = {{x, y}, {x + ROUND (457*sizeX), y}, {x + ROUND (337*sizeX), y + ROUND (310*sizeY)},
                            {x + ROUND (157*sizeX), y + ROUND (310*sizeY)}};
    txPolygon (pot, 4);

    txSetFillColor (TX_BLACK);
    txEllipse (x + ROUND (3*sizeX), y - ROUND (30*sizeY), x + ROUND (460*sizeX), y + ROUND (27*sizeY));

    txSetColor (TX_GREEN, 5);
    txSetFillColor (RGB (90, 255, 90));

    POINT cactus [8] = {{x + ROUND (177*sizeX), y + ROUND ( 10*sizeY)}, {x + ROUND ( 87*sizeX), y - ROUND (180*sizeY)},
                        {x + ROUND (117*sizeX), y - ROUND (240*sizeY)}, {x + ROUND (177*sizeX), y - ROUND (280*sizeY)},
                        {x + ROUND (287*sizeX), y - ROUND (280*sizeY)}, {x + ROUND (337*sizeX), y - ROUND (240*sizeY)},
                        {x + ROUND (357*sizeX), y - ROUND (180*sizeY)}, {x + ROUND (287*sizeX), y + ROUND ( 10*sizeY)}};
    txPolygon (cactus, 8);

    POINT child_cactus [8] = {{x + ROUND (282*sizeX), y - ROUND (280*sizeY)}, {x + ROUND (287*sizeX), y - ROUND (360*sizeY)},
                              {x + ROUND (327*sizeX), y - ROUND (405*sizeY)}, {x + ROUND (397*sizeX), y - ROUND (410*sizeY)},
                              {x + ROUND (452*sizeX), y - ROUND (360*sizeY)}, {x + ROUND (457*sizeX), y - ROUND (295*sizeY)},
                              {x + ROUND (417*sizeX), y - ROUND (260*sizeY)}, {x + ROUND (337*sizeX), y - ROUND (240*sizeY)}};
    txPolygon (child_cactus, 8);

    txSetColor (TX_BLACK, 5);
    txLine (x + ROUND (192*sizeX), y - ROUND (240*sizeY), x + ROUND (127*sizeX), y - ROUND (240*sizeY));
    txLine (x + ROUND (237*sizeX), y - ROUND (240*sizeY), x + ROUND (302*sizeX), y - ROUND (240*sizeY));

    txLine (x + 177*sizeX, y - 110*sizeY, x + 217*sizeX, y -  90*sizeY);
    txLine (x + 217*sizeX, y -  90*sizeY, x + 257*sizeX, y - 110*sizeY);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_WHITE);
    txEllipse (x + 132*sizeX, y - 225*sizeY, x + 187*sizeX, y - 155*sizeY);
    txEllipse (x + 247*sizeX, y - 225*sizeY, x + 302*sizeX, y - 155*sizeY);

    txSetFillColor (TX_BLACK);
    txCircle (x + 167*sizeX, y - 185*sizeY, 15*sizeX);
    txCircle (x + 282*sizeX, y - 185*sizeY, 15*sizeX);
    }
