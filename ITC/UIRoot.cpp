#include "UIRoot.h"
#include "Settings.h"
#include "Player.h"

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
	SDL_Rect rootRect;
	SDL_QueryTexture(Root->GetTexture(renderer), nullptr, nullptr, &rootRect.w, &rootRect.h);
	Vector2 pos = Root->GetAbsolutePosition();
	SDL_Rect rect2 = { pos.x, pos.y, rootRect.w, rootRect.h };

	SDL_RenderCopy(renderer, Root->GetTexture(renderer), NULL, &rect2);
}

void UIRoot::Update()
{
	Player* player = static_cast<Player*>(mHolder); //todo temporary, remove pls. Maybe add context abstract class that holder implements

	player->UpdateUI();
}