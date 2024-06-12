#include <stdlib.h>
#include <time.h> 
#include "../include/Objects.h"


Objects::Objects(std::string sprite_folder):
    Sprite("img/default.png"),
    state(drop)
{ 
   std::string anim_folder[5] = {"drop","stationary","inventory","air","explode"};
   int anim_frame_n[5] = {1,1,1,1,1};
   for (int i = 0; i < 5; i++)
   {
        std::string anim_folder_i=sprite_folder+anim_folder[i];
        for (int k = 0; k < anim_frame_n[i]; k++)
        {
            std::string anim_frame=anim_folder_i+"/"+ std::to_string(k)+".png";
            Texture new_frame(anim_frame.c_str());
            animation[i].push_back(new_frame);
        }
        
   }
    setPosition(Vector2f(-10,-10));
    setSize(Vector2f(50,50));
    framecount=0;
}
void Objects::update(Vector2f Movement){
    move(Movement);
    if (prstate!=acstate)
    {
        framecount=0; 
    }
    switch (state)
    {
        case drop:
            move(Vector2f(0,4));
            setTexture(animation[state][framecount/5]);
            break;
        case stationary:
            setTexture(animation[state][framecount/5]);
            break;
        case air:
            if (framecount>=25)
            {
                framecount=0;
            }
            setTexture(animation[state][framecount/5]);
            move(Vector2f(speed/mass,speed/mass));
            break;
        case inventory:
            setTexture(animation[state][0]);
            break;
        case explode:
            setTexture(animation[state][framecount/5]);
            break;
    }
    framecount++;    
}
void Objects::spawn(Vector2f point)
{
    setPosition(Vector2f(point.x,point.y-40));
    state=drop;
}
void Objects::trhow(Vector2f launch){
    state=air;
    move(launch);
}
Vector2f Objects::touch(CollisionBox* box){
    for (int i = 0; i < sizeof(box); i++)
    {
        if (explosion.check(box[i]));
        {
            return box[i].getPosition();
        }else{
            return Vector2f(0,0);
        }
        
    }
    
}





