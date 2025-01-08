#pragma once

// ==================== 라이브러리 ====================
// DirectX ToolKit
#ifdef _DEBUG
#pragma comment(lib, "DirectXTK\\DirectXTK_d.lib")
#else
#pragma comment(lib, "DirectXTK\\DirectXTK.lib")
#endif

// Window TitleBar
#pragma comment(lib, "dwmapi.lib")

// ====================== Window ======================
#include <Windows.h>
#include <dwmapi.h>

// ================== 표준 라이브러리 ==================

// Smart Pointer
#include <memory>

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;

using std::make_unique;
using std::make_shared;

// 자료 구조
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>
#include <stack>

using std::hash;
using std::list;
using std::make_pair;
using std::map;
using std::tuple;
using std::vector;

using std::string;
using std::wstring;

// ===================== Direct X =====================

// SimpleMath
#include <DirectXTK/SimpleMath.h>
using namespace DirectX::SimpleMath;

typedef Vector2 Vec2;
typedef Vector3 Vec3;
typedef Vector4 Vec4;
typedef Quaternion Quat;


// ===================== 엔진 헤더 참조 =====================
#include "EngineGlobals.h"