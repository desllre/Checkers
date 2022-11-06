#include "exitWindow.h"

Exit::Exit(): background(BACKGROUND_IMAGE),
              accept(SIZE_BUTTON, THICKNESS, POS_X,
                              (POS_Y + CONST_DISPLACEMENT), COLOR_OUTLINE, COLOR_TEXT,
                              TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                              (POS_TEXT_Y + CONST_DISPLACEMENT), "ACCEPT"),
              cancel(SIZE_BUTTON, THICKNESS, POS_X,
                          (POS_Y + 2 * CONST_DISPLACEMENT), COLOR_OUTLINE, COLOR_TEXT,
                          TEXT_SIZE, PATH_FONTS, POS_TEXT_X,
                          (POS_TEXT_Y + 2 * CONST_DISPLACEMENT), "CANCEL") {}