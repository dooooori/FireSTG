#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// �c�w���C�u����������
	if (DxLib_Init() == -1) return -1;


	// ��ʂɊG��\��
	LoadGraphScreen(0, 0, "./res/img/I_love_CQT.png", FALSE);//�摜�\��

	// �L�[�̓��͑҂�
	WaitKey();


	// �c�w���C�u�����g�p�̏I��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}