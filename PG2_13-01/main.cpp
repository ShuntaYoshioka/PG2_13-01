#include <Novice.h>
#include "Enemy.h"
#include "Player.h"

const char kWindowTitle[] = "Ltest";

Enemy enemy1;

Enemy enemy2;
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	enemy1.posX_ = 100;
	enemy1.posY_ = 100;

	enemy2.posX_ = 200;
	enemy2.posY_ = 100;

	Player player;

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
		player.Update(keys);

		enemy1.Update();
		enemy2.Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player.Draw();
		enemy1.Draw();
		enemy2.Draw();

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
