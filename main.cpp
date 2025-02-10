#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include"math.h"

const char kWindowTitle[] = "GC1A_11_フクシマ_タケル_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player();

	Enemy* enemy = new Enemy(100, 100, 5, 0,true);
	
	enum Scene {
		SCENE1,//タイトル
		SCENE2,//ゲーム画面
	};
	int scene = SCENE1;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		switch (scene){
		case SCENE1:
			//タイトル
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				
				scene = SCENE2;
			}

			break;

		case SCENE2:
			//ゲーム画面

			player->Update(keys, preKeys);

			enemy->Update();

			float radiusEP = enemy->Getradius() + player->Getradius();
			float distEPX = static_cast<float>(enemy->GetposX()) - player->GetposX();
			float distEPY = static_cast<int>(enemy->GetposY()) - player->GetposY();
			if (radiusEP >= sqrtf(static_cast<float>(pow(distEPX, 2) + pow(distEPY, 2)))) {
				enemy->SetisAlive(false);
			}

			float radiusEB = enemy->Getradius() + player->bullet->radius_;
			float distEBX = static_cast<float>(enemy->GetposX()) - player->bullet->posX_;
			float distEBY = static_cast<int>(enemy->GetposY()) - player->bullet->posY_;
			if (radiusEB >= sqrtf(static_cast<float>(pow(distEBX, 2) + pow(distEBY, 2))) && player->bullet->isShoot_) {
				enemy->SetisAlive(false);
			}

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = SCENE1;
				//初期化
				enemy->Initialize();
				player->initialize();
				
			}
			
			break;
		
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (scene){
		case SCENE1:
			Novice::ScreenPrintf(0, 0, "Title");
			Novice::ScreenPrintf(0, 20, "Enter key to Play screen");
			break;
		case SCENE2:
			Novice::ScreenPrintf(0, 0, "Play scene");
			Novice::ScreenPrintf(0, 20, "Enter key to Title");
			player->Draw();

			enemy->Draw();
			break;
		default:
			break;
		}
		
		


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
