#pragma once

class CDevice;

class CEngineCore
{
public:
	CEngineCore();
	~CEngineCore();

	int Init();
	void Tick();

private:
	unique_ptr<CDevice> m_Device;

};

