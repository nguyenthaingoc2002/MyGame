#include "BaseObject.h"
#include "CommonFunction.h"
BaseObject::BaseObject(){
    object_ = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}
BaseObject::~BaseObject(){
    Free();
}
bool BaseObject::loadImg(std::string path,SDL_Renderer* screen){
    Free();
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadSurface = IMG_Load ( path.c_str() );
    if(loadSurface != NULL){
        SDL_SetColorKey(loadSurface,SDL_TRUE,SDL_MapRGB(loadSurface->format,COLOR_KEY_R,COLOR_KEY_G,COLOR_KEY_B));
        newTexture = SDL_CreateTextureFromSurface(screen,loadSurface);
        if(newTexture!=NULL){
            rect_.w = loadSurface->w;
            rect_.h = loadSurface->h;
        }
        SDL_FreeSurface(loadSurface);
    }
    object_ = newTexture;
    return object_ != NULL;
}
void BaseObject::Render(SDL_Renderer* screen,const SDL_Rect* clip){
    SDL_Rect renderQuad = {rect_.x ,rect_.y , rect_.w ,rect_.h};
    SDL_RenderCopy(screen,object_,clip,&renderQuad);
}
void BaseObject::Free(){
    if(object_ != NULL){
        SDL_DestroyTexture(object_);
        object_ = NULL;
        rect_.w = 0;
        rect_.h = 0;
    }
}
