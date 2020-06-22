#include <math.h>
#include "DxLib.h"

#define PI 3.141592654f

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

    int Handle;     // 画像格納用ハンドル
    int Count = 0;
    Handle = LoadGraph("./res/img/pl_test.png"); // 画像のロード

    // while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
/*
        DrawRotaGraph(100, 240 + sin(PI * 2 / 240 * Count) * 200, 1.0, 0.0, Handle, TRUE); //画像の描画
        DrawRotaGraph(500, 240, 1.0 + sin(PI * 2 / 120 * Count) * 0.5, 0.0, Handle, TRUE); //画像の描画
        Count++;
        */

        DrawRotaGraph(420, 400 - sin(PI / 2 / 120 * Count) * 300, 1.0, 0.0, Handle, TRUE); //画像の描画

        DrawRotaGraph(220, 400 - (sin(-PI / 2 + PI / 120 * Count) + 1) / 2 * 300, 1.0, 0.0, Handle, TRUE); //画像の描画

        if (Count < 120) {
            Count++;
        }
        if (CheckHitKey(KEY_INPUT_Z) == 1) {
            Count = 0;
        }
    }

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}//sin( PI*2 / 周期 * Count ) * 振幅 で滑らかに移動などをさせることが多い
