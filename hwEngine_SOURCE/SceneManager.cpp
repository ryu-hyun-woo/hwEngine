#include "SceneManager.h"
#include "SceneManager.h"
#include "SceneManager.h"

namespace hw
{
	std::map<LPCSTR, Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mNowScene = nullptr;

	void SceneManager::Initailize()
	{
		mNowScene->Initialize();
	}
	void SceneManager::Update()
	{
		mNowScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		mNowScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		mNowScene->Render(hdc);
	}
}