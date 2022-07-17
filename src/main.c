#include <gb/gb.h>
#include <stdio.h>
#include "../gen/KingHeader.h"
#include "maps.h"

void main(void) {
    DISPLAY_ON;
    SHOW_SPRITES;
    SHOW_BKG;

    set_bkg_data(0,1,Floor_tiles);
    set_bkg_data(1,1,Brick_tiles);

    unsigned char* Map = CreateMap2();

    set_bkg_tiles(0,0,32,32,Map);

    set_sprite_data(0,1,HelmetLeft_tiles);
    set_sprite_data(1,1,HelmetRight_tiles);

    set_sprite_data(2,1,LegLeft1_tiles);
    set_sprite_data(3,1,LegRight1_tiles);
    set_sprite_data(4,1,LegLeft2_tiles);
    set_sprite_data(5,1,LegRight2_tiles);
    set_sprite_data(6,1,LegLeft1_tiles);
    set_sprite_data(7,1,LegRight1_tiles);
    set_sprite_data(8,1,LegLeft3_tiles);
    set_sprite_data(9,1,LegRight3_tiles);

    set_sprite_tile(0,0);
    set_sprite_tile(1,1);
    set_sprite_tile(2,2);
    set_sprite_tile(3,3);

    move_sprite(0,80,80);
    move_sprite(1,88,80);
    move_sprite(2,80,88);
    move_sprite(3,88,88);

    int anim = 0;
    int counter = 0;

    int offX = 72;
    int offY = 64;
    int posX = offX;
    int posY = offY;

    while(1) {
        int speedX = 0;
        int speedY = 0;
        int running = 0;
        if (joypad() & J_RIGHT) {speedX = 2; running = 1;}
        if (joypad() & J_LEFT) {speedX = -2; running = 1;}
        if (joypad() & J_DOWN) {speedY = 2; running = 1;}
        if (joypad() & J_UP) {speedY = -2; running = 1;}

        if (speedX == 2) {
            set_sprite_prop(0,0);
            set_sprite_prop(1,0);
            set_sprite_prop(2,0);
            set_sprite_prop(3,0);

            move_sprite(0,80,80);
            move_sprite(1,88,80);
            move_sprite(2,80,88);
            move_sprite(3,88,88);
        } else if (speedX == -2) {
            set_sprite_prop(0,32);
            set_sprite_prop(1,32);
            set_sprite_prop(2,32);
            set_sprite_prop(3,32);

            move_sprite(0,88,80);
            move_sprite(1,80,80);
            move_sprite(2,88,88);
            move_sprite(3,80,88);
        }

        if (running == 1) {
            if (anim > 3) {
                anim = 0;
            } else {
                if (counter > 6) {
                    anim += 1;
                    counter = 0;
                } else {
                    counter += 1;
                }
            }
        } else {
            anim = 0;
        }

        set_sprite_tile(2, 2 + (2*anim));
        set_sprite_tile(3, 3 + (2*anim));

        int tileIndex = 32*((posY+speedY)/8) + ((posX+speedX)/8);
        if (tileIndex < 0) {
            posX += 2;
            posY += 2;
        } else if (tileIndex > 1023) {
            posX -= 2;
            posY -= 2;
        } else if (Map[tileIndex] == 0x00) {
            posX += speedX;
            posY += speedY;
        }

        move_bkg(posX - offX, posY - offY);
        wait_vbl_done();
    }
}
