#include "Scene.h"

int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	SetMainWindowText("ŽOŠpŠÖ”ƒƒ‚");
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(WIND_W, WIND_H, GRAPHSIZE);
	SetFontSize(FONTSIZE);
	if (DxLib_Init() == -1)
	{
		return -1;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) == -1)
	{
		return -1;
	}
	Keyboard* key = new Keyboard();
	Scene* sc = new Scene();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_END) == 0)
	{
		ClearDrawScreen();
		key->KeyUpdate();
		sc->Update();
		sc->Draw();
		ScreenFlip();
	}
	Release(sc);
	Release(key);
	DxLib_End();

	return 0;
}