#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ɐݒ�
    DxLib_Init();   // DX���C�u��������������
    SetDrawScreen(DX_SCREEN_BACK); //�`���𗠉�ʂɐݒ�

    int x = 50;//�ړ��p
    int pl_img;
    pl_img = LoadGraph( "./res/img/pl_test.png"); // �摜���i�[

    while (1) {
        ProcessMessage();//����̏ꏊ�Ń��[�v����ꍇ����I�ɌĂԕK�v������
        if (ProcessMessage() != 0) {//�~�{�^����0�ȊO��Ԃ�
            break;
        }
        ClearDrawScreen();
        DrawGraph(x, 100, pl_img, TRUE); // �f�[�^�n���h�����g���ĉ摜��`��
        x += 2;
        ScreenFlip(); //����ʂ�\��ʂɔ��f ���j�^�[��Hz���ҋ@
    }
    DxLib_End();    // DX���C�u�����I������
    return 0;
}