#include"SceneManager.h"

// �����o�ϐ��̒l������������̂��A�b�v�f�[�g�֐�
void SceneManager::Update() {
    // ���݃V�[���̃A�b�v�f�[�g�����s
    mScene->Update();
}

// �`�揈���݂̂��s���֐�
void SceneManager::Draw() const {
    // ���݃V�[���̕`��֐������s
    mScene->Draw();
}

//�V�[���̕ύX����
AbstractScene* SceneManager::ChangeScene() {

    //�V�[���̕ύX��т���
    AbstractScene* nextScene = mScene->ChangeScene();

    //���̃V�[�������݂̃V�[���ƕʂȂ�ύX
    if (nextScene != mScene)
    {
        delete mScene;
        mScene = nextScene;
    }

    return nextScene;

}