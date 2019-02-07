#include "GamePlayer.hpp"

GamePlayer::GamePlayer()
{

}

GamePlayer::GamePlayer(Sprite& _sprite)
{
	sprite = _sprite;
	rb.Initialize(0.01F, 0.2F, sprite.GetPos(), sprite.GetRot(), sprite.GetScale(), sprite.GetSize());
}

void GamePlayer::Update()
{
	sprite.Update();
	rb.Update();
}

void GamePlayer::Render()
{
	sprite.Render();
	rb.Render(0,0,0); //passing color 0,0,0 - black
}

//Change it (just 4 debug)
Sprite& GamePlayer::GetSprite()
{
	return sprite;
}

Rigidbody& GamePlayer::GetRB()
{
	return rb;
}