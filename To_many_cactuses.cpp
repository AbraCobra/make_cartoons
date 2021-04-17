//========================================================================
//    Cactus starts to multiply (iteration)
//========================================================================

#include "TXLib.h"

void Cactus_drawer (int x, int y, double sizeX, double sizeY, int eyebrows_UP,
                    int eyesCRAZYleft, int eyesPUPILleft, int eyesCRAZYright, int eyesPUPILright,
                    int mouthLOWERpoint);

int main()
    {
    txCreateWindow (1000, 1000);
    txSetFillColor(TX_WHITE);
    POINT fon [4] = {{0, 0}, {1000, 0}, {1000, 1000}, {0, 1000}};
    txPolygon (fon, 4);

    int t = 0;
    while (t <= 590)
        {

        Cactus_drawer (10 + t, 200 + t, 0.4, 0.4, 0 + t/30, 10 + t/20,
                        0 + t/70, 10 + t/20, 0 + t/70, 0 - t/18);
        t += 70;

        }

    return 0;
    }

void Cactus_drawer (int x, int y, double sizeX, double sizeY, int eyebrows_UP,
                    int eyesCRAZYleft, int eyesPUPILleft, int eyesCRAZYright, int eyesPUPILright,
                    int mouthLOWERpoint)
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
    txLine (x + ROUND (192*sizeX), y - ROUND ((240 - eyebrows_UP)*sizeY), x + ROUND (127*sizeX), y - ROUND ((240 + eyebrows_UP)*sizeY));
    txLine (x + ROUND (237*sizeX), y - ROUND ((240 - eyebrows_UP)*sizeY), x + ROUND (302*sizeX), y - ROUND ((240 + eyebrows_UP)*sizeY));

    txLine (x + 177*sizeX, y - 110*sizeY, x + 217*sizeX, y -  (90 - mouthLOWERpoint)*sizeY);
    txLine (x + 217*sizeX, y - (90 - mouthLOWERpoint)*sizeY, x + 257*sizeX, y - 110*sizeY);

    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_WHITE);
    txEllipse (x + (132 -  eyesCRAZYleft)*sizeX, y - 225*sizeY, x + (187 +  eyesCRAZYleft)*sizeX, y - 155*sizeY);
    txEllipse (x + (247 - eyesCRAZYright)*sizeX, y - 225*sizeY, x + (302 + eyesCRAZYright)*sizeX, y - 155*sizeY);

    txSetFillColor (TX_BLACK);
    txCircle (x + 167*sizeX, y - 185*sizeY, (15 -  eyesPUPILleft)*sizeX);
    txCircle (x + 282*sizeX, y - 185*sizeY, (15 - eyesPUPILright)*sizeX);
    }


