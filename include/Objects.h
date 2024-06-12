#pragma once
#include <BBOP/Graphics.h>
#include <iostream>
#include <vector>

#include "../include/map.h"

enum object_state:int{drop=0,stationary=1,inventory=2,air=3,explode=4};
class Objects : public Sprite
{
    private:
        float speed; 
        object_state state;
        std::vector<Texture> animation[5];
        int throw_frame_cpt;
        int static_frame_cpt;
        int spawn_frame_cpt;
        int effect_frame_cpt;
        int framecount;
    public:
        Objects(std::string sprite_folder);
        void update(Vector2f Movement);
        virtual void spawn(Vector2f point);
        virtual void trhow(Vector2f launch);
        virtual void touch(Vector2f boxes);
        
};