#include "DxLib.h"

int Key[256]; // キーが押されているフレーム数を格納する

// キーの入力状態を更新する
int gpUpdateKey() {
    char tmpKey[256]; // 現在のキーの入力状態を格納する
    GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
            Key[i]++;     // 加算
        }
        else {              // 押されていなければ
            Key[i] = 0;   // 0にする
        }
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

    int Handle, Count = 0;
    Handle = LoadSoundMem("./res/se/000029ab.wav"); // wavをロードし、識別番号をHandleに格納

    int x = 0;



    // while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {

        if (Count % 120 == 0) { // 2秒に一度
        //    PlaySoundMem(Handle, DX_PLAYTYPE_BACK); // 効果音を再生する
        }
        Count++;

        DrawFormatString(x, 0, GetColor(255, 255, 255), "?!");
        if (Key[KEY_INPUT_RIGHT] == 1) {
            x = x + 50;
        }

    }

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}