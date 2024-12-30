#pragma once
#include "CommonInclude.h"
#include "GameObject.h"
#include "IInitialize.h"
#include "IUpdate.h"
#include "ILateUpdate.h"
#include "IRender.h"
#include "IRelease.h"
#include <vector>

namespace hw
{
	class Scene : public IInitialize
				, public IUpdate
				, public ILateUpdate
				, public IRender
				, public IRelease
	{
	public:
		Scene();
		~Scene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void Release() override;
		
		template<typename T, typename Func>
		void LoopObjects(std::vector<T>& objects, Func func)
		{
			for (auto& object : objects)
			{
				func(object);
			}
		}

		template<typename T>
		void RegisterGameObject(T* gameObject)
		{
			if constexpr (std::is_base_of_v<IInitialize, T>)
			{
				mInitiallizes.push_back(static_cast<IInitialize*>(gameObject));
			}

			if constexpr (std::is_base_of_v<IUpdate, T>)
			{
				mUpdates.push_back(static_cast<IUpdate*>(gameObject));
			}

			if constexpr (std::is_base_of_v<ILateUpdate, T>)
			{
				mLateUpdates.push_back(static_cast<ILateUpdate*>(gameObject));
			}

			if constexpr (std::is_base_of_v<IRender, T>)
			{
				mRenders.push_back(static_cast<IRender*>(gameObject));
			}

			if constexpr (std::is_base_of_v<IRelease, T>)
			{
				mReleases.push_back(static_cast<IRelease*>(gameObject));
			}
		}

	private:
		std::vector<IInitialize*> mInitiallizes;
		std::vector<IUpdate*> mUpdates;
		std::vector<ILateUpdate*> mLateUpdates;
		std::vector<IRender*> mRenders;
		std::vector<IRelease*> mReleases;
	};
}