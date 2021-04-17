//==================================================================
//   Drawing cactus on coordinates (1)
//==================================================================

#include "TXLib.h"

int main()
    {
    txCreateWindow (1000, 1000);
    txClear();

    txSetColor (RGB (128, 64, 64), 10);
    txSetFillColor (RGB (128, 64, 64));

    POINT pot [4] = {{353, 510}, {810, 510}, {690, 820}, {510, 820}};
    txPolygon (pot, 4);

    txSetFillColor (TX_BLACK);
    txEllipse (350, 480, 813, 530);

    txSetColor (TX_GREEN, 5);
    txSetFillColor (RGB (90, 255, 90));

    POINT cactus [8] = {{530, 500}, {440, 330}, {470, 270}, {530, 230},
                        {640, 230}, {690, 270}, {710, 330}, {640, 500}};
    txPolygon (cactus, 8);

    POINT child_cactus [8] = {{635, 230}, {640, 150}, {680, 105}, {750, 100},
                              {805, 150}, {810, 215}, {770, 250}, {690, 270}};
    txPolygon (child_cactus, 8);

    txSetColor (TX_BLACK, 5);
    txLine (545, 270, 480, 270);
    txLine (590, 270, 655, 270);

    txLine (530, 400, 570, 420);
    txLine (570, 420, 610, 400);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_WHITE);
    txEllipse (485, 285, 540, 355);
    txEllipse (600, 285, 655, 355);

    txSetFillColor (TX_BLACK);
    txCircle (520, 325, 15);
    txCircle (635, 325, 15);

    return 0;
    }


