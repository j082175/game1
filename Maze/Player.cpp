#include "pch.h"
#include "Player.h"
#include "Board.h"
void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	Pos pos = _pos;

	// ������ �����ϱ� ������ ��� ����
	Pos dest = board->GetExitPos();

	while (pos != dest)
	{
		// 
	}
}

void Player::Update(uint64 deltaTick)
{
}
