#include "SphereCollider.h"
#include"math.h"

//�R���X�g���N�^
SphereCollider::SphereCollider(T_location location, float radius)
{
	this->location.x = location.x;
	this->location.y = location.y;
	this->radius = radius;
}

//SphereCollider�^���m�̓����蔻��
bool SphereCollider::HitSphere(const SphereCollider* collider) const
{

	//�����Ƒ���Ƃ̊Ԃ̃x�N�g�����v�Z
	float vectorX = fabsf(this->location.x - collider->GetLocation().x);
	float vectorY = fabsf(this->location.y - collider->GetLocation().y);

	//�x�N�g���̑傫�����v�Z�ŋ��߂�
	float vectorLength = (vectorX * vectorX) + (vectorY * vectorY);
	vectorLength = sqrtf(vectorLength);

	//�����Ƒ���̔��a�̍��v�l���v�Z
	float sumRadius = radius + collider->GetRadius();

	//�����蔻��̌��ʂ��i�[
	bool ret = (vectorLength < sumRadius);

	return ret;
}

//���S���W���擾
T_location SphereCollider::GetLocation() const
{
	return location;
}

//���S���W�̐ݒ�
void SphereCollider::SetLocation(T_location location)
{
	this->location.x = location.x;
	this->location.y = location.y;
}

//���a�̎擾
float SphereCollider::GetRadius() const
{
	return radius;
}