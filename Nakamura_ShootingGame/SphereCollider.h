#pragma once
#include"common.h"

class SphereCollider
{
private:
	T_location location;//���S���W
	float radius;//���a

public:
	SphereCollider(T_location location, float radius);

public:
	bool HitSphere(const SphereCollider* collider) const;//SphereCollider�����蔻��

	T_location GetLocation() const;//���S���W���擾
	void SetLocation(T_location location);//���S���W�̐ݒ�

	float GetRadius() const;//���a�̎擾
};