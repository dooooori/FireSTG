#include "DxLib.h"

#define PI 3.141592654

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);//�E�B���h�E���[�h�ɐݒ�
    DxLib_Init();   // DX���C�u��������������
    SetDrawScreen(DX_SCREEN_BACK); //�`���𗠉�ʂɐݒ�

    int x = 50;//�ړ��p
    int pl_img;
    pl_img = LoadGraph( "./res/img/pl_test.png"); // �摜���i�[

    int bullet01;
    bullet01= LoadGraph("./res/img/bullet01.png"); // �摜���i�[

    // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        /*
        DrawGraph(x, 100, pl_img, TRUE); //�摜�̕`��
        x = x + 2; // x��2���₷
        
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		//�u�����h���[�h����(128/255)�ɐݒ� �����x
        DrawRotaGraph(100, 200, 2.0, PI/4, pl_img, TRUE);//x,y,�g��,�p�x,�摜�ϐ�,����
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//�u�����h���[�h���I�t 
        
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);   //�u�����h���[�h����(128/255)�ɐݒ�
        DrawGraph(100, 200, pl_img, TRUE); //�摜�̕`��
        DrawGraph(120, 200, pl_img, TRUE); //�摜�̕`��
        DrawGraph(140, 200, pl_img, TRUE); //�摜�̕`��
        DrawGraph(160, 200, pl_img, TRUE); //�摜�̕`��
        DrawGraph(180, 200, pl_img, TRUE); //�摜�̕`��
        DrawGraph(200, 200, pl_img, TRUE); //�摜�̕`��
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);           //�u�����h���[�h���I�t
        */

        SetDrawBlendMode(DX_BLENDMODE_ADD, 255);             //�u�����h���[�h�����Z(255/255)�ɐݒ�
        DrawGraph(300, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(320, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(340, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(360, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(380, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(400, 200, bullet01, TRUE); //�摜�̕`��
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);           //�u�����h���[�h���I�t

    }//while���̊֐��̓G���[���N�����0�ȊO��Ԃ�

    DxLib_End();    // DX���C�u�����I������
    return 0;
}