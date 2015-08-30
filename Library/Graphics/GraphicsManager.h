#pragma once

namespace KMT {

	class GraphicsManager
	{
	private :
		
		// �R���X�g���N�^
		GraphicsManager() {}

		// �f�X�g���N�^
		~GraphicsManager() {}
	public :
		
		// �摜�����ɕK�v�ȃf�o�C�X�̃|�C���^
		static IDirect3DDevice9* _device ;

		// �o�b�N�u�b�t�@�̃T�[�t�F�C�X
		static LPDIRECT3DSURFACE9 _backBufferSurface ;

		// �o�b�N�o�b�t�@�̐[�x�o�b�t�@�̃T�[�t�F�C�X
		static LPDIRECT3DSURFACE9 _backDepthSurface ;

		// ������
		static void Initialize( IDirect3DDevice9* device ) ;

		// ���
		static void Destroy() ;

		static void ResetRenderTargetToBackBuffer() ;
	} ;

}