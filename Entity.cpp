#include "Entity.h"

Entity::Entity()
{
	this->Datas = { 0 };
	this->DatsSize = sizeof(Datas);
};

void Entity::SetCoordinate(POINT point)
{
	/* �}�E�X�ړ������ۑ� */
	this->Datas.Move.x = point.x - this->Datas.Coordinate.x;
	this->Datas.Move.y = point.y - this->Datas.Coordinate.y;

	/* ���ݍ��W�ۑ� */
	this->Datas.Coordinate.x = point.x;
	this->Datas.Coordinate.y = point.y;
}