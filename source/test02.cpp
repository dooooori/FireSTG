#include "DxLib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

    int bullet01;     // 画像格納用ハンドル
    bullet01 = LoadGraph("./res/img/bullet01.png"); // 画像のロード
    
    int x = 0, y = 0;
    int Green = GetColor(0, 255, 0);      // 緑の色コードを取得

    // while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);   //ブレンドモードをα(128/255)に設定
        DrawGraph(100, 200, bullet01, TRUE); //画像の描画
        DrawGraph(120, 200, bullet01, TRUE); //画像の描画
        DrawGraph(140, 200, bullet01, TRUE); //画像の描画
        DrawGraph(160, 200, bullet01, TRUE); //画像の描画
        DrawGraph(180, 200, bullet01, TRUE); //画像の描画
        DrawGraph(200, 200, bullet01, TRUE); //画像の描画
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);           //ブレンドモードをオフ

        SetDrawBlendMode(DX_BLENDMODE_ADD, 255);             //ブレンドモードを加算(255/255)に設定
        DrawGraph(300, 200, bullet01, TRUE); //画像の描画
        DrawGraph(320, 200, bullet01, TRUE); //画像の描画
        DrawGraph(340, 200, bullet01, TRUE); //画像の描画
        DrawGraph(360, 200, bullet01, TRUE); //画像の描画
        DrawGraph(380, 200, bullet01, TRUE); //画像の描画
        DrawGraph(400, 200, bullet01, TRUE); //画像の描画
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);           //ブレンドモードをオフ

        DrawFormatString(x, y, Green, "座標[%d,%d]", x, y); // 文字を描画する

        x = x + 2; // x座標を2加算
        y = y + 1; // y座標を1加算


    }

    DxLib_End(); // DXライブラリ終了処理
    return 0;
}