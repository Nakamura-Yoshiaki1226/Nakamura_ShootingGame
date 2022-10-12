#pragma once
#include"common.h"

class SphereCollider
{
private:
	T_location location;//中心座標
	float radius;//半径

public:
	SphereCollider(T_location location, float radius);

public:
	bool HitSphere(const SphereCollider* collider) const;//SphereCollider当たり判定

	T_location GetLocation() const;//中心座標を取得
	void SetLocation(T_location location);//中心座標の設定

	float GetRadius() const;//半径の取得
};