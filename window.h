#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cmath>


class GameWindow {
	private:
		SDL_Rect* drawrect;
	public:
		Camera* camera;
		SDL_Window *win = NULL;
		SDL_Renderer *renderer = NULL;
		SDL_Texture* textureFromSurface(SDL_Surface* sur);
		void draw(SDL_Texture* tex, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
		void draw(SDL_Texture* tex, const SDL_Rect* srcrect, const SDL_Rect* dstrect, const double angle, const SDL_Point* center, const SDL_RendererFlip flip);
		void drawOverride(SDL_Texture* tex, const SDL_Rect* srcrect, const SDL_Rect* dstrect);
		void drawOverride(SDL_Texture* tex, const SDL_Rect* srcrect, const SDL_Rect* dstrect, const double angle, const SDL_Point* center, const SDL_RendererFlip flip);
		Vector2 getMousePosition();
		void clear();
		void present();
		GameWindow();
		int init();
};