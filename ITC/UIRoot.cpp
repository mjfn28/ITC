#include "UIRoot.h"
#include "Settings.h"

UIRoot::UIRoot(Entity* holder)
	:Renderable(holder), InputHandler(holder), Component(holder)
{
	Root = nullptr;
}

void UIRoot::HandleMouseDown(int x, int y)
{
	Root->HandleMouseDown(x, y);
}

void UIRoot::HandleMouseMove(int x, int y)
{
	Root->HandleMouseMove(x, y);
}

void UIRoot::Render(SDL_Renderer* renderer)
{
	//Render text
	SDL_Rect locationLabelRect;
	SDL_QueryTexture(Root->GetTexture(renderer), nullptr, nullptr, &locationLabelRect.w, &locationLabelRect.h);
	SDL_Rect rect2 = { 0, Settings::getInstance().ScreenHeight - locationLabelRect.h, locationLabelRect.w, locationLabelRect.h };

	SDL_RenderCopy(renderer, Root->GetTexture(renderer), NULL, &rect2);
}