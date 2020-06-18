#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    int bullet01;     // �摜�i�[�p�n���h��
    bullet01 = LoadGraph("./res/img/bullet01.png"); // �摜�̃��[�h
    
    int x = 0, y = 0;
    int Green = GetColor(0, 255, 0);      // �΂̐F�R�[�h���擾

    // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);   //�u�����h���[�h����(128/255)�ɐݒ�
        DrawGraph(100, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(120, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(140, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(160, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(180, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(200, 200, bullet01, TRUE); //�摜�̕`��
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);           //�u�����h���[�h���I�t

        SetDrawBlendMode(DX_BLENDMODE_ADD, 255);             //�u�����h���[�h�����Z(255/255)�ɐݒ�
        DrawGraph(300, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(320, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(340, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(360, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(380, 200, bullet01, TRUE); //�摜�̕`��
        DrawGraph(400, 200, bullet01, TRUE); //�摜�̕`��
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);           //�u�����h���[�h���I�t

        DrawFormatString(x, y, Green, "���W[%d,%d]", x, y); // ������`�悷��

        x = x + 2; // x���W��2���Z
        y = y + 1; // y���W��1���Z


    }

    DxLib_End(); // DX���C�u�����I������
    return 0;
}