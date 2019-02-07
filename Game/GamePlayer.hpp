#ifndef FIRSTGAME_GAMEPLAYER
#define FIRSTGAME_GAMEPLAYER

#include "../Engine/Graphics/Sprite.hpp"
#include "../Engine/Calculations/Rigidbody.hpp"

class GamePlayer
{
private:

	Sprite sprite;
	Rigidbody rb;
	
public:
	GamePlayer();
	GamePlayer(Sprite& _sprite);
	
	void Update();
	void Render();

	Sprite& GetSprite();
	Rigidbody& GetRB();
};

#endif //FIRSTGAME_GAMEPLAYER