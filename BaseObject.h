#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_
#include "CommonFunction.h"

class BaseObject{
public:
    BaseObject();
    ~BaseObject();

    void SetRect(const int& x,const int& y){rect_.x = x,rect_.y = y;}
    SDL_Rect GetRect()const{return rect_;}
    SDL_Texture* GetObject()const{return object_;}

    bool loadImg(std::string path,SDL_Renderer* screen);
    void Render(SDL_Renderer* screen,const SDL_Rect* clip = NULL);
    void Free();
protected:
    SDL_Rect rect_;
    SDL_Texture* object_;
};



#endif
