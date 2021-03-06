#MIT License
#
#Copyright (c) 2016 MTA SZTAKI
#
#Permission is hereby granted, free of charge, to any person obtaining a copy
#of this software and associated documentation files (the "Software"), to deal
#in the Software without restriction, including without limitation the rights
#to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#copies of the Software, and to permit persons to whom the Software is
#furnished to do so, subject to the following conditions:
#
#The above copyright notice and this permission notice shall be included in all
#copies or substantial portions of the Software.
#
#THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#SOFTWARE.

# Add all header and cpp files in the directory to the project
set (HEADERS
	ApeTextGeometryImpl.h
	ApeLightImpl.h
	ApeNodeImpl.h
	ApeCameraImpl.h
	ApeSceneImpl.h
	ApeFileGeometryImpl.h
	ApePlaneGeometryImpl.h
	ApeBoxGeometryImpl.h
	ApeIndexedFaceSetGeometryImpl.h
	ApeIndexedLineSetGeometryImpl.h
	ApeCylinderGeometryImpl.h
	ApeConeGeometryImpl.h
	ApeTorusGeometryImpl.h
	ApeTubeGeometryImpl.h
	ApeSphereGeometryImpl.h
	ApeFileMaterialImpl.h
	ApePbsPassImpl.h
	ApeManualPassImpl.h
	ApeManualMaterialImpl.h
	ApeManualTextureImpl.h
	session/ApeReplica.h
	session/ApeSceneSessionImpl.h
	session/ApeReplicaManagerConnection.h
	session/ApeReplicaManager.h
	session/ApeLobbyManager.h
	session/ApeHttpManager.h
	)

set (SOURCES 
	ApeTextGeometryImpl.cpp
	ApeLightImpl.cpp
	ApeNodeImpl.cpp
	ApeCameraImpl.cpp
	ApeSceneImpl.cpp
	ApeFileGeometryImpl.cpp
	ApePlaneGeometryImpl.cpp
	ApeBoxGeometryImpl.cpp
	ApeIndexedFaceSetGeometryImpl.cpp
	ApeIndexedLineSetGeometryImpl.cpp
	ApeCylinderGeometryImpl.cpp
	ApeConeGeometryImpl.cpp
	ApeTorusGeometryImpl.cpp
	ApeTubeGeometryImpl.cpp
	ApeSphereGeometryImpl.cpp
	ApeFileMaterialImpl.cpp
	ApePbsPassImpl.cpp
	ApeManualPassImpl.cpp
	ApeManualMaterialImpl.cpp
	ApeManualTextureImpl.cpp
	session/ApeReplica.cpp
	session/ApeSceneSessionImpl.cpp
	session/ApeReplicaManagerConnection.cpp
	session/ApeReplicaManager.cpp
	session/ApeLobbyManager.cpp
	session/ApeHttpManager.cpp
	)
	
include_directories(
	${PROJECT_SOURCE_DIR}/core/scene
	${PROJECT_SOURCE_DIR}/core/scene/session
	${PROJECT_SOURCE_DIR}/core/eventManager
	${RAKNET_INCLUDE_DIR}
	${CURL_INCLUDE_DIR}
	${RAPIDJSON_INCLUDE_DIR}
	)

# Add the dinamic library target to the project
add_library (ApeScene SHARED ${SOURCES} ${HEADERS})

# Link with dependency libraries
if(WIN32)
	target_link_libraries (ApeScene ApeSystemConfig ApeEventManager RAKNET MY_CURL ws2_32)
endif()

# Add preprocessor definitions
set_property (TARGET ApeScene PROPERTY COMPILE_DEFINITIONS BUILDING_APE_SCENE_DLL)

# Place target xxx into the specified folder in IDEs supporting it
set_property (TARGET ApeScene PROPERTY FOLDER "Core")
