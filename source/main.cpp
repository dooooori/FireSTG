#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);//ウィンドウモードに設定
    DxLib_Init();   // DXライブラリ初期化処理
    SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に設定

    int x = 50;//移動用
    int pl_img;
    pl_img = LoadGraph( "./res/img/pl_test.png"); // 画像を格納

    while (1) {
        ProcessMessage();//特定の場所でループする場合定期的に呼ぶ必要がある
        if (ProcessMessage() != 0) {//×ボタンは0以外を返す
            break;
        }
        ClearDrawScreen();
        DrawGraph(x, 100, pl_img, TRUE); // データハンドルを使って画像を描画
        x += 2;
        ScreenFlip(); //裏画面を表画面に反映 モニターのHz分待機
    }
    DxLib_End();    // DXライブラリ終了処理
    return 0;
}