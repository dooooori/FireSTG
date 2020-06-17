#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);//ウィンドウモードに設定
    DxLib_Init();   // DXライブラリ初期化処理
    SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に設定

    int x = 50;//移動用
    int pl_img;
    pl_img = LoadGraph( "./res/img/pl_test.png"); // 画像を格納

    // while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        DrawGraph(x, 100, pl_img, TRUE); //画像の描画
        DrawGraph(x / 2, 200, pl_img, TRUE); //画像の描画
        DrawGraph(x / 4, 300, pl_img, TRUE); //画像の描画
        x = x + 2; // xを2増やす

    }//while内の関数はエラーが起きると0以外を返す
    DxLib_End();    // DXライブラリ終了処理
    return 0;
}