#include "DxLib.h"
#include "globals.h"
#include "input.h"
//#include "Vector2D.h"
#include "Player.h"
#include "Enemy.h"
#include "NewPlayer.h"

//ファイルの中だけで使えるグローバル変数
namespace
{
	const int BGCOLOR[3] = {255, 250, 205}; // 背景色{ 255, 250, 205 }; // 背景色
	int crrTime;
	int prevTime;
	float atTime;//フレーム間時間表示用の変数
	//Vector2D a(5, 0);
	//Vector2D b(50, 0);
	//Player player("Hero", Vector2D(50, 250), Vector2D(1.0f, 0), 1.0f );
	NewPlayer nPlayer("NewHero", Vector2D(50, 250), Vector2D(1.0f, 0), 1.0f);
	Enemy enemy("Monster", Vector2D(300, 250), Vector2D(-5.0f, 0), 1.0f);

	bool isHitChars = false;//当たり判定フラグ
	//当たり判定
	bool IsHit(const Player& p, const Enemy& e) {
		float rDist;//半径と半径の和
		float dist;//中心と中心の距離
		rDist = p.GetRadius() + e.GetRadius();
		Vector2D ppos = p.GetPosition();
		Vector2D epos = e.GetPosition();
		dist = sqrt((ppos.x - epos.x) * (ppos.x - epos.x) +
			              (ppos.y - epos.y) * (ppos.y - epos.y));
		if (rDist >= dist)
			return true;
		else
			return false;
	}

}


float gDeltaTime = 0.0f; // フレーム間の時間差

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0],BGCOLOR[1],BGCOLOR[2]);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}
	
	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{
	DrawFormatString(100, 100, GetColor(0, 0, 0), "ウィンドウのテスト");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);
}

//ゲーム内容の初期化
void Initialize()
{
	atTime = 0.0f;
}

//ゲーム内容の更新
void Update()
{
	atTime = gDeltaTime; //フレーム間時間
	//player.Update();
	nPlayer.Update();
	enemy.Update();

	//isHitChars = IsHit(player, enemy);
	//if (isHitChars)
	//{
	//	Vector2D pSP = player.GetSpeed();
	//	Vector2D eSP = enemy.GetSpeed();
	//	pSP.x = -pSP.x;//x方向の速度を反転
	//	eSP.x = -eSP.x;//x方向の速度を反転
	//	player.SetSpeed(pSP);
	//	enemy.SetSpeed(eSP);
	//	player.Update();
	//	enemy.Update();
	//}
}

//ゲーム内容の描画
void Draw()
{
	//atTimeを表示
	DrawFormatString(100, 50, GetColor(0, 0, 0), "%8.3lf", atTime);

	//string->char []  .c_str() を使う
	string pName = nPlayer.GetName();
	Vector2D pPos = nPlayer.GetPosition();
	DrawFormatString(100, 80, GetColor(50, 0, 255), "%-8s (%5.2lf, %5.2lf)",
								pName.c_str(), pPos.x, pPos.y);
	if (nPlayer.GetIsSayHello() == true)
	{
		DrawFormatString(400, 80, GetColor(0, 0, 0), "Hello!");
	}

	string eName = enemy.GetName();
	Vector2D ePos = enemy.GetPosition();
	DrawFormatString(100, 110, GetColor(255, 0, 50), "%-8s (%5.2lf, %5.2lf)",
								eName.c_str(), ePos.x, ePos.y);
	DrawFormatString(400, 110, GetColor(0, 0, 0), "%5.2lf", enemy.GetSpeed().x);

	nPlayer.Draw();
	enemy.Draw();
	if (isHitChars == true)
		DrawFormatString(100, 130, GetColor(255, 0, 0), "Hit!");

}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();

	Initialize();

	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate(); // キー入力の状態を更新

		crrTime = GetNowCount(); // 現在の時間を取得
		// 前回の時間との差分を計算
		float deltaTime = (crrTime - prevTime) / 1000.0f; // 秒単位に変換
		gDeltaTime = deltaTime; // グローバル変数に保存

		//ここにやりたい処理を書く
		Update();

		Draw();

		ScreenFlip();
		WaitTimer(16);

		prevTime = crrTime; // 現在の時間を前回の時間として保存

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}