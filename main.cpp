#include "CommonFunction.h"
#include "BaseObject.h"
#include <iostream>
using namespace std ;




SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Event gEvent;
BaseObject background ;





bool Init()
{
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        return false;
    }
    else{
        gWindow = SDL_CreateWindow("NguyenThaiNgoc-20020208",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow==NULL){
            return false;
        }
        else{
            SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

            gRenderer = SDL_CreateRenderer(gWindow,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(gRenderer == NULL){
                return false;
            }
            else{
				SDL_SetRenderDrawColor( gRenderer,RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR );

				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
                    {
                    return false;
                    }
                }
            }
    }
    return true;
}

void close(){
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    gWindow = NULL;
    gRenderer = NULL;

    SDL_Quit();
    IMG_Quit();

}

int main ( int argc , char * argv [] )
{
    if(!Init()){
        return -1;
    }
    if(!background.loadImg("image//background.png",gRenderer)){
        return -1;
    }

    bool is_quit = false ;
    while ( !is_quit )
    {
        while ( SDL_PollEvent (&gEvent) != 0  )
        {
            if ( gEvent.type == SDL_QUIT )
            {
                is_quit = true ;
            }
        }
        SDL_SetRenderDrawColor(gRenderer , RENDER_DRAW_COLOR , RENDER_DRAW_COLOR , RENDER_DRAW_COLOR , RENDER_DRAW_COLOR ) ;
        SDL_RenderClear (gRenderer);
        background.Render(gRenderer,NULL);
        SDL_RenderPresent(gRenderer) ;
    }
    close() ;
    return 0;
}
