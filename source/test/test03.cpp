#include "DxLib.h"

int Key[256]; // �L�[��������Ă���t���[�������i�[����

// �L�[�̓��͏�Ԃ��X�V����
int gpUpdateKey() {
    char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
    GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
            Key[i]++;     // ���Z
        }
        else {              // ������Ă��Ȃ����
            Key[i] = 0;   // 0�ɂ���
        }
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

    int Handle, Count = 0;
    Handle = LoadSoundMem("./res/se/000029ab.wav"); // wav�����[�h���A���ʔԍ���Handle�Ɋi�[

    int x = 0;



    // while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {

        if (Count % 120 == 0) { // 2�b�Ɉ�x
        //    PlaySoundMem(Handle, DX_PLAYTYPE_BACK); // ���ʉ����Đ�����
        }
        Count++;

        DrawFormatString(x, 0, GetColor(255, 255, 255), "?!");
        if (Key[KEY_INPUT_RIGHT] == 1) {
            x = x + 50;
        }

    }

    DxLib_End(); // DX���C�u�����I������
    return 0;
}