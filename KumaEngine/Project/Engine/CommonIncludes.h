#pragma once

// ==================== ���̺귯�� ====================
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

// ================== ǥ�� ���̺귯�� ==================

// Smart Pointer
#include <memory>

using std::shared_ptr;
using std::unique_ptr;
using std::weak_ptr;

using std::make_unique;
using std::make_shared;

// �ڷ� ����
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


// ===================== ���� ��� ���� =====================
#include "EngineGlobals.h"