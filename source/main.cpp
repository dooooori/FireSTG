#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    DxLib_Init();   // DX���C�u��������������

    int pl_img;

    pl_img = LoadGraph( "./res/img/pl_test.png"); // �摜���i�[

    DrawGraph(50, 100, pl_img, TRUE); // �f�[�^�n���h�����g���ĉ摜��`��

    WaitKey();      // �L�[���͑҂�
    DxLib_End();    // DX���C�u�����I������
    return 0;
}