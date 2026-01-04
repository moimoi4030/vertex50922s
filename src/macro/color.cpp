#include "helpers.hpp"
#include "main.h"
#include "macro/color.hpp"
#include "globals.hpp"
#include "pros/vision.h"

// color sort
const int NONE = 0;
const int RED = 1;
const int BLUE = 2;


void redSort() { 
    if(optical.get_hue() > 340 || optical.get_hue() < 20) {
        TopRoller.move_velocity(-600);
    } else {
        TopRoller.move_velocity(600);
    }
}

void blueSort() { 
    if(optical.get_hue() > 210 && optical.get_hue() < 270) {
        TopRoller.move_velocity(-600);
    } else {
        TopRoller.move_velocity(600);
    }
}

/*void autoSort(int color) {
    vision.set_auto_white_balance(true);
    vision.set_exposure(37);
    
    pros::vision_signature_s_t RED_BALLS = vision.signature_from_utility(RED, 12655, 13829, 13242, -1, 307, 153, 11.000, 0);
    pros::vision_signature_s_t BLUE_BALLS = vision.signature_from_utility(BLUE, -3355, -2731, -3043, 6117, 7581, 6849, 4.200, 0);
    vision.set_signature(1, &RED_BALLS);
    vision.set_signature(2, &BLUE_BALLS);


    while(true) {
        pros::vision_object_s_t obj = vision.get_by_size(0);
        if(color == RED && obj.signature == 1) {
            sup3.move_velocity(600);
        } else if(color == RED && obj.signature != 1) { 
            stop();
        }
        pros::delay(10);
    }
}*/

