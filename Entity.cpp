#include "Entity.h"

Entity::Entity()
{
	this->Datas = { 0 };
	this->DatsSize = sizeof(Datas);
};

void Entity::SetCoordinate(POINT point)
{
	/* マウス移動距離保存 */
	this->Datas.Move.x = point.x - this->Datas.Coordinate.x;
	this->Datas.Move.y = point.y - this->Datas.Coordinate.y;

	/* 現在座標保存 */
	this->Datas.Coordinate.x = point.x;
	this->Datas.Coordinate.y = point.y;
}