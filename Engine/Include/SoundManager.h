#pragma once

PUN_BEGIN

class PUN_DLL CSoundManager
{
	//�ܹ� Sound Effect
	//���� Sound EffectInstance

public:
	bool Init();
	void Update();
	void AllStop();
	void Restart();

	void CreateSoundEffect(const string& KeyName, const wstring& FileName, const string& PathKey = SOUND_PATH);
	void SoundPlay(const string& KeyName, SOUND_TYPE type, const Vector3& EmitterPos = Vector3::Zero);

	shared_ptr<SoundEffect> const& FindSoundEffect(const string& KeyName);
	shared_ptr<SoundEffectInstance> const& FindSoundEffectInstance(const string& KeyName);

private:
	void CreateBGMList(const string& KeyName, unique_ptr<SoundEffectInstance> instance);
	void RemoveBGMList(const string& KeyName);

private:
	unique_ptr<AudioEngine> m_AudioEngine;
	unordered_map<string, shared_ptr<SoundEffect>> m_SoundEffectMap;
	unordered_map<string, shared_ptr<SoundEffectInstance>> m_SoundEffectInstanceMap;

	AudioListener m_Listener;
	AudioEmitter m_Emitter;
	SOUND_TYPE m_State;

	static shared_ptr<SoundEffect> m_NULLPTR1;
	static shared_ptr<SoundEffectInstance> m_NULLPTR2;

private:
	CLASS_IN_SINGLE(CSoundManager)
};

PUN_END