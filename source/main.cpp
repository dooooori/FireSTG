#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ɐݒ�
    DxLib_Init();   // DX���C�u��������������
    SetDrawScreen(DX_SCREEN_BACK); //�`���𗠉�ʂɐݒ�

    int x = 50;//�ړ��p
    int pl_img;
    pl_img = LoadGraph( "./res/img/pl_test.png"); // �摜���i�[

    // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        DrawGraph(x, 100, pl_img, TRUE); //�摜�̕`��
        DrawGraph(x / 2, 200, pl_img, TRUE); //�摜�̕`��
        DrawGraph(x / 4, 300, pl_img, TRUE); //�摜�̕`��
        x = x + 2; // x��2���₷

    }//while���̊֐��̓G���[���N�����0�ȊO��Ԃ�
    DxLib_End();    // DX���C�u�����I������
    return 0;
}