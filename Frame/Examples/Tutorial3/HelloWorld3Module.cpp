/*
* This source file is part of ArkGameFrame
* For the latest info, see https://github.com/ArkGame
*
* Copyright (c) 2013-2017 ArkGame authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#include "HelloWorld3Module.h"
#include "SDK/Proto/NFProtocolDefine.hpp"
#include "SDK/Base/AFTime.hpp"

bool HelloWorld3Module::Init()
{
    //初始化
    std::cout << "Hello, world3, Init" << std::endl;

    return true;
}

int HelloWorld3Module::OnEvent(const AFGUID& self, const int event, const AFIDataList& arg)
{
    //事件回调函数
    std::cout << "OnEvent EventID: " << event << " self: " << self.n64Value << " argList: " << arg.String(0) << " " << " " << arg.Int(1) << std::endl;

    m_pKernelModule->SetPropertyString(self, "Hello", arg.String(0));
    m_pKernelModule->SetPropertyInt(self, "World", arg.Int(1));

    return 0;
}

int HelloWorld3Module::OnHeartBeat(const AFGUID& self, const std::string& strHeartBeat, const float fTime, const int nCount)
{
    int64_t unNowTime = AFCTimeBase::GetInstance().GetNowMillisecond();
    std::cout << "strHeartBeat: " << fTime << " Count: " << nCount << "  TimeDis: " << unNowTime - mLastTime << std::endl;

    mLastTime = unNowTime;

    return 0;
}

int HelloWorld3Module::OnClassCallBackEvent(const AFGUID& self, const std::string& strClassName, const CLASS_OBJECT_EVENT event, const AFIDataList& arg)
{
    //虚拟类事件，只要有此虚拟类创建或者销毁即会回调
    std::cout << "OnClassCallBackEvent ClassName: " << strClassName << " ID: " << self.n64Value << " Event: " << event << std::endl;

    if(event == COE_CREATE_HASDATA)
    {
        m_pKernelModule->AddEventCallBack(self, 11111111, this, &HelloWorld3Module::OnEvent);

        m_pKernelModule->AddHeartBeat(self, "OnHeartBeat", this, &HelloWorld3Module::OnHeartBeat, 1000.0f, 1, true);

        mLastTime = GetSystemTime();
    }

    return 0;
}

int HelloWorld3Module::OnPropertyCallBackEvent(const AFGUID& self, const std::string& strProperty, const AFIData& oldVar, const AFIData& newVar)
{
    //属性回调事件，只要属性值内容有变化，就会被回调
    std::cout << "OnPropertyCallBackEvent Property: " << strProperty << " OldValue: " << oldVar.GetInt() << " NewValue: " << newVar.GetInt() << std::endl;

    return 0;
}

int HelloWorld3Module::OnPropertyStrCallBackEvent(const AFGUID& self, const std::string& strProperty, const AFIData& oldVar, const AFIData& newVar)
{
    //属性回调事件，只要属性值内容有变化，就会被回调
    std::cout << "OnPropertyCallBackEvent Property: " << strProperty << " OldValue: " << oldVar.GetString() << " NewValue: " << newVar.GetString() << std::endl;

    return 0;
}

bool HelloWorld3Module::AfterInit()
{
    //初始化完毕
    std::cout << "Hello, world3, AfterInit" << std::endl;

    m_pKernelModule = pPluginManager->FindModule<AFIKernelModule>();
    m_pElementModule = pPluginManager->FindModule<AFIElementModule>();

    //创建容器，所有的对象均需在容器中
    m_pKernelModule->CreateScene(1);

    m_pKernelModule->AddClassCallBack(NFrame::Player::ThisName(), this, &HelloWorld3Module::OnClassCallBackEvent);

    //创建对象，挂类回调和属性回调,然后事件处理对象
    ARK_SHARE_PTR<AFIObject> pObject = m_pKernelModule->CreateObject(AFGUID(0, 10), 1, 0, NFrame::Player::ThisName(), "", AFCDataList());
    if(nullptr == pObject)
    {
        return false;
    }

    AFCData xData;
    pObject->GetPropertyManager()->AddProperty("Hello", AFCData(DT_STRING, ""), 0);
    pObject->GetPropertyManager()->AddProperty("World", AFCData(DT_INT, 1), 0);

    pObject->AddPropertyCallBack("Hello", this, &HelloWorld3Module::OnPropertyStrCallBackEvent);
    pObject->AddPropertyCallBack("World", this, &HelloWorld3Module::OnPropertyCallBackEvent);

    pObject->SetPropertyString("Hello", "hello,World");
    pObject->SetPropertyInt("World", 1111);

    m_pKernelModule->DoEvent(pObject->Self(), 11111111, AFCDataList() << "hello2" << int(200));

    return true;
}

bool HelloWorld3Module::Execute()
{
    //每帧执行
    //std::cout << "Hello, world3, Execute" << std::endl;

    return true;
}

bool HelloWorld3Module::BeforeShut()
{
    //反初始化之前
    std::cout << "Hello, world3, BeforeShut" << std::endl;

    m_pKernelModule->DestroyAll();

    return true;
}

bool HelloWorld3Module::Shut()
{
    //反初始化
    std::cout << "Hello, world3, Shut" << std::endl;

    return true;
}