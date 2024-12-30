#include "Scene.h"
#include "Scene.h"

namespace hw
{
	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		LoopObjects<IInitialize*>(mInitiallizes, [](IInitialize*& object) {
			object->Initialize();
		});
	}

	void Scene::Update()
	{
		LoopObjects<IUpdate*>(mUpdates, [](IUpdate*& object) {
			object->Update();
		});
	}

	void Scene::LateUpdate()
	{
		LoopObjects<ILateUpdate*>(mLateUpdates, [](ILateUpdate*& object) {
			object->LateUpdate();
		});
	}

	void Scene::Render(HDC hdc)
	{
		LoopObjects<IRender*>(mRenders, [hdc](IRender*& object) {
			object->Render(hdc);
		});
	}

	void Scene::Release()
	{
		LoopObjects<IRelease*>(mReleases, [](IRelease*& object) {
			object->Release();
		});
	}
}
