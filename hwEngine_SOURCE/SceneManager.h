#pragma once
#include <map>
#include "Scene.h" 
namespace hw
{
	class SceneManager
	{
	public:
		static void CreateScene(LPCSTR name)
		{
			Scene* scence = new Scene();
			mScenes.insert({name, scence});
		}
		
		static Scene* LoadScene(LPCSTR name)
		{
			std::map<LPCSTR, Scene*>::iterator iter = mScenes.find(name);

			if (iter == mScenes.end())
			{
				return nullptr;
			}

			if (mNowScene)
			{
				mNowScene->Release();
			}

			mNowScene = iter->second;

			return mNowScene;
		}

		static void Initailize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		static std::map<LPCSTR, Scene*> mScenes;
		static Scene* mNowScene;
	};
}