#include <iostream>
#include "ApeSampleScenePlugin.h"

ApeSampleScenePlugin::ApeSampleScenePlugin()
{
	mpEventManager = Ape::IEventManager::getSingletonPtr();
	mpEventManager->connectEvent(Ape::Event::Group::NODE, std::bind(&ApeSampleScenePlugin::nodeEventCallBack, this, std::placeholders::_1));
	mpScene = Ape::IScene::getSingletonPtr();
}

ApeSampleScenePlugin::~ApeSampleScenePlugin()
{
	std::cout << "ApeSampleScenePlugin dtor" << std::endl;
}

void ApeSampleScenePlugin::nodeEventCallBack(const Ape::Event& event)
{
	//std::cout  << "event called on the " << event.subjectName << " node" << std::endl;
}

void ApeSampleScenePlugin::Init()
{
	std::cout << "ApeSampleScenePlugin::init" << std::endl;
	mPlanetNode = mpScene->createNode("planetNode");
	if (auto planetNode = mPlanetNode.lock())
	{
		if (auto sceneProperty = mpScene->getProperty().lock())
		{
			sceneProperty->setAmbientColor(Ape::Color(0.3f, 0.3f, 0.3f, 1.0f));
			if (auto universeSkyBoxMaterial = std::static_pointer_cast<Ape::IFileMaterial>(mpScene->createEntity("universe", "", Ape::Entity::MATERIAL_FILE).lock()))
			{
				universeSkyBoxMaterial->setFileName("universe.material");
				sceneProperty->setSkyBoxMaterialName(universeSkyBoxMaterial->getName());
			}
		}
		if (auto planetMeshFile = std::static_pointer_cast<Ape::IFileGeometry>(mpScene->createEntity("planet.mesh", planetNode->getName(), Ape::Entity::GEOMETRY_FILE).lock()))
			planetMeshFile->setFileName("planet.mesh");
		if (auto helloWorldText = std::static_pointer_cast<Ape::ITextGeometry>(mpScene->createEntity("helloWorldText", planetNode->getName(), Ape::Entity::GEOMETRY_TEXT).lock()))
		{
			helloWorldText->setOffset(Ape::Vector3(0.0f, 10.0f, 0.0f));
			helloWorldText->setCaption("helloWorld");
		}
	}
}

void ApeSampleScenePlugin::Run()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		if (auto planetNode = mPlanetNode.lock())
			planetNode->rotate(0.0017f, Ape::Vector3(0, 1, 0), Ape::Node::TransformationSpace::LOCAL);
	}
	mpEventManager->disconnectEvent(Ape::Event::Group::NODE, std::bind(&ApeSampleScenePlugin::nodeEventCallBack, this, std::placeholders::_1));
}

void ApeSampleScenePlugin::Step()
{

}

void ApeSampleScenePlugin::Stop()
{

}

void ApeSampleScenePlugin::Suspend()
{

}

void ApeSampleScenePlugin::Restart()
{

}