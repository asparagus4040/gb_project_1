#include <gb/gb.h>
#include <stdint.h>
#include "../gen/genheader.h"

void draw16(uint8_t s1,uint8_t s2,uint8_t s3,uint8_t s4, uint8_t x, uint8_t y) {
    move_sprite(s1,x,y);
    move_sprite(s2,x+8,y);
    move_sprite(s3,x,y+8);
    move_sprite(s4,x+8,y+8);
}

void main(void) {
    DISPLAY_ON;
    SHOW_SPRITES;

    int8_t knightX = 0;
    int8_t knightY = 0;

    //Knight
    set_sprite_data(0,1,KnightHeadL_tiles);
    set_sprite_data(1,1,KnightHeadR_tiles);
    set_sprite_data(2,1,KnightLegL1_tiles);
    set_sprite_data(3,1,KnightLegR1_tiles);
    set_sprite_data(4,1,KnightLegL2_tiles);
    set_sprite_data(5,1,KnightLegR2_tiles);
    set_sprite_data(6,1,KnightLegL3_tiles);
    set_sprite_data(7,1,KnightLegR3_tiles);

    //Load knight tiles
    set_sprite_tile(0,0);
    set_sprite_tile(1,1);
    set_sprite_tile(2,2);
    set_sprite_tile(3,3);

    //Show knight
    draw16(0,1,2,3,80,72);

    //Skelly
    set_sprite_data(8,1,SkellyHeadL_tiles);
    set_sprite_data(9,1,SkellyHeadR_tiles);
    set_sprite_data(10,1,SkellyLegL1_tiles);
    set_sprite_data(11,1,SkellyLegR1_tiles);
    set_sprite_data(12,1,SkellyLegL2_tiles);
    set_sprite_data(13,1,SkellyLegR2_tiles);
    set_sprite_data(14,1,SkellyLegL3_tiles);
    set_sprite_data(15,1,SkellyLegR3_tiles);

    //Load skelly tiles
    set_sprite_tile(4,8);
    set_sprite_tile(5,9);
    set_sprite_tile(6,10);
    set_sprite_tile(7,11);

    int8_t skellyX = 32;
    int8_t skellyY = 32;

    //Cursor
    set_sprite_data(16,1,cursor_tiles);

    //Set cursor tile properties
    set_sprite_prop(9,32); // top right
    set_sprite_prop(10,64); // bottom left
    set_sprite_prop(11, 96); // bottom right

    //Load cursor tiles
    set_sprite_tile(8,16);
    set_sprite_tile(9,16);
    set_sprite_tile(10,16);
    set_sprite_tile(11,16);

    int8_t speedX = 0;
    int8_t speedY = 0;
    int8_t targetX = 0;
    int8_t targetY = 0;

    while(1) {

        if (knightX == targetX && knightY == targetY) {
            speedX = 0;
            speedY = 0;
            if(joypad() & J_DOWN) {
                speedY += 1;
                targetY = knightY + 16;
            }
            if(joypad() & J_UP) {
                speedY -= 1;
                targetY = knightY - 16;
            }
            if(joypad() & J_RIGHT) {
                speedX += 1;
                targetX = knightX + 16;
            }
            if(joypad() & J_LEFT) {
                speedX -= 1;
                targetX = knightX - 16;
            }
        } else {
            knightX += speedX;
            knightY += speedY;
        }

        int8_t deltaX = skellyX - knightX;
        int8_t deltaY = skellyY - knightY;

        draw16(4,5,6,7,80+deltaX,72+deltaY);

        int8_t cursorX, cursorY;
        int8_t cdeltaX = skellyX - targetX;
        int8_t cdeltaY = skellyY - targetY;

        if ((uint8_t)(cdeltaX) < 8) {
            cursorX = 0;
        } else {
            if (cdeltaX > 0) {
                cursorX = 16;
            } else {
                cursorX = -16;
            }
        }

        if ((uint8_t)(cdeltaY) < 8) {
            cursorY = 0;
        } else {
            if (cdeltaY > 0) {
                cursorY = 16;
            } else {
                cursorY = -16;
            }
        }

        draw16(8,9,10,11,80+cursorX+targetX-knightX,72+cursorY+targetY-knightY);

        wait_vbl_done();
    }
}
