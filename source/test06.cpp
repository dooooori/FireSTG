#include <math.h>
#include "DxLib.h"

#define PI 3.141592654f

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    int Handle;     // �摜�i�[�p�n���h��
    int Count = 0;
    Handle = LoadGraph("./res/img/pl_test.png"); // �摜�̃��[�h

    // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
/*
        DrawRotaGraph(100, 240 + sin(PI * 2 / 240 * Count) * 200, 1.0, 0.0, Handle, TRUE); //�摜�̕`��
        DrawRotaGraph(500, 240, 1.0 + sin(PI * 2 / 120 * Count) * 0.5, 0.0, Handle, TRUE); //�摜�̕`��
        Count++;
        */

        DrawRotaGraph(420, 400 - sin(PI / 2 / 120 * Count) * 300, 1.0, 0.0, Handle, TRUE); //�摜�̕`��

        DrawRotaGraph(220, 400 - (sin(-PI / 2 + PI / 120 * Count) + 1) / 2 * 300, 1.0, 0.0, Handle, TRUE); //�摜�̕`��

        if (Count < 120) {
            Count++;
        }
        if (CheckHitKey(KEY_INPUT_Z) == 1) {
            Count = 0;
        }
    }

    DxLib_End(); // DX���C�u�����I������
    return 0;
}//sin( PI*2 / ���� * Count ) * �U�� �Ŋ��炩�Ɉړ��Ȃǂ������邱�Ƃ�����
