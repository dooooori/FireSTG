#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// ＤＸライブラリ初期化
	if (DxLib_Init() == -1) return -1;


	// 画面に絵を表示
	LoadGraphScreen(0, 0, "./res/img/I_love_CQT.png", FALSE);//画像表示

	// キーの入力待ち
	WaitKey();


	// ＤＸライブラリ使用の終了
	DxLib_End();

	// ソフトの終了
	return 0;
}