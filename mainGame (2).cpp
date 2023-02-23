#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## �ʱ�ȭ ## init()
//=============================================================
HRESULT mainGame::init()
{
	gameNode::init();
	//�̰����� �ʱ�ȭ�� �Ѵ�

	/*������ �޿������� ������ ���鸸 ������ �Ѵ�*/
	//������ ������ ���ΰ��� ������ �ϸ� �ȴ�

	SCENEMANAGER->addScene("intro", new intro);
	SCENEMANAGER->loadScene("intro");
	SCENEMANAGER->addScene("boss", new boss);
	


	/*���߰�*/

	//����� ����

	return S_OK;
}

//=============================================================
//	## ���� ## release()
//=============================================================
void mainGame::release()
{
	gameNode::release();
	//�̹��� Ŭ������ ���������� ����� �� ����
	//�����Ҵ� new�� ����ߴٸ� �̰����� SAFE_DELETE() ����Ѵ�
	//SAFE_DELETE(_intro);
	//SAFE_DELETE(_boss);
}


//=============================================================
//	## ������Ʈ ## update()
//=============================================================
void mainGame::update()
{
	gameNode::update();
	//�̰����� ����, Ű����, ���콺��� ������Ʈ�� �Ѵ�
	//�����ϰ� �̰����� �ڵ��Ѵٰ� �����ϸ� �ȴ�
	
	//���Ŵ��� ������Ʈ
	SCENEMANAGER->update();

	//����Ŵ��� ������Ʈ(�̳�����ָ� ���尡 �����۵�����)
	SOUNDMANAGER->update();

	//_intro->update();
	//_boss->update();
}

//=============================================================
//	## ���� ## render(HDC hdc)
//=============================================================
void mainGame::render()
{
	//��� �� ��Ʈ�� (�̰͵� ������ �׳� �α�)
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
//=============================================================

	//���Ŵ��� ����
	SCENEMANAGER->render();

	//_intro->render();
	//_boss->render();

//=============================================================
	//������� ������ HDC�� �׸��� (�̰͵� ������ �׳� �α�)
	this->getBackBuffer()->render(getHDC());
}