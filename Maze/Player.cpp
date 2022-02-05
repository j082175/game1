#include "pch.h"
#include "Player.h"
#include "Board.h"
void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	Pos pos = _pos;

	// 목적지 도착하기 전에는 계속 실행
	Pos dest = board->GetExitPos();

	while (pos != dest)
	{
		// 
	}
}

void Player::Update(uint64 deltaTick)
{
}
