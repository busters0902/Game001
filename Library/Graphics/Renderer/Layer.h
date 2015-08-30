//*********************************************************************
// �I�t�X�N���[�������_�����O�N���X
// Last Update : 2014.2.5
// Yuta Komatsu
//*********************************************************************
#pragma once

#include <memory>
#include <string>
#include <vector>
#include <list>

#include "GraphicBehavior.h"
#include "GraphicalShape/GraphicalPlane.h"
#include "../View/Camera.h"

#include "../../Extension.h"


namespace KMT {

	enum RenderState
	{
		RENDER_BACK2D,
		RENDER_NORMAL,
		RENDER_ALPHA,
		RENDER_FRONT2D,
		RENDER_STATE_MAX
	};

	class Layer;
	typedef std::shared_ptr<Layer> LayerSP;
	typedef std::weak_ptr<Layer> LayerWP;

	class Layer
	{
	public :
		// �J����
		CCameraSP _camera3D;
		CCameraSP _camera2D;
		// �|�����f��
		GPlaneSP _board;

		// �f�X�g���N�^
		~Layer();

		// ����
		static LayerSP Create(size_t width, size_t height);
		// �����_�����O���X�g�̒��g�����ׂĕ`��
		void Render();
		// �����_�����O���X�g�ɃI�u�W�F�N�g��ǉ�����
		// object �ǉ�����I�u�W�F�N�g
		// list �ǂ̃����_�����O���X�g�ɒǉ����邩
		inline void Add(GraphicBehaviorWP object, RenderState list) 
		{
			_renderLists[list]->push_back(object);
		}

	private :
		// �����_�����O���X�g(�`�惊�X�g�̃n�b�V���}�b�v)
		std::vector<std::list<GraphicBehaviorWP>*> _renderLists;
		// �����_�����O�Ώۂ̃e�N�X�`��
		CTextureSP _texture;
		// ��L�����_�����O�Ώۂ̃e�N�X�`���̃T�[�t�F�C�X
		LPDIRECT3DSURFACE9 _textureSurface;
		// �����_�����O�Ώۂ̃e�N�X�`���p�[�x�o�b�t�@
		LPDIRECT3DSURFACE9 _depthSurface;

		// �R���X�g���N�^
		Layer();

	};

} 