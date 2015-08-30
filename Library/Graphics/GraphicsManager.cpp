#include "DXUT.h"
#include "GraphicsManager.h"

#include "Shader/Shader.h"
#include "Shader/Lambert/ShaderLambert.h"
#include "Shader/HalfLambert/ShaderHalfLambert.h"
#include "Shader/Phong/ShaderPhong.h"
#include "Shader/Toon/ShaderToon.h"
#include "Texture.h"

namespace KMT {

	IDirect3DDevice9* GraphicsManager::_device;

	LPDIRECT3DSURFACE9 GraphicsManager::_backBufferSurface;

	LPDIRECT3DSURFACE9 GraphicsManager::_backDepthSurface;

	void GraphicsManager::Initialize(IDirect3DDevice9* device)
	{
		// �f�o�C�X�|�C���^�̎擾
		_device = device;

		// �o�b�N�o�b�t�@�̃T�[�t�F�C�X���擾
		_device->GetRenderTarget(0, &_backBufferSurface);
		
		// �[�x�o�b�t�@�̃T�[�t�F�C�X���擾
		_device->GetDepthStencilSurface(&_backDepthSurface);

		//-------------------------------------------------------------
		// �V�F�[�_�[�̏����ǂݍ���

		//* �V�F�[�f�B���O���ݒ� *//
		ShaderNormal::Create();
		//* �����o�[�g�g�U���˃V�F�[�f�B���O *//
		ShaderLambert::Create();
		//* �n�[�t�����o�[�g�V�F�[�_�[ *//
		ShaderHalfLambert::Create();
		//* �t�H���V�F�[�_�[ *//
		ShaderPhong::Create();
		//* �g�D�[���V�F�[�_�[ *//
		ShaderToon::Create();
	}
	
	void GraphicsManager::Destroy()
	{
		// �o�b�N�o�b�t�@�̃T�[�t�F�C�X�����
		SAFE_RELEASE(_backBufferSurface);
		// �[�x�o�b�t�@�̃T�[�t�F�C�X�����
		SAFE_RELEASE(_backDepthSurface);
		// �V�F�[�_�[�̊J��
		Shader::Destroy();
		// �e�N�X�`���̊J��
		CTexture::Destroy();
	}

	void GraphicsManager::ResetRenderTargetToBackBuffer()
	{
		// �X�e���V���o�b�t�@���Z�b�g
		_device->SetDepthStencilSurface(_backDepthSurface);
		// �����_�����O�^�[�Q�b�g���Z�b�g
		_device->SetRenderTarget(0, _backBufferSurface);
		// �T�[�t�F�C�X���N���A
		_device->Clear(0, 
			NULL, 
			D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER,
			D3DCOLOR_ARGB(0, 20, 40, 50),
			1.0f,
			0);
	}

}