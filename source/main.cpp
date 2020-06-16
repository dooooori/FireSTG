#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    DxLib_Init();   // DXライブラリ初期化処理

    int pl_img;

    pl_img = LoadGraph( "./res/img/pl_test.png"); // 画像を格納

    DrawGraph(50, 100, pl_img, TRUE); // データハンドルを使って画像を描画

    WaitKey();      // キー入力待ち
    DxLib_End();    // DXライブラリ終了処理
    return 0;
}