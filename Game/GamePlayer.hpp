#ifndef FIRSTGAME_GAMEPLAYER
#define FIRSTGAME_GAMEPLAYER

#include "../Engine/Graphics/Sprite.hpp"
#include "../Engine/Calculations/Rigidbody.hpp"

class GamePlayer
{
private:
	Rigidbody rb;
	
public:
	GamePlayer();
	GamePlayer(const Sprite _sprite);
	
	void Update();
	void Render();

	Rigidbody& GetRB();
};

#endif //FIRSTGAME_GAMEPLAYER