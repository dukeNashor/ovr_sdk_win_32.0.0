/************************************************************************************

Filename    :   Render_XmlSceneLoader.h
Content     :   Imports and exports XML files
Created     :   January 21, 2013
Authors     :   Robotic Arm Software - Peter Hoff, Dan Goodman, Bryan Croteau

Copyright   :   Copyright (c) Facebook Technologies, LLC and its affiliates. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

************************************************************************************/

#ifndef OVR_Render_XmlSceneLoader_h
#define OVR_Render_XmlSceneLoader_h

#include "Render_Device.h"

using namespace OVR;
using namespace OVR::Render;

#include "TinyXml/tinyxml2.h"

namespace OVR { namespace Render {

using namespace tinyxml2;

class XmlHandler
{
public:
    XmlHandler();
    ~XmlHandler();

    bool ReadFile(const char* fileName, OVR::Render::RenderDevice* pRender,
                  OVR::Render::Scene* pScene,
                  std::vector<Ptr<CollisionModel> >* pCollisions,
                  std::vector<Ptr<CollisionModel> >* pGroundCollisions,
                  bool srgbAware = false,
                  bool anisotropic = false,
                  OVR::Render::BuiltinGeometryShaders geomShader = GShader_Disabled,
                  bool heavyAluAndEarlyZ = false);

protected:
    void ParseVectorString(const char* str, std::vector<OVR::Vector3f> *array,
                       bool is2element = false);

private:
    tinyxml2::XMLDocument*     pXmlDocument;
    char                       filePath[250];
    int                        textureCount;
    std::vector<Ptr<Texture> > Textures;
    int                        modelCount;
    std::vector<Ptr<Model> >   Models;
    int                        collisionModelCount;
    int                        groundCollisionModelCount;
};

}} // OVR::Render

#ifdef OVR_DEFINE_NEW
#define new OVR_DEFINE_NEW
#endif

#endif // OVR_Render_XmlSceneLoader_h
