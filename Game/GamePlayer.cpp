#include "GamePlayer.hpp"

GamePlayer::GamePlayer()
{

}

GamePlayer::GamePlayer(const Sprite _sprite)
{
	//setup sprite-like
	rb.SetPos(Vector2(_sprite.GetValue('x'), _sprite.GetValue('y')));
	rb.SetScaleTo(Vector2(1, 1));
	rb.SetSpeedTo(Vector2(0, 0));
	rb.SetSizeTo(Vector2(_sprite.GetTexture().getWidth(), _sprite.GetTexture().getHeight()));
	rb.SetRotTo(0.0F);
	rb.SetRotSpeed(0.0F);

	rb.SetFriction(1.0F);
	rb.SetGravity(0.1F);
}

void GamePlayer::Update()
{
	rb.UpdateSprite(); //update like sprite
	rb.UpdateRB();
}

void GamePlayer::Render()
{
	rb.RenderSprite(); //render like sprite
	rb.RenderRB(0,0,0); //passing color 0,0,0 - black
}


Rigidbody& GamePlayer::GetRB()
{
	return rb;
}