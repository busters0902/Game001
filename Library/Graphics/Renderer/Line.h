#pragma once

#include <memory>
#include "GraphicBehavior.h"

namespace KMT {

	// ���C���̒��_���`
	typedef struct LineVertex {
		float _x, _y, _z;
		DWORD _color;

		// �R���X�g���N�^
		LineVertex() { }
		LineVertex(CVector3 v, DWORD color) : _x(v.x), _y(v.y), _z(v.z), _color(color) { }

	}*pLineVertex;

	class Line;
	typedef std::shared_ptr<Line> LineSP;
	typedef std::weak_ptr<Line> LineWP;

	// ���C���`��
	class Line : public GraphicBehavior
	{
	public :
		// �f�X�g���N�^
		~Line() { }
		// ����
		static LineSP Create(const CVector3& positionA, const CVector3& positionB, DWORD color);

		// �`��
		void Render(const CCamera* camera);

	private :
		// ���C���̒��_
		LineVertex _vertices[2];

		// �R���X�g���N�^
		Line() { }

	protected :
	};

}