#pragma once 

#pragma warning( disable:4482 )

#include "GraphicBehavior.h"

#include <vector>
#include <memory>
#include <string>
#include <sstream>

namespace KMT {

	class CCamera;

	class ModelRenderer;
	typedef std::shared_ptr<ModelRenderer> ModelRendererSP, GRendererSP;
	typedef std::weak_ptr<ModelRenderer> ModelRendererWP, GRendererWP;

	typedef class ModelRenderer : public GraphicBehavior
	{
	public :
		// �R���X�g���N�^
		ModelRenderer();
		// �f�X�g���N�^
		virtual ~ModelRenderer(){ _textures.clear(); }
		
		// ����
		static ModelRendererSP CreateFromX(const std::string &path, const ShaderSP &shader);
		// �`��
		virtual void Render(const CCamera* camera);		

	private :		
		// X�t�@�C���Ǎ�
		void LoadFromX(const std::string &path);

	}GRenderer;

}