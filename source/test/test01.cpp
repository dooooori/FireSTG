#include "DxLib.h"

#define PI 3.141592654

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    ChangeWindowMode(TRUE);//ウィンドウモードに設定
    DxLib_Init();   // DXライブラリ初期化処理
    SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に設定

    int x = 50;//移動用
    int pl_img;
    pl_img = LoadGraph( "./res/img/pl_test.png"); // 画像を格納

    int bullet01;
    bullet01= LoadGraph("./res/img/bullet01.png"); // 画像を格納

    // while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
        /*
        DrawGraph(x, 100, pl_img, TRUE); //画像の描画
        x = x + 2; // xを2増やす
        
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);		//ブレンドモードをα(128/255)に設定 透明度
        DrawRotaGraph(100, 200, 2.0, PI/4, pl_img, TRUE);//x,y,拡大,角度,画像変数,透過
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをオフ 
        
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);   //ブレンドモードをα(128/255)に設定
        DrawGraph(100, 200, pl_img, TRUE); //画像の描画
        DrawGraph(120, 200, pl_img, TRUE); //画像の描画
        DrawGraph(140, 200, pl_img, TRUE); //画像の描画
        DrawGraph(160, 200, pl_img, TRUE); //画像の描画
        DrawGraph(180, 200, pl_img, TRUE); //画像の描画
        DrawGraph(200, 200, pl_img, TRUE); //画像の描画
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);           //ブレンドモードをオフ
        */

        SetDrawBlendMode(DX_BLENDMODE_ADD, 255);             //ブレンドモードを加算(255/255)に設定
        DrawGraph(300, 200, bullet01, TRUE); //画像の描画
        DrawGraph(320, 200, bullet01, TRUE); //画像の描画
        DrawGraph(340, 200, bullet01, TRUE); //画像の描画
        DrawGraph(360, 200, bullet01, TRUE); //画像の描画
        DrawGraph(380, 200, bullet01, TRUE); //画像の描画
        DrawGraph(400, 200, bullet01, TRUE); //画像の描画
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);           //ブレンドモードをオフ

    }//while内の関数はエラーが起きると0以外を返す

    DxLib_End();    // DXライブラリ終了処理
    return 0;
}